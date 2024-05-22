#include "Network.h"
#include "UF_DS.h"

void MST_finder (std::string filename) {
    Network network(filename);
    
}


int main() {
    MST_finder(".\\data\\small_graph.csv");
    return 0;
}