#ifndef NETWORK_PROCESSOR_H
#define NETWORK_PROCESSOR_H

#include "Network.h"
#include "UF_DS.h"
#include "Edge.h"
#include <fstream>
#include <vector>
#include <set>

/**
 * @class MST
 * @brief Class for computing and managing the Minimum Spanning Tree (MST) of a network.
 * 
 * The MST class provides functionality to find the MST of a given network, print the MST,
 * and export the MST to a CSV file.
 */
class Network_Processor {
public:
    /**
     * @brief Constructs an MST object.
     * 
     * Initializes the MST object with a specified size and network.
     * Both parameters must be provided.
     * 
     * @param size The number of nodes in the network.
     * @param network The network for which the MST is to be computed.
     */
    Network_Processor(int size, const Network& network);

    /**
     * @brief Prints the edges in the MST.
     * 
     * Prints the edges included in the MST and the total weight of the MST.
     */
    void MST_printer();

    /**
     * @brief Exports the MST to a CSV file.
     * 
     * Exports the edges in the MST to a CSV file with columns for source, target, weight, and type.
     * This format is suitable for visualization in tools like Gephi.
     */
    void MST_CSV_exporter();

    /**
     * @brief Exports the MST to a GraphML file.
     * 
     * Exports the edges in the MST to a GraphML file format, suitable for visualization in tools
     * like yEd or Gephi.
     */
    void MST_GRAPHML_exporter();

    /**
     * @brief Finds the MST using Kruskal's algorithm.
     * 
     * Computes the MST of the network using Kruskal's algorithm and stores the result.
     */
    void MST_finder();

private:
    const Network& network; ///< The network for which the MST is computed.
    std::vector<Edge> mst; ///< Vector to store the edges in the MST.
    double mstWeight = 0; ///< Total weight of the MST.
    int size; ///< The number of nodes in the network.
};

#endif
