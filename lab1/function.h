#pragma once
#include "polynom.h"
#include <cmath>
#include <complex>
#include <iostream>

template <typename T>
T* find_real_roots(const Polynom<T>& pol)
{
    T* coeffs = pol.coeffs();
    size_t degree = pol.degree();

    if (degree != 3) throw std::invalid_argument("Max degree must be 3");

    T a = coeffs[3];
    if (a == 0) throw std::invalid_argument("Coeff must not be 0");
    T b = coeffs[2];
    T c = coeffs[1];
    T d = coeffs[0];

    T* roots = new T[3];
    int root_count = 0;

    T f = ((3 * c / a) - (b * b) / (a * a)) / 3;
    T g = ((2 * b * b * b) / (a * a * a) - (9 * b * c) / (a * a) + (27 * d / a)) / 27;
    T h = (g * g / 4) + (f * f * f / 27);

    if (h > 0) {
        T r = -(g / 2) + std::sqrt(h);
        T s = std::cbrt(r);
        r = -(g / 2) - std::sqrt(h);
        T t = std::cbrt(r);

        roots[0] = (s + t) - (b / (3 * a));
        root_count = 1;
    }
    else if (f == 0 && g == 0 && h == 0) {
        T root = -std::cbrt(d / a);
        roots[0] = root;
        roots[1] = root;
        roots[2] = root;
        root_count = 3;
    }
    else {
        T i = std::sqrt((g * g / 4) - h);
        T j = std::cbrt(i);
        T k = std::acos(-(g / (2 * i)));
        T l = -j;
        T m = std::cos(k / 3);
        T n = std::sqrt(3) * std::sin(k / 3);
        T p = (b / (3 * a));

        roots[0] = 2 * j * m - p;
        roots[1] = l * (m + n) - p;
        roots[2] = l * (m - n) - p;
        root_count = 3;
    }

    T* result = new T[root_count];
    for (int i = 0; i < root_count; ++i) {
        result[i] = roots[i];
    }

    return result;
}

template<>
std::complex<double>* find_real_roots(const Polynom<std::complex<double>>& pol)
{

    if (pol.degree() != 3) throw std::invalid_argument("Max degree must be 3");

    std::complex<double>* coeffs = pol.coeffs();

    std::complex<double> a = coeffs[3];
    if (a == std::complex<double>(0)) throw std::invalid_argument("Coeff must not be 0");
    std::complex<double> b = coeffs[2];
    std::complex<double> c = coeffs[1];
    std::complex<double> d = coeffs[0];

    std::complex<double> p = (3.0 * a * c - b * b) / (3.0 * a * a);
    std::complex<double> q = (2.0 * b * b * b - 9.0 * a * b * c + 27.0 * a * a * d) / (27.0 * a * a * a);

    std::complex<double> Q = (p / 3.0) * (p / 3.0) * (p / 3.0) + (q / 2.0) * (q / 2.0);

    std::complex<double> u = std::pow(-q / 2.0 + std::sqrt(Q), 1.0 / 3.0);
    std::complex<double> v = std::pow(-q / 2.0 - std::sqrt(Q), 1.0 / 3.0);

    std::complex<double>* roots = new std::complex<double>[3];
    size_t count = 0;
    if (Q.real() > 0) 
    {
        roots[count++] = u + v;
    }
    else if (Q.real() == 0) {
        roots[count++] = 2.0 * u;
        roots[count++] = roots[2] = -u;
    }
    else 
    {
        double r = std::sqrt(-std::norm(q) / 4.0);
        double theta = acos(-q.real() / (2.0 * r * r * r));
        roots[count++] = 2.0 * r * std::exp(std::complex<double>(0, theta / 3.0));
        roots[count++] = 2.0 * r * std::exp(std::complex<double>(0, (theta + 2 * 3.14) / 3.0));
        roots[count++] = 2.0 * r * std::exp(std::complex<double>(0, (theta + 4 * 3.14) / 3.0));
    }

    return roots;
}

template<>
std::complex<float>* find_real_roots(const Polynom<std::complex<float>>& pol)
{

    if (pol.degree() != 3) throw std::invalid_argument("Max degree must be 3");
    std::complex<float>* coeffs = pol.coeffs();

    std::complex<float> a = coeffs[3];
    if (a == std::complex<float>(0)) throw std::invalid_argument("Coeff must not be 0");
    std::complex<float> b = coeffs[2];
    std::complex<float> c = coeffs[1];
    std::complex<float> d = coeffs[0];


    std::complex<float> p = (float(3.0) * a * c - b * b) / (float(3.0) * a * a);
    std::complex<float> q = (float(2.0) * b * b * b - float(9.0) * a * b * c + float(27.0) * a * a * d) / (float(27.0) * a * a * a);

    std::complex<float> Q = (p / float(3.0)) * (p / float(3.0)) * (p / float(3.0)) + (q / float(2.0)) * (q / float(2.0));

    std::complex<float> u = std::pow(-q / float(2.0) + std::sqrt(Q), float(1.0) / float(3.0));
    std::complex<float> v = std::pow(-q / float(2.0) - std::sqrt(Q), float(1.0) / float(3.0));

    std::complex<float>* roots = new std::complex<float>[3];
    size_t count = 0;
    if (Q.real() > 0) 
    {
        roots[count++] = u + v;
    }
    else if (Q.real() == 0) {
        roots[count++] = float(2.0) * u;
        roots[count++] = roots[2] = -u;
    }
    else 
    {
        float r = std::sqrt(-std::norm(q) / 4.0);
        float theta = acos(-q.real() / (float(2.0) * r * r * r));
        roots[count++] = float(2.0) * r * std::exp(std::complex<float>(0, theta / float(3.0)));
        roots[count++] = float(2.0) * r * std::exp(std::complex<float>(0, (theta + 2 * 3.14) / float(3.0)));
        roots[count++] = float(2.0) * r * std::exp(std::complex<float>(0, (theta + 4 * 3.14) / float(3.0)));
    }

    return roots;
}
