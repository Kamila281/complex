#ifndef MY_COMPLEX_H
#define MY_COMPLEX_H

#include <iostream>
using namespace std;

class Complex {
private:
    double Re; // Реальная часть
    double Im; // Мнимая часть

public:
    /**
    * @brief Конструктор с возможностью задать значения частей комплексного числа
    * @param aRe Действительная часть (по умолчанию 0)
    * @param Мнимая часть(по умолчанию 0)
    */
    Complex(double aRe = 0, double aIm = 0);

    /**
    * @brief Конструктор копирования
    * @param other Другой объект Complex для копирования
    */
    Complex(const Complex& other);

    /** 
    * @brief Деструктор
    */
    ~Complex();

    /**
    * @brief Метод для установки значений частей
    * @param aRe Новое значение действительной части
    * @param aIm Новое значение мнимой части(по умолчанию 0)
    */
    void Set(double aRe, double aIm = 0);

    /**
    * @brief Оператор преобразования в double(например, для получения длины вектора)
    */
    operator double();

    // Метод для вычисления модуля комплексного числа
    double abs();

    // Перегрузка оператора ввода
    friend istream& operator>>(istream& input, Complex& c);

    // Перегрузка оператора вывода
    friend ostream& operator<<(ostream& output, Complex& c);

    // Перегрузка оператора сложения (с другим комплексным числом)
    Complex operator+(const Complex& other);

    // Перегрузка оператора вычитания (с другим комплексным числом)
    Complex operator-(const Complex& other);

    // Перегрузка оператора сложения (с числом типа double)
    Complex operator+(const double& value);

    // Перегрузка оператора сложения (с числом типа double) в другом порядке
    friend Complex operator+(const double& value, const Complex& c);

    // Перегрузка оператора вычитания (с числом типа double)
    Complex operator-(const double& value);

    // Перегрузка оператора вычитания (с числом типа double) в другом порядке
    friend Complex operator-(const double& value, const Complex& c);

    // Перегрузка оператора умножения (с другим комплексным числом)
    Complex operator*(const Complex& other);

    // Перегрузка оператора умножения (с числом типа double)
    Complex operator*(const double& value);

    // Перегрузка оператора умножения (с числом типа double) в другом порядке
    friend Complex operator*(const double& value, const Complex& c);

    // Перегрузка оператора деления (на число типа double)
    Complex operator/(const double& value);

    // Перегрузка оператора += (с другим комплексным числом)
    Complex& operator+=(const Complex& other);

    // Перегрузка оператора -= (с другим комплексным числом)
    Complex& operator-=(const Complex& other);

    // Перегрузка оператора *= (с другим комплексным числом)
    Complex& operator*=(const Complex& other);

    // Перегрузка оператора += (с числом типа double)
    Complex& operator+=(const double& value);

    // Перегрузка оператора -= (с числом типа double)
    Complex& operator-=(const double& value);

    // Перегрузка оператора *= (с числом типа double)
    Complex& operator*=(const double& value);

    // Перегрузка оператора /= (с числом типа double)
    Complex& operator/=(const double& value);

    // Перегрузка оператора присваивания (копирование комплексного числа)
    Complex& operator=(const Complex& other);

    // Перегрузка оператора присваивания (присваивание числа типа double)
    Complex& operator=(const double& value);
};

#endif // MY_COMPLEX_H
