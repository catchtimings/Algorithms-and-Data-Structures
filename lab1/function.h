#pragma once
#include "polynom.h"
#include <cmath>
#include <complex>
#include <iostream>

template <typename T>
T* find_real_roots(const Polynom<T>& pol) {

    T* coeffs = pol.coeffs();
    size_t degree = pol.degree();

    if (degree != 3) throw std::invalid_argument("Max degree must be 3");

    T a = coeffs[3];
    T b = coeffs[2];
    T c = coeffs[1];
    T d = coeffs[0];

    if (a == 0) throw std::invalid_argument("Coeff must not be 0");


    size_t count = 0;
    T* roots = new T[3];

    T b1 = b / a;
    T c1 = c / a;
    T d1 = d / a;

    T p = (3 * c1 - b1 * b1) / 3;
    T q = (2 * b1 * b1 * b1 - 9 * b1 * c1 + 27 * d1) / 27;

    T discriminant = (q * q) / 4 + (p * p * p) / 27;

    if (discriminant > T(0)) {
        T u = std::cbrt(-q / T(2) + std::sqrt(discriminant));
        T v = std::cbrt(-q / T(2) - std::sqrt(discriminant));
        roots[count++] = u + v - b1 / T(3);
    }
    else if (discriminant == T(0)) {
        T u = std::cbrt(-q / T(2));
        roots[count++] = 2 * u - b1 / T(3);
        roots[count++] = u - b1 / T(3);
    }
    else {
        T u = std::cbrt(-q / T(2) + std::sqrt(-discriminant));
        T v = std::cbrt(-q / T(2) - std::sqrt(-discriminant));
        roots[count++] = u + v - b1 / T(3);
        roots[count++] = -0.5 * (u + v) - b1 / T(3);
        roots[count++] = 0.5 * std::sqrt(T(3)) * (u - v) - b1 / T(3);
    }

    return roots;
}

template <>
std::complex<float>* find_real_roots(const Polynom<std::complex<float>>& pol) {
    throw std::invalid_argument("There are no real roots for complex polynomials");
}

template <>
std::complex<double>* find_real_roots(const Polynom<std::complex<double>>& pol) {
    throw std::invalid_argument("There are no real roots for complex polynomials");
}