#include "Edge.h"

Edge::Edge(int node1, int node2, double weight, int id){
   this->node1 = node1;
   this->node2 = node2;
   this->weight = weight;
   this->id = id;
}
int Edge::getNode1() const{
   return node1;
}
int Edge::getNode2() const{
   return node2;
}
double Edge::getWeight() const{
   return weight;
}
int Edge::getId() const{
   return id;
}