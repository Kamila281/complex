#ifndef MY_COMPLEX_H
#define MY_COMPLEX_H

#include <iostream>
using namespace std;

/*
 * @brief Класс для представления комплексных чисел.
 */

class Complex {
private:
    double Re;  /*< Реальная часть комплексного числа.*/
    double Im; /*< Мнимая часть комплексного числа.*/


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

    /**
    * @brief Вычисляет модуль (абсолютное значение) комплексного числа.
    * @return Модуль комплексного числа.
    */
    double abs();

    /**
    * @brief Перегрузка оператора ввода для класса Complex.
    * @param input Поток ввода.
    * @param c Объект класса Complex, в который будет записано число.
    * @return Поток ввода.
    */
    friend istream& operator>>(istream& input, Complex& c);

    /** 
    * @brief Перегрузка оператора вывода для класса Complex.
    * @param output Поток вывода.
    * @param c Объект класса Complex, который нужно вывести.
    * @return Поток вывода.
    */
    friend ostream& operator<<(ostream& output, Complex& c);

    /**
    *@brief Перегрузка оператора сложения(с другим комплексным числом)
    * @param other Другой объект Complex 
    * @return Результат сложения 
    */
    Complex operator+(const Complex& other);

    /**
    * @brief Перегрузка оператора вычитания(с другим комплексным числом)
    * @param other  Другой объект Complex 
    * @return Результат вычитания
    */ 
    Complex operator-(const Complex& other);

    /**
    * @brief Перегрузка оператора сложения для Complex и double.
    * @param a Число типа double.
    * @return Результат сложения.
    */
    Complex operator+(const double& value);

    /**
    * @brief Перегрузка оператора сложения(с числом типа double) в другом порядке
    * @param value Число типа double
    * @param c Объект complex
    * @return Результат сложения
    */
     
    friend Complex operator+(const double& value, const Complex& c);

    /**
    * @brief Перегрузка оператора вычитания
    * @param value Число типа double
    * @return Результат вычитания 
    */ 
    Complex operator-(const double& value);

    /** 
    * @brief Перегрузка оператора вычитания(с числом типа double) в другом порядке
    * @param value Число типа double
    * @param c Объект complex
    * @return Результат вычитания
    */
    friend Complex operator-(const double& value, const Complex& c);

    /**
    * @brief Перегрузка оператора умножения(с другим комплексным числом)
    * @param other  Другой объект Complex
    * @return Результат умножения 
    */
    Complex operator*(const Complex& other);

    /**
    * @brief Перегрузка оператора умножения(с числом типа double) в другом порядке
    * @param value Число типа double
    * @return Результат умножения
    */
    Complex operator*(const double& value);
    
    /** 
    * @brief Перегрузка оператора умножения(с числом типа double) в другом порядке
    * @param value Число типа double
    * @param c Объект complex
    * @return Результат умножения
    */
    friend Complex operator*(const double& value, const Complex& c);
   
    /** 
    * @brief Перегрузка оператора деления(с числом типа double) в другом порядке
    * @param value Число типа double
    * @return Результат деления
    */
    Complex operator/(const double& value);

   /**
   * @brief Перегрузка оператора += для двух объектов Complex.
   * @param a Другой объект Complex.
   * @return Ссылка на текущий объект.
   */
    Complex& operator+=(const Complex& other);

    /**
    *@brief Перегрузка оператора -= для двух объектов Complex.
    * @param a Другой объект Complex.
    * @return Ссылка на текущий объект.
    */
    Complex& operator-=(const Complex& other);
  
    /**
   *@brief Перегрузка оператора *= для двух объектов Complex.
   * @param a Другой объект Complex.
   * @return Ссылка на текущий объект.
   */
    Complex& operator*=(const Complex& other);
   
    /**
    *@brief Перегрузка оператора += для Complex и double.
    * @param a Число типа double.
    * @return Ссылка на текущий объект.
    */
    Complex& operator+=(const double& value);

    /**
    *@brief Перегрузка оператора -= для Complex и double.
    * @param a Число типа double.
    * @return Ссылка на текущий объект.
    */
    Complex& operator-=(const double& value);

    /**
    *@brief Перегрузка оператора *= для Complex и double.
    * @param a Число типа double.
    * @return Ссылка на текущий объект.
    */
    Complex& operator*=(const double& value);

    /**
    *@brief Перегрузка оператора /= для Complex и double.
    * @param a Число типа double.
    * @return Ссылка на текущий объект.
    */
    Complex& operator/=(const double& value);

    /**
    *@brief Перегрузка оператора присваивания для двух объектов Complex.
    * @param a Другой объект Complex.
    * @return Ссылка на текущий объект.
    */
    Complex& operator=(const Complex& other);

    /**
    *@brief Перегрузка оператора присваивания для Complex и double.
    * @param a Число типа double.
    * @return Ссылка на текущий объект.
    */
    Complex& operator=(const double& value);
};

#endif // MY_COMPLEX_H
