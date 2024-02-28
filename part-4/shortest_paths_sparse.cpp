#include "shortest_paths_sparse.hpp"
#include <priority_queue.hpp>

#include <cmath>

std::vector<hop_t> bellman_ford(const SparseGraph &graph, const int source,
                                bool &has_negative_cycle)
{
    const int V = static_cast<int>(graph.size()); //number of nodes
    assert(0 <= source && source < V);

    auto DP = std::vector<hop_t>(V, {inf, -1}); // D_v and P_v (from source to v)
    DP[source] = {0, -1}; // D_u = 0 and P_u = -1 or u

    // WRITE YOUR CODE HERE
    for (int i = 0; i < V-1; i++) {
        has_negative_cycle = false;
        for (int r = 0; r < V; r++) {
            for (const auto &edge : graph[r]) {
                // path relaxation: source to v versus source to r to v
                auto distance = DP[edge.vertex].weight; // from source to v (edge.vertex) 
                auto alt_distance = DP[r].weight + edge.weight; // from source to r to v
                if (alt_distance < distance) {
                    DP[edge.vertex] = {alt_distance, r};
                    has_negative_cycle = true; //????
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

    // method 1
    DP[source].weight = 0;
    auto queue = std::vector<triplet_t>{};
    auto compare = [](const triplet_t &lhs, const triplet_t &rhs) {
        return lhs.d < rhs.d; 
    }; // lambda function
    priority_enqueue(queue, {0, source, source}, compare);
    while(!queue.empty()) {
        auto v_star = queue[0].v;
        auto d_star = queue[0].d;
        auto r_star = queue[0].r;
        // dequeue {d_star, r_star, v_star}
        priority_dequeue(queue, compare);
        for (const auto &edge : graph[v_star]) {
            auto alt_distance = d_star + edge.weight; // D_v* + w(v*,v)
            auto distance = DP[edge.vertex].weight; // D_v, where v is edge.vertex;
            // D_v* + w(v*,v) < D_v, path relaxation
            // source to v_* to v is shorter than source to v
            if (alt_distance<distance) {
                DP[edge.vertex] = {alt_distance, v_star};
                priority_enqueue(queue, {alt_distance, v_star, edge.vertex}, compare);
            }
        }
    }

    // method 2
    // auto queue = std::vector<triplet_t>{};
    // // auto compare = std::less<triplet_t>{};
    // auto compare = [](const triplet_t &lhs, const triplet_t &rhs) {
    //     return lhs.d < rhs.d; 
    // }; // lambda function

    // priority_enqueue(queue, {0, source, source}, compare);

    // while(!queue.empty()) {
    //     auto v_star = queue[0].v;
    //     auto d_star = queue[0].d;
    //     auto r_star = queue[0].r;

    //     // dequeue {d_star, r_star, v_star}
    //     priority_dequeue(queue, compare);

    //     if (DP[v_star].weight <= d_star) { 
    //         continue;
    //     }
    //     DP[v_star] = {d_star, r_star};

    //     for (const auto &edge : graph[v_star]) {
    //         auto d = d_star + edge.weight;
    //         if (!std::isfinite(d)) {
    //             continue;
    //         }
    //         priority_enqueue(queue, {d, v_star, edge.vertex}, compare);
    //     }
    // }

    return DP;
}
