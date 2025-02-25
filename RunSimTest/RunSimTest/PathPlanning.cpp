#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include "PathPlanning.h"

PathPlanning::PathPlanning(int vertices) : vertices(vertices) {
    adjList.resize(vertices);
}

void PathPlanning::addEdge(int u, int v, int weight) {
    adjList[u].emplace_back(v, weight);
    adjList[v].emplace_back(u, weight); // If the graph is undirected
}

std::vector<int> PathPlanning::dijkstra(int src) {
    std::vector<int> dist(vertices, std::numeric_limits<int>::max());
    dist[src] = 0;
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> pq;
    pq.emplace(0, src);

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (const auto& neighbor : adjList[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.emplace(dist[v], v);
            }
        }
    }

    return dist;
}