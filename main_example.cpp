#include"Network.h"
#include"UF_DS.h"
#include"Edge.h"

void MST_printer(std::vector<Edge> mst, double mstWeight){
    std::cout << "Edges in MST:\n";
    for (const auto& edge : mst) {
        std::cout << edge.getNode1() << " -- " << edge.getNode2() << " == " << edge.getWeight() << '\n';
    }
    std::cout << "Total weight of MST: " << mstWeight << '\n';
}

void kruskalMST(int numVertices, Network network) {
    UF_DS uf(numVertices);
    std::vector<Edge> mst;
    double mstWeight = 0;
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
    MST_printer(mst, mstWeight);
}

int main()
{
    Network network(".\\data\\small_graph.csv");
    kruskalMST(8, network);
    return 0;
}