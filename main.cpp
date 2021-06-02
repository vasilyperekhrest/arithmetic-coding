//
// Created by Vasily Perekhrest on 16.04.2021.
//

#include <iostream>
#include <map>

#include <gmpxx.h>

#include "src/Arithmetic/arithmetic.hpp"
#include "src/Utils/utils.hpp"


int main(int argc, char* argv[]) {
    mpq_class code;
    std::string input_string;

    if (argc == 1) {
        std::cout << "Enter the message: ";
        std::getline(std::cin, input_string);
    } else if (argc == 2) {
        input_string = argv[1];

    } else {
        std::cout << "Error!" << std::endl;
        return -1;
    }

    std::map<char, int> char_counter = CharCounter(input_string);

    code = ArithmeticEncode(input_string);
    std::cout << "Encoded message: " << code << std::endl;
    std::cout << "Decoded message: " << ArithmeticDecode(char_counter, code) << std::endl;
    return 0;
}