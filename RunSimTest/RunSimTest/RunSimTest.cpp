
#include <iostream>
#include "AMRvehicle.h"
#include "PathPlanning.h"
int main()
{
    AMRvehicle* sd = new AMRvehicle(1, 2, 3, 4, 1);
    sd->printInfo();

    PathPlanning pp(5);
    pp.addEdge(0, 1, 10);
    pp.addEdge(0, 4, 5);
    pp.addEdge(1, 2, 1);
    pp.addEdge(1, 4, 2);
    pp.addEdge(2, 3, 4);
    pp.addEdge(3, 4, 7);
    pp.addEdge(4, 2, 9);

    std::vector<int> distances = pp.dijkstra(0);

    for (int i = 0; i < distances.size(); ++i) {
        std::cout << "Distance from 0 to " << i << " is " << distances[i] << std::endl;
    }
}


