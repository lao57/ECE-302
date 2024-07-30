#include "graph.hpp"

template <typename LabelType>
Graph<LabelType>::Graph() {}

template <typename LabelType> 
int Graph<LabelType>::getNumVertices() const {}

template <typename LabelType> 
int Graph<LabelType>::getNumEdges() const {}
        
template <typename LabelType> 
bool Graph<LabelType>::add(LabelType start, LabelType end) {}   

template <typename LabelType> 
bool Graph<LabelType>::remove(LabelType start, LabelType end) {}

template <typename LabelType> 
void Graph<LabelType>::depthFirstTraversal(LabelType start, void visit(LabelType&)) {}

template <typename LabelType> 
void Graph<LabelType>::breadthFirstTraversal(LabelType start, void visit(LabelType&)) {}