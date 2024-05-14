#include <map>
#include <string>

class Edge {
public:
    Edge(int source, int target, double weight, int id) 
        : source(source), target(target), weight(weight), id(id) {}

    int getSource() const { return source; }
    int getTarget() const { return target; }
    double getWeight() const { return weight; }
    int getId() const { return id; }

private:
    int source;
    int target;
    double weight;
    int id;
};

class Network {
public:
    void addEdge(double key, int source, int target, double weight, int id) {
        edges[key] = Edge(source, target, weight, id);
    }

    void removeMin() {
        if (!edges.empty()) {
            auto it = edges.begin();
            edges.erase(it);
        }
    }

    void readNetwork(const std::string& filename) {
        std::cout << "Reading network from file: " << filename << std::endl;
    }

private:
    std::map<double, Edge> edges;
};
