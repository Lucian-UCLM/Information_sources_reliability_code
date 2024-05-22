#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <cmath>
#include <limits>
#include <algorithm>

// Edge class definition
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

// Network class definition
class Network {
public:
    void addEdge(double key, int source, int target, double weight, int id) {
        edges[key] = Edge(source, target, weight, id);
    }

    const std::map<double, Edge>& getEdges() const {
        return edges;
    }

    int size() const {
        return nodeCount;
    }

    void readNetwork(const std::string& filename) {
        std::ifstream file(filename);
        if (!file.is_open()) {
            std::cerr << "Error: Unable to open file " << filename << std::endl;
            return;
        }

        std::string line;
        int nodeId = 0;
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            std::string cell;
            int targetId = 0;
            while (std::getline(iss, cell, ',')) {
                double weight = std::stod(cell);
                if (weight != 0) {
                    addEdge(weight, nodeId, targetId, weight, edgeId++);
                }
                ++targetId;
            }
            ++nodeId;
        }
        nodeCount = nodeId;
    }

private:
    std::map<double, Edge> edges;
    int nodeCount = 0;
    int edgeId = 0;
};

// UnionFind class definition
class UnionFind {
public:
    UnionFind(int size) : parent(size), rank(size, 0) {
        for (int i = 0; i < size; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }

private:
    std::vector<int> parent;
    std::vector<int> rank;
};


class MinimumSpanningTreeFinder {
public:
    MinimumSpanningTreeFinder(const Network& network) : network(network) {}

    std::vector<Edge> findMinimumSpanningTree() {
        std::vector<Edge> mst;
        UnionFind uf(network.size());

        // Sort edges by weight
        std::vector<std::pair<double, Edge>> sortedEdges(network.getEdges().begin(), network.getEdges().end());
        std::sort(sortedEdges.begin(), sortedEdges.end());

        for (const auto& pair : sortedEdges) {
            const Edge& edge = pair.second;
            int source = edge.getSource();
            int target = edge.getTarget();

            if (uf.find(source) != uf.find(target)) {
                uf.unite(source, target);
                mst.push_back(edge);
            }
        }

        return mst;
    }

private:
    const Network& network;
};

int main() {
    Network network;

    // Read the network from a CSV file
    network.readNetwork("adjacency_matrix.csv");

    // Find the minimum spanning tree
    MinimumSpanningTreeFinder mstFinder(network);
    std::vector<Edge> mst = mstFinder.findMinimumSpanningTree();

    // Print the edges in the minimum spanning tree
    std::cout << "Edges in the Minimum Spanning Tree:" << std::endl;
    for (const auto& edge : mst) {
        std::cout << "Edge from " << edge.getSource() << " to " << edge.getTarget() 
                  << " with weight " << edge.getWeight() << std::endl;
    }

    return 0;
}
