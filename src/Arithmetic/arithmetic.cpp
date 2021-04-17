//
// Created by Vasily Perekhrest on 16.04.2021.
//

#include "arithmetic.hpp"
#include "../Utils/utils.hpp"

Fraction ArithmeticEncode(const std::string &str) {
    std::map<char, std::pair<Fraction, Fraction>> segments;
    std::map<char, int> char_counter = CharCounter(str);
    Fraction counter;
    Fraction left(0, 1), right(1, 1), code;

    for (const auto &iter : char_counter) {
        Fraction probability (iter.second, str.size());
        segments.emplace(iter.first, std::make_pair(counter, counter + probability));
        counter = counter + probability;
    }

    for (const auto &it : str) {
        Fraction new_left = left + (right - left) * segments.find(it)->second.first;
        Fraction new_right = left + (right - left) * segments.find(it)->second.second;

        right = new_right;
        left = new_left;
    }

    return (left + right) / Fraction(2, 1);
}

std::string ArithmeticDecode(const std::map<char, int> &char_counter, const Fraction& code) {
    std::map<char, std::pair<Fraction, Fraction>> segments;
    Fraction counter, char_code (code);
    std::string decoded_string;
    int size_str = 0;

    for (const auto &it : char_counter) {
        size_str += it.second;
    }
    decoded_string.reserve(size_str);

    for (const auto &iter : char_counter) {
        Fraction probability (iter.second, size_str);
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
