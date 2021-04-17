//
// Created by Vasily Perekhrest on 16.04.2021.
//

#ifndef ARITHMETIC_CODING_ARITHMETIC_HPP
#define ARITHMETIC_CODING_ARITHMETIC_HPP

#include "../Fraction/Fraction.hpp"
#include <map>

Fraction ArithmeticEncode(const std::string &str);
std::string ArithmeticDecode(const std::map<char, int> &char_counter, const Fraction& code);

#endif //ARITHMETIC_CODING_ARITHMETIC_HPP
