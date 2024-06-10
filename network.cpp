#include "Network.h"

/**
 * @brief Constructs a Network from a file.
 * 
 * Reads edges from a specified file and builds the network.
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
            if (weight > 0) {
                addEdge(row, col, weight, edgeId++);
            }
            col++;
        }
        row++;
    }
    file.close();

    // Sort edges by weight
    std::sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
        return a.getWeight() < b.getWeight();
    });

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
    edges.emplace_back(source, target, weight, id);
}

/**
 * @brief Prints the network to the standard output.
 * 
 * Prints the details of each edge in the network.
 */
void Network::printNetwork() {
    for (const auto& edge : edges) {
        std::cout << "Edge ID: " << edge.getId() << " Source: " << edge.getNode1() 
                  << " Target: " << edge.getNode2() << " Weight: " << edge.getWeight() 
                  << std::endl;
    }
}
