//
// Created by Vasily Perekhrest on 16.04.2021.
//

#ifndef ARITHMETIC_CODING_FRACTION_HPP
#define ARITHMETIC_CODING_FRACTION_HPP

#include <gmpxx.h>
#include <iostream>

class Fraction {
private:
    mpz_class numerator;
    mpz_class denominator;

public:
    Fraction();
    [[maybe_unused]] Fraction(const mpz_class &_numerator, const mpz_class &_denominator);
    [[maybe_unused]] Fraction(const std::string &_numerator, const std::string &_denominator);
    [[maybe_unused]] Fraction(const Fraction &fraction);

    friend std::ostream& operator << (std::ostream &out, const Fraction &fraction);
    friend Fraction operator+(const Fraction& left, const Fraction& right);
    friend Fraction operator-(const Fraction& left, const Fraction& right);
    friend Fraction operator*(const Fraction& left, const Fraction& right);
    friend Fraction operator/(const Fraction& left, const Fraction& right);
    friend bool operator==(const Fraction& left, const Fraction& right);
    friend bool operator!=(const Fraction& left, const Fraction& right);
    friend bool operator<=(const Fraction& left, const Fraction& right);
    friend bool operator>=(const Fraction& left, const Fraction& right);
    friend bool operator<(const Fraction& left, const Fraction& right);
    friend bool operator>(const Fraction& left, const Fraction& right);
};

#endif //ARITHMETIC_CODING_FRACTION_HPP
