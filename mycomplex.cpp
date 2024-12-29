#include <iostream>
#include <cmath>
#include "mycomplex.h"

using namespace std;


Complex::Complex(double real, double imag) {
    re_ = real;
    im_ = imag;
}

Complex::Complex(const Complex& other) {
    re_ = other.re_;
    im_ = other.im_;
}

Complex::~Complex() {
    re_ = 0.0;
    im_ = 0.0;
}


void Complex::Set(double real, double imag) {
    re_ = real;
    im_ = imag;
}

Complex::operator double() {
    return Abs();
}

double Complex::Abs() {
    return sqrt(re_ * re_ + im_ * im_);
}


Complex Complex::operator+(const Complex& other) {
    Complex result;
    result.re_ = re_ + other.re_;
    result.im_ = im_ + other.im_;
    return result;
}

Complex Complex::operator-(const Complex& other) {
    Complex result;
    result.re_ = re_ - other.re_;
    result.im_ = im_ - other.im_;
    return result;
}

Complex Complex::operator+(const double& value) {
    Complex result;
    result.re_ = re_ + value;
    result.im_ = im_;
    return result;
}

Complex Complex::operator-(const double& value) {
    Complex result;
    result.re_ = re_ - value;
    result.im_ = im_;
    return result;
}

Complex Complex::operator*(const Complex& other) {
    Complex result;
    result.re_ = re_ * other.re_ - im_ * other.im_;
    result.im_ = re_ * other.im_ + im_ * other.re_;
    return result;
}
/**
* @brief Перегрузка оператора умножения для комплексного числа и вещественного числа.
* @param value Вещественное число
* @return Резултьтат умножения 
*/
Complex Complex::operator*(const double& value) {
    Complex result;
    result.re_ = re_ * value;
    result.im_ = im_ * value;
    return result;
}

/**
* @brief Перегрузка оператора умножения для комплексного числа и вещественного числа.
* @param value Вещественное число
* @return Резултьтат деления
*/

Complex Complex::operator/(const double& value) {
    Complex result;
    result.re_ = re_ / value;
    result.im_ = im_ / value;
    return result;
}

Complex& Complex::operator+=(const Complex& other) {
    re_ += other.re_;
    im_ += other.im_;
    return *this;
}

Complex& Complex::operator-=(const Complex& other) {
    re_ -= other.re_;
    im_ -= other.im_;
    return *this;
}

Complex& Complex::operator*=(const Complex& other) {
    double temp_re = re_;
    re_ = re_ * other.re_ - im_ * other.im_;
    im_ = im_ * other.re_ + temp_re * other.im_;
    return *this;
}

Complex& Complex::operator+=(const double& value) {
    re_ += value;
    return *this;
}

Complex& Complex::operator-=(const double& value) {
    re_ -= value;
    return *this;
}

Complex& Complex::operator*=(const double& value) {
    re_ *= value;
    im_ *= value;
    return *this;
}

Complex& Complex::operator/=(const double& value) {
    re_ /= value;
    im_ /= value;
    return *this;
}

Complex& Complex::operator=(const Complex& other) {
    re_ = other.re_;
    im_ = other.im_;
    return *this;
}

Complex& Complex::operator=(const double& value) {
    re_ = value;
    im_ = 0.0;
    return *this;
}


istream& operator>>(istream& stream, Complex& complex) {
    char tmp[256];
    stream >> complex.re_ >> complex.im_ >> tmp;
    return stream;
}

ostream& operator<<(ostream& stream, Complex& complex) {
    stream << complex.re_;
    if (!(complex.im_ < 0)) {
        stream << '+';
    }
    stream << complex.im_ << 'i';
    return stream;
}

Complex operator+(const double& lhs, const Complex& rhs) {
    Complex result;
    result.re_ = lhs + rhs.re_;
    result.im_ = rhs.im_;
    return result;
}

Complex operator-(const double& lhs, const Complex& rhs) {
    Complex result;
    result.re_ = lhs - rhs.re_;
    result.im_ = -rhs.im_;
    return result;
}

Complex operator*(const double& lhs, const Complex& rhs) {
    Complex result;
    result.re_ = lhs * rhs.re_;
    result.im_ = lhs * rhs.im_;
    return result;
}
