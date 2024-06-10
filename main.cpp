#include "Network.h"
#include "Network_Processor.h"

int main()
{
    Network network(".\\data\\similarity.csv");
    const auto& edges = network.getEdges();
    Network_Processor Processor(21152, network);
    Processor.MST_finder();
    Processor.MST_GRAPHML_exporter();
    Processor.MST_CSV_exporter();
    return 0;
}