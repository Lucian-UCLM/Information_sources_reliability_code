#include "Network.h"

/**
 * @brief Constructs a Network from a file.
 * 
 * Reads edges from a specified file and constructs the network.
 * 
 * @param filename The name of the file to read the edges from.
 * Must be a CSV file with ";" as the delimiter.
 */
Network::Network(const std::string& filename) {
    std::ifstream file(filename);
    std::string line;
    int col, edgeId = 0, row = 0;
    double weight;

    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file " << filename << std::endl;
        exit(1);
    }

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        col = 0;
        while (iss) {
            std::string cell;
            if (!std::getline(iss, cell, ';')) {
                break;
            }
            weight = std::stod(cell);
            addEdge(row, col, weight, edgeId++);
            col++;
        }
        row++;
    }
}

/**
 * @brief Adds an edge to the network.
 * 
 * Adds an edge with the specified key, source node, target node, weight, and id.
 * 
 * @param key The key (weight) of the edge.
 * @param source The source node of the edge.
 * @param target The target node of the edge.
 * @param weight The weight of the edge.
 * @param id The unique identifier of the edge.
 */
void Network::addEdge(int source, int target, double weight, int id) {
    edges.insert(std::pair<double, Edge>(weight, Edge(source, target, weight, id)));
}

/**
 * @brief Prints the network to the standard output.
 * 
 * Prints the details of each edge in the network.
 */
void Network::printNetwork() {
    for (auto& edge : edges) {
        std::cout << "Edge ID: " << edge.second.getId() << " Source: " << edge.second.getNode1() 
                  << " Target: " << edge.second.getNode2() << " Weight: " << edge.second.getWeight() 
                  << std::endl;
    }
}

/**
 * @brief Gets the edges of the network.
 * 
 * @return std::multimap<double, Edge> The edges of the network.
 */
std::multimap<double, Edge> Network::getEdges() const {
    return edges;
}
