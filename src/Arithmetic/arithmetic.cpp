//
// Created by Vasily Perekhrest on 16.04.2021.
//

#include "arithmetic.hpp"
#include "../Utils/utils.hpp"


mpq_class ArithmeticEncode(const std::string &str) {
    std::map<char, std::pair<mpq_class , mpq_class>> segments;
    std::map<char, int> char_counter = CharCounter(str);
    mpq_class counter;
    mpq_class left, right(1, 1);

    for (const auto &iter : char_counter) {
        mpq_class probability(iter.second, str.size());
        segments.emplace(iter.first, std::make_pair(counter, counter + probability));
        counter = counter + probability;
    }

    for (const auto &it : str) {
        mpq_class new_left = left + (right - left) * segments.find(it)->second.first;
        mpq_class new_right = left + (right - left) * segments.find(it)->second.second;

        right = new_right;
        left = new_left;
    }

    return (left + right) / 2;
}

std::string ArithmeticDecode(const std::map<char, int> &char_counter, const mpq_class & code) {
    std::map<char, std::pair<mpq_class, mpq_class>> segments;
    mpq_class counter, char_code(code);
    std::string decoded_string;
    int size_str = 0;

    for (const auto &it : char_counter) {
        size_str += it.second;
    }

    for (const auto &iter : char_counter) {
        mpq_class probability (iter.second, size_str);
        segments.emplace(iter.first, std::make_pair(counter, counter + probability));
        counter = counter + probability;
    }

    for (int i = 0; i < size_str; i++) {
        for (const auto &it : segments) {
            if (it.second.first <= char_code and char_code < it.second.second) {
                decoded_string.push_back(it.first);
                char_code = (char_code - it.second.first) / (it.second.second - it.second.first);
                break;
            }
        }
    }

    return decoded_string;
}
