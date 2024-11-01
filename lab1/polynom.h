#pragma once
#include <stdexcept>
#include <iostream>
#include <cmath>
#include <algorithm>

template <typename T>
class Polynom
{
private:
    T* _coeffs;
    size_t _degree;

public:

    Polynom(const size_t& degree) : _degree(degree) 
    {
        _coeffs = new T[_degree + 1];
        std::fill_n(_coeffs, _degree + 1, 0);
    }


    Polynom(const T* vector, const size_t& degree) : _degree(degree) 
    {
        _coeffs = new T[_degree + 1];
        for (size_t i = 0; i <= _degree; ++i) _coeffs[i] = vector[i];
    }


    Polynom(const Polynom<T>& other) : _degree(other._degree) 
    {
        _coeffs = new T[_degree + 1];
        for (size_t i = 0; i <= _degree; ++i) {
            _coeffs[i] = other._coeffs[i];
        }
    }


    ~Polynom() {
        delete[] _coeffs;
    }


    size_t degree() const noexcept { return _degree; }


    T* coeffs() const noexcept { return _coeffs; }


    T& operator[](const size_t& index) const 
    {
        if (index < 0 || index > _degree) throw std::out_of_range("Invalid degree value");
        return _coeffs[index];
    }


    void set(const T& value, const size_t& degree) 
    {
        if (degree < 0 || degree > _degree) throw std::out_of_range("Invalid degree value");
        _coeffs[degree] = value;
    }


    T calculate(const T& x) const 
    {
        T result = 0;
        for (size_t i = 0; i <= _degree; ++i) 
        {
            result += _coeffs[i] * pow(x,i);
        }
        return result;
    }


    void shrink_to_fit() 
    {
        int deg = static_cast<int>(_degree);
        size_t max_degree = 0;
        for (int i = deg; i >= 0; --i) 
        {
            if (_coeffs[i] != 0) {
                max_degree = static_cast<size_t>(i);
                break;
            }
        }

        if (max_degree == 0) throw std::invalid_argument("Degree must be greater than 0");

        T* new_coeffs = new T[max_degree + 1];

        for (size_t i = 0; i <= max_degree; ++i) 
        {
            new_coeffs[i] = _coeffs[i];
        }
        delete[] _coeffs;
        _coeffs = new_coeffs;
        _degree = max_degree;
    }


    void expand(const size_t& new_degree) 
    {
        if (new_degree <= _degree) throw std::invalid_argument("New degree must be greater than old");

        T* new_coeffs = new T[new_degree + 1];
        for (size_t i = 0; i <= new_degree; ++i) {
            T value = (i > _degree) ? 0 : _coeffs[i];
            new_coeffs[i] = value;
        }
        delete[] _coeffs;
        _coeffs = new_coeffs;
        _degree = new_degree;
    }


    Polynom<T>& operator=(const Polynom<T>& other) 
    {
        if (this != &other) {
            delete[] _coeffs;
            _degree = other.degree();
            _coeffs = new T[_degree + 1];
            for (size_t i = 0; i <= _degree; ++i) 
            {
                _coeffs[i] = other._coeffs[i];
            }
        }
        return *this;
    }


    Polynom<T>& operator +=(const Polynom<T>& other) 
    {
        size_t new_degree = _degree > other.degree() ? _degree : other.degree();
        T* new_coeffs = new T[new_degree + 1];

        for (size_t i = 0; i <= new_degree; ++i)
        {
            T c1 = (i > _degree) ? 0 : _coeffs[i];
            T c2 = (i > other.degree()) ? 0 : other._coeffs[i];
            new_coeffs[i] = c1 + c2;
        }

        delete[] _coeffs;
        _coeffs = new_coeffs;
        _degree = new_degree;
        return *this;
    }


    Polynom<T>& operator -=(const Polynom<T>& other) 
    {
        if (_degree < other.degree()) throw std::logic_error("You can't minusing big from small");

        T* new_coeffs = new T[_degree + 1];
        for (size_t i = 0; i <= _degree; ++i) {
            T c1 = _coeffs[i];
            T c2 = (i > other.degree()) ? 0 : other._coeffs[i];
            new_coeffs[i] = c1 - c2;
        }
        delete[] _coeffs;
        _coeffs = new_coeffs;
        return *this;
    }


    Polynom<T>& operator *=(const T& value) 
    {
        for (size_t i = 0; i <= _degree; ++i) {
            _coeffs[i] *= value;
        }
        return *this;
    }


    bool operator==(const Polynom<T>& other) const 
    {
        if (_degree != other._degree) return false;

        for (size_t i = 0; i <= _degree; ++i) {
            if (_coeffs[i] != other._coeffs[i]) return false;
        }

        return true;
    }


    bool operator!=(const Polynom<T>& other) const 
    {
        return !(*this == other);
    }

};



template <class T>
Polynom<T> operator+(Polynom<T> lhs, const Polynom<T>& rhs)
{
    return lhs += rhs;
}

template <class T>
Polynom<T> operator*(Polynom<T> lhs, const T& value) 
{
    return lhs *= value;
}

template <class T>
Polynom<T> operator-(Polynom<T> lhs, const Polynom<T>& rhs) 
{
    return lhs -= rhs;
}

template <class T>
Polynom<T> operator*(const T& value, Polynom<T> lhs) 
{
    return lhs *= value;
}

template <class T>
std::ostream& operator<<(std::ostream& os, const Polynom<T>& p) 
{
    T* coeffs = p.coeffs();
    int deg = static_cast<int>(p.degree());
    for (int i = deg; i >= 0; --i)
    {
        os << "(" << coeffs[i] << ")" << "x^" << i << " ";
        if (i > 0) os << " + ";
    }
    return os;
}