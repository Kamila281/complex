#include <iostream>
#include <cmath>
#include "mycomplex.h"

using namespace std;

// Конструкторы и деструктор
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

// Методы
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

// Операторы
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

Complex Complex::operator*(const double& value) {
    Complex result;
    result.re_ = re_ * value;
    result.im_ = im_ * value;
    return result;
}

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

// Ввод и вывод
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

// Операторы с double слева
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