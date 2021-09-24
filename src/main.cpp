// References
//  [Creating a Small-footprint Programming Language in C++ | Toptal](https://www.toptal.com/c-plus-plus/creating-programming-language-in-c-)
// 
#include <cassert>
#include <cstdlib>
#include <iostream>

#include "../include/token.hpp"

int main_vm(int argc, char* argv[]) {
    // [Range-based for loop (since C++11) - cppreference.com](https://en.cppreference.com/w/cpp/language/range-for)
    for (const auto& reserved_token : reserved_instruction_token_map) {
        std::cout << reserved_token.first << std::endl;
    }
    std::cout << "---" << std::endl;
    for (const auto& reserved_token : reserved_memory_segment_token_map) {
        std::cout << reserved_token.first << std::endl;
    }
    return EXIT_SUCCESS;
}