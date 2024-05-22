#include "Edge.h"
#include <fstream>
#include <sstream>
#include <map>

class Network {
private:
    std::multimap<double, Edge> edges;
    int nodeCount = 0;
    int edgeId = 0;
public:
    Network(const std::string& filename);
    void addEdge(double key, int source, int target, double weight, int id);
    void printNetwork();
    std::multimap<double, Edge> getEdges() const;
};