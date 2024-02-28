#ifndef __shortest_paths_decode__
#define __shortest_paths_decode__

#include "graph.hpp"
#include <algorithm>
#include <vector>

inline std::vector<int> decode(const std::vector<hop_t> &DP, int v)
{
    // WRITE YOUR CODE HERE

    // if cannot go from u to v
    if (DP[v].vertex == -1) return {};

    std::vector<int> path{v};
    while(true) {
        auto prev = DP[v].vertex;
        if (prev == v || prev == -1) break;
        v = prev;
        path.push_back(v);
    }
    std::reverse(begin(path), end(path));
    return path;
}

#endif // __shortest_paths_decode__
