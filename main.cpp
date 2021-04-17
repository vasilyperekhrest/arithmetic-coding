//
// Created by Vasily Perekhrest on 16.04.2021.
//

#include <iostream>
#include <map>

#include "src/Arithmetic/arithmetic.hpp"
#include "src/Fraction/Fraction.hpp"
#include "src/Utils/utils.hpp"

int main() {
    Fraction code;
    std::string input_string;
    std::cout << "Enter the message: ";
    std::getline(std::cin, input_string);

    std::map<char, int> char_counter = CharCounter(input_string);

    code = ArithmeticEncode(input_string);
    std::cout << "Encoded message: " << code << std::endl;

    std::cout << "Decoded message: " << ArithmeticDecode(char_counter, code) << std::endl;
    return 0;
}