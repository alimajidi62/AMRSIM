#pragma once
#include <vector>

class PathPlanning {
public:
    PathPlanning(int vertices);
    void addEdge(int u, int v, int weight);
    std::vector<int> dijkstra(int src);

private:
    int vertices;
    std::vector<std::vector<std::pair<int, int>>> adjList;
};
