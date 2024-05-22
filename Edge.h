#ifndef EDGE_H
#define EDGE_H
#include <iostream>
#include <string>

class Edge{
private:
   int node1;
   int node2;
   double weight;
   int id;
public:
   Edge()=default;
   Edge(int node1, int node2, double weight, int id);
   int getNode1() const;
   int getNode2() const;
   double getWeight() const;
   int getId() const;
};

#endif