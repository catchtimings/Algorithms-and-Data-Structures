#pragma once
#include "polynom.h"
#include <cmath>
#include <complex>
#include <iostream>
#define M_PI 3.14

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

//template <>
//std::complex<float>* find_real_roots(const Polynom<std::complex<float>>&) {
//    throw std::invalid_argument("There are no real roots for complex polynomials");
//}

template<>
std::complex<double>* find_real_roots(const Polynom<std::complex<double>>& pol)
{
    std::complex<double>* coeffs = pol.coeffs();

    if (pol.degree() != 3) throw std::invalid_argument("Max degree must be 3");

    std::complex<double> a = coeffs[3];
    std::complex<double> b = coeffs[2];
    std::complex<double> c = coeffs[1];
    std::complex<double> d = coeffs[0];

    if (a == static_cast<std::complex<double>>(0)) throw std::invalid_argument("Coeff must not be 0");
    std::complex<double> p = (3.0 * a * c - b * b) / (3.0 * a * a);
    std::complex<double> q = (2.0 * b * b * b - 9.0 * a * b * c + 27.0 * a * a * d) / (27.0 * a * a * a);

    std::complex<double> Q = (p / 3.0) * (p / 3.0) * (p / 3.0) + (q / 2.0) * (q / 2.0);

    std::complex<double>* roots = new std::complex<double>[3];
    if (Q.real() > 0) {
        std::complex<double> u = std::pow(-q / 2.0 + std::sqrt(Q), 1.0 / 3.0);
        std::complex<double> v = std::pow(-q / 2.0 - std::sqrt(Q), 1.0 / 3.0);
        roots[0] = u + v;
    }
    else if (Q.real() == 0) {
        std::complex<double> u = std::pow(-q / 2.0, 1.0 / 3.0);
        roots[0] = 2.0 * u;
        roots[1] = roots[2] = -u;
    }
    else {
        double r = std::sqrt(-std::norm(q) / 4.0);
        double theta = acos(-q.real() / (2.0 * r * r * r));
        roots[0] = 2.0 * r * std::exp(std::complex<double>(0, theta / 3.0));
        roots[1] = 2.0 * r * std::exp(std::complex<double>(0, (theta + 2 * M_PI) / 3.0));
        roots[2] = 2.0 * r * std::exp(std::complex<double>(0, (theta + 4 * M_PI) / 3.0));
    }

    return roots;
}