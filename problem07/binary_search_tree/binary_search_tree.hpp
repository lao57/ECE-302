
#ifndef _BINARY_SEARCH_TREE_H_
#define _BINARY_SEARCH_TREE_H_

#include <stack>
#include <cstdlib>

template <typename KeyType, typename ItemType>
class BinarySearchTree
{
public:
    BinarySearchTree();
    BinarySearchTree(const BinarySearchTree& tree_to_copy);
    BinarySearchTree& operator=(BinarySearchTree tree_to_copy);
    ~BinarySearchTree();

    void swap(BinarySearchTree& tree_to_swap);
    bool insert(const KeyType& key, const ItemType& item);
    bool isEmpty();
    bool retrieve(const KeyType& key, ItemType& item);
    bool remove(KeyType key);
    void destroy();
    void treeSort(KeyType arr[], int size);

private:
    template <typename K, typename I>
    struct Node {
        I data;
        K key;
        Node<K, I>* left = 0;
        Node<K, I>* right = 0;
    };

    template <typename K, typename I>
    struct stackvar {
        Node<K, I>* node_to_copy;
        Node<K, I>** this_node_address;
    };

    Node<KeyType, ItemType>* root;

     void inorder(Node<KeyType, ItemType>* curr, Node<KeyType, ItemType>*& in,
        Node<KeyType, ItemType>*& parent);

    void search(KeyType key, Node<KeyType, ItemType>*& curr,
        Node<KeyType, ItemType>*& parent);
};

#include "binary_search_tree.tpp"

#endif 
