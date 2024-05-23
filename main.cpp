#include "Network.h"
#include "network_processor.h"

int main()
{
    Network network(".\\data\\small_graph.csv");
    MST MST(8, network);
    MST.MST_finder();
    MST.MST_printer();
    return 0;
}