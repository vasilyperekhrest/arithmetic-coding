//
// Created by Vasily Perekhrest on 16.04.2021.
//

#include "utils.hpp"

#include <set>
#include <string>

std::map<char, int> CharCounter(const std::string &str) {
    std::map<char, int> char_counter;
    std::set<char> alpha {str.cbegin(), str.cend()};
    for (const auto& iter : alpha) {
        char_counter.emplace(iter, std::count(str.cbegin(), str.cend(), iter));
    }
    return char_counter;
}
