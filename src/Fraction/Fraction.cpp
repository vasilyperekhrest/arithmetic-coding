//
// Created by Vasily Perekhrest on 16.04.2021.
//

#include "Fraction.hpp"

Fraction::Fraction() {
    numerator = 0;
    denominator = 1;
}

[[maybe_unused]] Fraction::Fraction(const mpz_class &_numerator, const mpz_class &_denominator) {
    mpz_class d = gcd(_numerator, _denominator);
    numerator = _numerator / d;
    denominator = _denominator / d;
}

[[maybe_unused]] Fraction::Fraction(const std::string &_numerator, const std::string &_denominator) {
    numerator.set_str(_numerator, 10);
    denominator.set_str(_denominator, 10);
    mpz_class d = gcd(numerator, denominator);
    numerator /= d;
    denominator /= d;
}

Fraction::Fraction(const Fraction &fraction) {
    this->numerator = fraction.numerator;
    this->denominator = fraction.denominator;
}

std::ostream &operator<<(std::ostream &out, const Fraction &fraction) {
    out << fraction.numerator << "/" << fraction.denominator;
    return out;
}

Fraction operator+(const Fraction &left, const Fraction &right) {
    mpz_class denominator = lcm(left.denominator, right.denominator);
    mpz_class left_numerator = denominator / left.denominator * left.numerator;
    mpz_class right_numerator = denominator / right.denominator * right.numerator;

    return Fraction(left_numerator + right_numerator, denominator);
}

Fraction operator-(const Fraction &left, const Fraction &right) {
    mpz_class denominator = lcm(left.denominator, right.denominator);
    mpz_class left_numerator = denominator / left.denominator * left.numerator;
    mpz_class right_numerator = denominator / right.denominator * right.numerator;

    return Fraction(left_numerator - right_numerator, denominator);
}

Fraction operator*(const Fraction& left, const Fraction& right) {
    mpz_class d_left = gcd(left.numerator, right.denominator);
    mpz_class left_numerator = left.numerator / d_left;
    mpz_class right_denominator = right.denominator / d_left;

    mpz_class d_right = gcd(right.numerator, left.denominator);
    mpz_class right_numerator = right.numerator / d_right;
    mpz_class left_denominator = left.denominator / d_right;

    return Fraction(left_numerator * right_numerator, left_denominator * right_denominator);
}

Fraction operator/(const Fraction& left, const Fraction& right) {
    mpz_class d_left = gcd(left.numerator, right.numerator);
    mpz_class left_numerator = left.numerator / d_left;
    mpz_class right_denominator = right.numerator / d_left;

    mpz_class d_right = gcd(left.denominator, right.denominator);
    mpz_class right_numerator = right.denominator / d_right;
    mpz_class left_denominator = left.denominator / d_right;

    return Fraction(left_numerator * right_numerator, left_denominator * right_denominator);
}

bool operator==(const Fraction &left, const Fraction &right) {
    if (left.denominator == right.denominator and left.numerator == right.numerator) {
        return true;
    } else {
        return false;
    }
}

bool operator!=(const Fraction &left, const Fraction &right) {
    if (left.denominator != right.denominator or left.numerator != right.numerator) {
        return true;
    } else {
        return false;
    }
}

bool operator<=(const Fraction &left, const Fraction &right) {
    mpz_class denominator = lcm(left.denominator, right.denominator);
    mpz_class left_numerator = denominator / left.denominator * left.numerator;
    mpz_class right_numerator = denominator / right.denominator * right.numerator;

    if (left_numerator <= right_numerator) {
        return true;
    } else {
        return false;
    }
}

bool operator>=(const Fraction &left, const Fraction &right) {
    mpz_class denominator = lcm(left.denominator, right.denominator);
    mpz_class left_numerator = denominator / left.denominator * left.numerator;
    mpz_class right_numerator = denominator / right.denominator * right.numerator;

    if (left_numerator >= right_numerator) {
        return true;
    } else {
        return false;
    }
}

bool operator<(const Fraction &left, const Fraction &right) {
    mpz_class denominator = lcm(left.denominator, right.denominator);
    mpz_class left_numerator = denominator / left.denominator * left.numerator;
    mpz_class right_numerator = denominator / right.denominator * right.numerator;

    if (left_numerator < right_numerator) {
        return true;
    } else {
        return false;
    }
}

bool operator>(const Fraction &left, const Fraction &right) {
    mpz_class denominator = lcm(left.denominator, right.denominator);
    mpz_class left_numerator = denominator / left.denominator * left.numerator;
    mpz_class right_numerator = denominator / right.denominator * right.numerator;

    if (left_numerator > right_numerator) {
        return true;
    } else {
        return false;
    }
}
