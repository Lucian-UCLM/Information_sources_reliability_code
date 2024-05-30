#include "Network_Processor.h"

/**
 * @brief Constructs an MST object.
 * 
 * Initializes the MST object with a specified size and network.
 * Both parameters must be provided.
 * 
 * @param size The number of nodes in the network.
 * @param network The network for which the MST is to be computed.
 */
Network_Processor::Network_Processor(int size, const Network& network) : network(network) {
    this->size = size;
}
/**
 * @brief Prints the edges in the MST.
 * 
 * Prints the edges included in the MST and the total weight of the MST.
 */
void Network_Processor::MST_printer() {
    std::cout << "Edges in MST:\n";
    for (const auto& edge : mst) {
        std::cout << edge.getNode1() << " <--> " << edge.getNode2() << " == " << edge.getWeight() << '\n';
    }
    std::cout << "Total weight of MST: " << mstWeight << '\n';
}

/**
 * @brief Exports the MST to a CSV file.
 * 
 * Exports the edges in the MST to a CSV file with columns for source, target, weight, and type.
 * This format is suitable for visualization in tools like Gephi.
 */
void Network_Processor::MST_CSV_exporter() {
    std::ofstream outputFile(".\\data\\MST.csv");
    if (!outputFile.is_open()) {
        std::cerr << "Error: Unable to open output file" << std::endl;
        return;
    }
    outputFile << "source;target;weight;type" << std::endl;
    for (const auto& edge : mst) {
        outputFile << edge.getNode1() << ";" << edge.getNode2() << ";" << edge.getWeight() << ";undirected" << std::endl;
    }
    outputFile.close();
}

void Network_Processor::MST_GRAPHML_exporter() {
    std::ofstream outputFile(".\\data\\MST.graphml");
    if (!outputFile.is_open()) {
        std::cerr << "Error: Unable to open output file" << std::endl;
        return;
    }
    
    // Write the GraphML header
    outputFile << R"(<?xml version="1.0" encoding="UTF-8"?>)" << '\n';
    outputFile << R"(<graphml xmlns="http://graphml.graphdrawing.org/xmlns")" << '\n';
    outputFile << R"(    xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance")" << '\n';
    outputFile << R"(    xsi:schemaLocation="http://graphml.graphdrawing.org/xmlns )" << '\n';
    outputFile << R"(     http://graphml.graphdrawing.org/xmlns/1.0/graphml.xsd">)" << '\n';
    outputFile << R"(<graph id="G" edgedefault="undirected">)" << '\n';

    // Write nodes
    std::set<int> nodes;
    for (const auto& edge : mst) {
        nodes.insert(edge.getNode1());
        nodes.insert(edge.getNode2());
    }
    for (const int node : nodes) {
        outputFile << "  <node id=\"" << node << "\" />" << '\n';
    }

    // Write edges
    int edgeId = 0;
    for (const auto& edge : mst) {
        outputFile << "  <edge id=\"e" << edgeId++ << "\" source=\"" 
                   << edge.getNode1() << "\" target=\"" << edge.getNode2() 
                   << "\" weight=\"" << edge.getWeight() << "\" />" << '\n';
    }

    // Write the GraphML footer
    outputFile << "</graph>" << '\n';
    outputFile << "</graphml>" << '\n';
    
    outputFile.close();
}

/**
 * @brief Finds the MST using Kruskal's algorithm.
 * 
 * Computes the MST of the network using Kruskal's algorithm and stores the result.
 */
void Network_Processor::MST_finder() {
    UF_DS uf(size);
    int u, v;

    for (const auto& [weight, edge] : network.getEdges()) {
        u = edge.getNode1();
        v = edge.getNode2();

        if (uf.find(u) != uf.find(v)) {
            uf.unite(u, v);
            mst.push_back(edge);
            mstWeight += weight;
        }
    }
}
