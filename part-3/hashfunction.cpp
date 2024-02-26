#include <iostream>

uint32_t hash(const std::string& str, const uint32_t m) {
    uint32_t res = 0;
    for (const auto c: str) {
        res = (res * 256 + static_cast<uint32_t>(c)) % m;
    }
    return res;
}


// clang++ -std=c++11 part-3/hashfunction.cpp -o part-3/hashfunction
// ./part-3/hashfunction
int main(int argc, char** argv){
    const uint32_t m = 255;
    std::string key{"ciao"}; //uniform initialization syntax (brace-initialization)
    std::cout << "h(\"" << key << "\") = " << hash(key, m) << '\n';

    std::string key2{"oaic"};
    std::cout << "h(\"" << key2 << "\") = " << hash(key2, m) << '\n';

    return 0;
}