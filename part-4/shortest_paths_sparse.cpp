#include "shortest_paths_sparse.hpp"
#include <priority_queue.hpp>

#include <cmath>

std::vector<hop_t> bellman_ford(const SparseGraph &graph, const int source,
                                bool &has_negative_cycle)
{
    const int V = static_cast<int>(graph.size()); //number of nodes
    auto DP = std::vector<hop_t>(V, {inf, -1});
    DP[source] = {0, source};

    // WRITE YOUR CODE HERE
    for (int i = 0; i < V-1; i++) {
        for (int u = 0; u < V; u++) {
            for (const auto &edge : graph[u]) {
                // path relaxation: source to v versus source to u to v
                auto distance = DP[edge.vertex].weight; // from source to v (edge.vertex) 
                auto alt_distance = DP[u].weight + edge.weight; // from source to u to v
                if (alt_distance < distance) {
                    DP[edge.vertex] = {alt_distance, u};
                }
            }
        }
    }

    return DP;
}

struct triplet_t {
    float d;
    int r;
    int v;
};

std::vector<hop_t> dijkstra(const SparseGraph &graph, const int source)
{
    assert(source >= 0);
    assert(source < (signed)graph.size());

    auto DP = std::vector<hop_t>(graph.size(), {inf, -1});

    // WRITE YOUR CODE HERE
    auto queue = std::vector<triplet_t>{};
    auto compare = [](const triplet_t &lhs, const triplet_t &rhs) {
        return lhs.d < rhs.d; 
    };
    priority_enqueue(queue, {0, source, source}, compare);

    while(!queue.empty()) {
        
    }

    return DP;
}
