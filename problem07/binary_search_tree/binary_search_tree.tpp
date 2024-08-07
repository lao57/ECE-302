#include "binary_search_tree.hpp"

template <typename KeyType, typename ItemType>
BinarySearchTree<KeyType, ItemType>::BinarySearchTree()
{
    root = 0;
}

template <typename KeyType, typename ItemType>
BinarySearchTree<KeyType, ItemType>::BinarySearchTree(
    const BinarySearchTree<KeyType, ItemType>& tree_to_copy)
{
    root = 0;
    Node<KeyType, ItemType>** this_tree_root = &root;

    std::stack<stackvar<KeyType, ItemType>> s;

    stackvar<KeyType, ItemType> rootvar;
    rootvar.node_to_copy = tree_to_copy.root;
    rootvar.this_node_address = this_tree_root;
    s.push(rootvar);

    while (!s.empty()) {
        stackvar<KeyType, ItemType> currentvar = s.top();
        s.pop();

        Node<KeyType, ItemType>* curr_node_to_copy = currentvar.node_to_copy;
        Node<KeyType, ItemType>** curr_this_node_address = currentvar.this_node_address;

        if (curr_node_to_copy == 0)
            continue;

        // allocate new node and copy contents
        Node<KeyType, ItemType>* temp = new Node<KeyType, ItemType>;
        temp->key = curr_node_to_copy->key;
        temp->data = curr_node_to_copy->data;
        temp->left = 0;
        temp->right = 0;
        *curr_this_node_address = temp; // assigns value using this node address

        // push left subtree
        stackvar<KeyType, ItemType> left_subtree_root;
        left_subtree_root.node_to_copy = curr_node_to_copy->left;
        left_subtree_root.this_node_address = &((*curr_this_node_address)->left); 
        s.push(left_subtree_root);

        // push right subtree
        stackvar<KeyType, ItemType> right_subtree_root;
        right_subtree_root.node_to_copy = curr_node_to_copy->right;
        right_subtree_root.this_node_address = &((*curr_this_node_address)->right);
        s.push(right_subtree_root);
    }
}


template <typename KeyType, typename ItemType>
BinarySearchTree<KeyType, ItemType>& BinarySearchTree<KeyType, ItemType>::
operator=(BinarySearchTree<KeyType, ItemType> tree_to_copy)
{
    swap(tree_to_copy);
    return *this;
}

template <typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::swap(BinarySearchTree<KeyType, ItemType>& tree_to_swap)
{
    std::swap(root, tree_to_swap.root);
}

template <typename KeyType, typename ItemType>
BinarySearchTree<KeyType, ItemType>::~BinarySearchTree()
{
    destroy();
}


template <typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::destroy()
{
    std::stack<Node<KeyType, ItemType>*> s;
    s.push(root);

    while (!s.empty()) {
        Node<KeyType, ItemType>* curr = s.top();
        s.pop();

        if (curr != 0) {
            s.push(curr->left);
            s.push(curr->right);
            delete curr;
        }
    }
    root = 0;
}

template <typename KeyType, typename ItemType>
bool BinarySearchTree<KeyType, ItemType>::insert(
    const KeyType& key, const ItemType& item)
{
    Node<KeyType, ItemType>* temp = new Node<KeyType, ItemType>;
    temp->data = item;
    temp->key = key;
    if (isEmpty()){
        root = temp;
    }else{
        Node<KeyType, ItemType>* curr;
        Node<KeyType, ItemType>* curr_parent;
        search(key, curr, curr_parent);
        if (key == curr->key){
            delete temp;
            return false;
        }else if(curr->key > key){
            curr->left = temp;
        }else{
            curr->right = temp;
        }
    }
    return true;
}

template <typename KeyType, typename ItemType>
bool BinarySearchTree<KeyType, ItemType>::isEmpty()
{
    return (root == 0);
}

template <typename KeyType, typename ItemType>
bool BinarySearchTree<KeyType, ItemType>::retrieve(
    const KeyType& key, ItemType& item)
{
    Node<KeyType, ItemType>* curr;
    Node<KeyType, ItemType>* curr_parent;
    search(key, curr, curr_parent);

    if (curr == 0)
        return false;

    if (curr->key == key) {
        item = curr->data;
        return true;
    }

    return false;
}

template <typename KeyType, typename ItemType>
bool BinarySearchTree<KeyType, ItemType>::remove(KeyType key)
{
    if (isEmpty())
        return false; // empty tree

    // TODO
    // only one thing in the tree
    if (root->left == 0 && root->right == 0) {
        if (root->key == key) {
            delete root;
            root = 0;
            return true;
        } else {
            return false;
        }
    }
    Node<KeyType, ItemType>* curr;
    Node<KeyType, ItemType>* curr_parent;
    search(key, curr, curr_parent);
    ItemType item;
    
    if (curr->key != key) {
        return false;
    }

    //case found at leaf
    if(curr->left == nullptr && curr->right == nullptr){
        if (curr_parent->left == curr){
            curr_parent->left = nullptr;
            delete curr;
        }else{
            curr_parent->right = nullptr;
            delete curr;
        }
    }


    // // case, item to delete has only a right child
    else if (curr->left == 0) {
        if (curr_parent == 0) {
            root = curr->right;
            delete curr;
        } else if (curr_parent->left == curr) {
            curr_parent->left = curr->right;
            delete curr;
        } else {
            curr_parent->right = curr->right;
            delete curr;
        }
    }

    // // case, item to delete has only a left child
    else if (curr->right == 0) {
        if (curr_parent == 0) {
            root = curr->left;
            delete curr;
        } else if (curr_parent->left == curr) {
            curr_parent->left = curr->left;
            delete curr;
        } else {
            curr_parent->right = curr->left;
            delete curr;
        }
    }
    // // case, item to delete has two children
    else {
        Node<KeyType, ItemType>* in;
        Node<KeyType, ItemType>* in_Parent;
        inorder(curr, in, in_Parent);

        std::swap(curr, in);
        in->data = curr->data;
        in->key = curr->key;

        if (in_Parent->left == curr) {
            delete curr;
            in_Parent->left = 0;
        } else if (in_Parent->right == curr) {
            delete curr;
            in_Parent->right = 0;
        }
    }

    return true; 
}

template <typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::inorder(Node<KeyType, ItemType>* curr,
    Node<KeyType, ItemType>*& in, Node<KeyType, ItemType>*& curr_parent)
{
    // TODO: find inorder successor of "curr" and assign to "in"
    curr_parent = curr;
    in = curr_parent->right;
    
    while (in != 0) {
        if (in->left == 0) {
            return;
        } else {
            curr_parent = in;
            in = in->left;
        }
    }
}

template <typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::search(KeyType key,
    Node<KeyType, ItemType>*& curr, Node<KeyType, ItemType>*& curr_parent)
{
    curr = root;
    curr_parent = 0;

    if (isEmpty())
        return;

    while (true) {
        if (key == curr->key) {
            break;
        } else if (key < curr->key) {
            if (curr->left != 0) {
                curr_parent = curr;
                curr = curr->left;
            } else
                break;
        } else {
            if (curr->right != 0) {
                curr_parent = curr;
                curr = curr->right;
            } else
                break;
        }
    }
}

template<typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::treeSort(KeyType arr[], int size) {
    // TODO: check for duplicate items in the input array

    // TODO: use the tree to sort the array items

    // TODO: overwrite input array values with sorted values

    for (int i=0; i<size; i++) {
        if (insert(arr[i], ItemType()) == false) {
            
            for (int j=i; j<size-1; j++) {
                arr[j] = arr[j+1];
            }
            size--;
            i--;
        }
    }
}
