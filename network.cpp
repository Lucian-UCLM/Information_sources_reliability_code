#include "network.h"

Network::Network(const std::string& filename){
    std::ifstream file(filename);
    std::string line;
    int col, edgeId = 0, row = 0;
    double weight;
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file " << filename << std::endl;
        return;
    }
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        col = 0;
        while(iss){
            std::string cell;
            if(!std::getline(iss, cell, ';')){
                break;
            }
            weight = std::stod(cell);
            addEdge(weight, row, col, weight, edgeId++);
            col++;
        }
        row++;
    }
}
void Network::addEdge(double key, int source, int target, double weight, int id){
    //edges.(key, Edge(source, target, weight, id));
    edges.insert(std::pair<double, Edge>(key, Edge(source, target, weight, id)));
}
void Network::printNetwork(){
    for(auto& edge : edges){
        std::cout << "Edge ID: " << edge.second.getId() << " Source: " << edge.second.getNode1() << " Target: " << edge.second.getNode2() << " Weight: " << edge.second.getWeight() << std::endl;
    }
}
std::multimap<double, Edge> Network::getEdges() const{
    return edges;
}