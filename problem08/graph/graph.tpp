#include "graph.hpp"

#include "graph.hpp"

template <typename LabelType>
Graph<LabelType>::Graph() {}

template <typename LabelType>
int Graph<LabelType>::getNumVertices() const {
    return adjList.size();
}

template <typename LabelType>
int Graph<LabelType>::getNumEdges() const {
    int edgeCount = 0;
    for (auto i = adjList.begin(); i != adjList.end(); ++i) {
        edgeCount += i->second.size();
    }
    return edgeCount / 2; // because of dupes
}

template <typename LabelType>
bool Graph<LabelType>::add(LabelType start, LabelType end) {
    if (start == end) return false; //loop

    if (adjList.size() != 0){
        bool cont = false;
        for (auto i = adjList.begin(); i != adjList.end(); ++i) {
            if (i->first == start || i->first == end){
                cont = true;
            }
        }
        if (cont == false){
            return false;
        }
    }

    if (adjList[start].count(end) > 0 || adjList[end].count(start) > 0){ //dupe check
        return false;
    }

    adjList[start].insert(end);
    adjList[end].insert(start);

    return true;
}

template <typename LabelType>
bool Graph<LabelType>::remove(LabelType start, LabelType end) {
    if (adjList[start].count(end) == 0 || adjList[end].count(start) == 0){ //DNE
        return false;
    }

    adjList[start].erase(end);
    adjList[end].erase(start);

    if (adjList[start].empty()){ 
        adjList.erase(start);
    }
    if (adjList[end].empty()){ 
        adjList.erase(end);
    }

    return true;
}

template <typename LabelType>
void Graph<LabelType>::depthFirstTraversal(LabelType start, void visit(LabelType&)) {}

template <typename LabelType>
void Graph<LabelType>::breadthFirstTraversal(LabelType start, void visit(LabelType&)) {}