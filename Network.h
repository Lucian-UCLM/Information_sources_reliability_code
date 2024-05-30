#ifndef NETWORK_H
#define NETWORK_H

#include "Edge.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <map>

/**
 * @class Network
 * @brief Represents a network of edges.
 * 
 * The Network class manages a collection of edges, allowing: reading edges from a file,
 * adding edges to the network, printing the network, and retrieving the edges.
 */
class Network {
private:
    std::multimap<double, Edge> edges; ///< Multimap to store edges keyed by weight.
    int nodeCount = 0; ///< Count of nodes in the network.
    int edgeId = 0; ///< Unique identifier for edges.

public:
    /**
     * @brief Constructs a Network from a file.
     * 
     * Reads edges from a specified file and constructs the network.
     * 
     * @param filename The name of the file to read the edges from. 
     * Must be a CSV file with ";" as the delimiter.
     */
    Network(const std::string& filename);

    /**
     * @brief Adds an edge to the network.
     * 
     * Adds an edge with the specified source node, target node, weight, and id.
     * The key of the edge is the weight.
     * 
     * @param source The source node of the edge.
     * @param target The target node of the edge.
     * @param weight The weight of the edge.
     * @param id The unique identifier of the edge.
     */
    void addEdge(int source, int target, double weight, int id);

    /**
     * @brief Prints the network to the standard output.
     * 
     * Prints the details of each edge in the network.
     */
    void printNetwork();

    /**
     * @brief Gets the edges of the network.
     * 
     * @return std::multimap<double, Edge> The edges of the network.
     */
    std::multimap<double, Edge> getEdges() const;
};

#endif
