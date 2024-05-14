#include <vector>
#include <algorithm>

class MinimumSpanningTreeFinder {
public:
    MinimumSpanningTreeFinder(const Network& network) : network(network) {}

    std::vector<Edge> findMinimumSpanningTree() {
        std::vector<Edge> mst;
        UnionFind uf(network.size());

        for (const auto& pair : network.getEdges()) {
            double key = pair.first;
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
