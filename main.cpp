#include "Network.h"
#include "Network_Processor.h"

int main()
{
    Network network(".\\data\\similarity.csv");
    Network_Processor Processor(8, network);
    Processor.MST_finder();
    Processor.MST_GRAPHML_exporter();
    return 0;
}