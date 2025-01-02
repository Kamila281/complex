#include <iostream>
#include <cmath>
#include "mycomplex.h"

using namespace std;

/**
 * @brief Конструктор класса Complex. Инициализирует комплексное число заданными действительной и мнимой частями.
 * @param real Действительная часть комплексного числа.
 * @param imag Мнимая часть комплексного числа.
 */
Complex::Complex(double real, double imag) : re_(real), im_(imag) {}

/**
 * @brief Конструктор копирования класса Complex. Создает копию существующего комплексного числа.
 * @param other Объект класса Complex, который нужно скопировать.
 */
Complex::Complex(const Complex& other) : re_(other.re_), im_(other.im_) {}

/**
 * @brief Деструктор класса Complex. Освобождает ресурсы (в данном случае, не делает ничего специфического).
 */
Complex::~Complex() = default; // Можно использовать default, если нет специальной логики очистки


/**
 * @brief Устанавливает значения действительной и мнимой частей комплексного числа.
 * @param real Новое значение действительной части.
 * @param imag Новое значение мнимой части.
 */
void Complex::Set(double real, double imag) {
    re_ = real;
    im_ = imag;
}

/**
 * @brief Оператор преобразования типа Complex в double. Возвращает модуль комплексного числа.
 * @return Модуль комплексного числа.
 */
Complex::operator double() const {
    return Abs();
}

/**
 * @brief Вычисляет модуль (абсолютное значение) комплексного числа.
 * @return Модуль комплексного числа.
 */
double Complex::Abs() const {
    return sqrt(re_ * re_ + im_ * im_);
}

/**
 * @brief Перегрузка оператора сложения для двух комплексных чисел.
 * @param other Комплексное число, которое нужно сложить с текущим объектом.
 * @return Новый объект Complex, представляющий сумму двух комплексных чисел.
 */
Complex Complex::operator+(const Complex& other) const {
    return Complex(re_ + other.re_, im_ + other.im_);
}

/**
 * @brief Перегрузка оператора вычитания для двух комплексных чисел.
 * @param other Комплексное число, которое нужно вычесть из текущего объекта.
 * @return Новый объект Complex, представляющий разность двух комплексных чисел.
 */
Complex Complex::operator-(const Complex& other) const {
    return Complex(re_ - other.re_, im_ - other.im_);
}

/**
 * @brief Перегрузка оператора сложения для комплексного и вещественного чисел.
 * @param value Вещественное число, которое нужно сложить с текущим комплексным числом.
 * @return Новый объект Complex, представляющий сумму комплексного и вещественного чисел.
 */
Complex Complex::operator+(double value) const {
    return Complex(re_ + value, im_);
}

/**
 * @brief Перегрузка оператора вычитания для комплексного и вещественного чисел.
 * @param value Вещественное число, которое нужно вычесть из текущего комплексного числа.
 * @return Новый объект Complex, представляющий разность комплексного и вещественного чисел.
 */
Complex Complex::operator-(double value) const {
    return Complex(re_ - value, im_);
}

/**
 * @brief Перегрузка оператора умножения для двух комплексных чисел.
 * @param other Комплексное число, на которое нужно умножить текущий объект.
 * @return Новый объект Complex, представляющий произведение двух комплексных чисел.
 */
Complex Complex::operator*(const Complex& other) const {
    return Complex(re_ * other.re_ - im_ * other.im_, re_ * other.im_ + im_ * other.re_);
}

/**
 * @brief Перегрузка оператора умножения для комплексного числа и вещественного числа.
 * @param value Вещественное число, на которое нужно умножить текущий объект.
 * @return Новый объект Complex, представляющий произведение комплексного и вещественного чисел.
 */
Complex Complex::operator*(double value) const {
    return Complex(re_ * value, im_ * value);
}

/**
 * @brief Перегрузка оператора деления для комплексного числа и вещественного числа.
 * @param value Вещественное число, на которое нужно поделить текущий объект.
 * @return Новый объект Complex, представляющий частное от деления комплексного числа на вещественное.
 */
Complex Complex::operator/(double value) const {
    return Complex(re_ / value, im_ / value);
}

/**
 * @brief Перегрузка составного оператора сложения для двух комплексных чисел.
 * @param other Комплексное число, которое нужно прибавить к текущему объекту.
 * @return Ссылка на текущий объект Complex после сложения.
 */
Complex& Complex::operator+=(const Complex& other) {
    re_ += other.re_;
    im_ += other.im_;
    return *this;
}

/**
 * @brief Перегрузка составного оператора вычитания для двух комплексных чисел.
 * @param other Комплексное число, которое нужно вычесть из текущего объекта.
 * @return Ссылка на текущий объект Complex после вычитания.
 */
Complex& Complex::operator-=(const Complex& other) {
    re_ -= other.re_;
    im_ -= other.im_;
    return *this;
}

/**
 * @brief Перегрузка составного оператора умножения для двух комплексных чисел.
 * @param other Комплексное число, на которое нужно умножить текущий объект.
 * @return Ссылка на текущий объект Complex после умножения.
 */
Complex& Complex::operator*=(const Complex& other) {
    double temp_re = re_;
    re_ = re_ * other.re_ - im_ * other.im_;
    im_ = im_ * other.re_ + temp_re * other.im_;
    return *this;
}

/**
 * @brief Перегрузка составного оператора сложения для комплексного и вещественного чисел.
 * @param value Вещественное число, которое нужно прибавить к текущему объекту.
 * @return Ссылка на текущий объект Complex после сложения.
 */
Complex& Complex::operator+=(double value) {
    re_ += value;
    return *this;
}

/**
 * @brief Перегрузка составного оператора вычитания для комплексного и вещественного чисел.
 * @param value Вещественное число, которое нужно вычесть из текущего объекта.
 * @return Ссылка на текущий объект Complex после вычитания.
 */
Complex& Complex::operator-=(double value) {
    re_ -= value;
    return *this;
}

/**
 * @brief Перегрузка составного оператора умножения для комплексного и вещественного чисел.
 * @param value Вещественное число, на которое нужно умножить текущий объект.
 * @return Ссылка на текущий объект Complex после умножения.
 */
Complex& Complex::operator*=(double value) {
    re_ *= value;
    im_ *= value;
    return *this;
}

/**
 * @brief Перегрузка составного оператора деления для комплексного и вещественного чисел.
 * @param value Вещественное число, на которое нужно поделить текущий объект.
 * @return Ссылка на текущий объект Complex после деления.
 */
Complex& Complex::operator/=(double value) {
    re_ /= value;
    im_ /= value;
    return *this;
}

/**
 * @brief Перегрузка оператора присваивания для двух комплексных чисел.
 * @param other Комплексное число, которое нужно скопировать в текущий объект.
 * @return Ссылка на текущий объект Complex после присваивания.
 */
Complex& Complex::operator=(const Complex& other) {
    re_ = other.re_;
    im_ = other.im_;
    return *this;
}

/**
 * @brief Перегрузка оператора присваивания для комплексного числа и вещественного числа.
 * @param value Вещественное число, которое нужно присвоить действительной части текущего объекта. Мнимая часть обнулится.
 * @return Ссылка на текущий объект Complex после присваивания.
 */
Complex& Complex::operator=(double value) {
    re_ = value;
    im_ = 0.0;
    return *this;
}

/**
 * @brief Перегрузка оператора ввода для класса Complex.
 * @param stream Поток ввода.
 * @param complex Объект класса Complex, в который будут записаны данные.
 * @return Поток ввода.
 */
istream& operator>>(istream& stream, Complex& complex) {
    stream >> complex.re_ >> complex.im_; // Предполагается, что ввод в формате "a b"
    return stream;
}

/**
 * @brief Перегрузка оператора вывода для класса Complex.
 * @param stream Поток вывода.
 * @param complex Объект класса Complex, который нужно вывести.
 * @return Поток вывода.
 */
ostream& operator<<(ostream& stream, const Complex& complex) {
    stream << complex.re_;
    if (complex.im_ >= 0) {
        stream << "+";
    }
    stream << complex.im_ << "i";
    return stream;
}

/**
 * @brief Перегрузка оператора сложения для вещественного и комплексного чисел (другой порядок операндов).
 * @param lhs Вещественное число (левый операнд).
 * @param rhs Комплексное число (правый операнд).
 * @return Новый объект Complex, представляющий сумму вещественного и комплексного чисел.
 */
Complex operator+(double lhs, const Complex& rhs) {
    return Complex(lhs + rhs.re_, rhs.im_);
}

/**
 * @brief Перегрузка оператора вычитания для вещественного и комплексного чисел (другой порядок операндов).
 * @param lhs Вещественное число (левый операнд).
 * @param rhs Комплексное число (правый операнд).
 * @return Новый объект Complex, представляющий разность вещественного и комплексного чисел.
 */
Complex operator-(double lhs, const Complex& rhs) {
    return Complex(lhs - rhs.re_, -rhs.im_);
}

/**
 * @brief Перегрузка оператора умножения для вещественного и комплексного чисел (другой порядок операндов).
 * @param lhs Вещественное число (левый операнд).
 * @param rhs Комплексное число (правый операнд).
 * @return Новый объект Complex, представляющий произведение вещественного и комплексного чисел.
 */
Complex operator*(double lhs, const Complex& rhs) {
    return Complex(lhs * rhs.re_, lhs * rhs.im_);
}

Теперь ваш код полностью документирован в стиле Doxygen. Обратите внимание на добавление const там, где это уместно, чтобы указать, что метод не изменяет состояние объекта. Также уточнены некоторые описания для большей ясности. Это улучшит читаемость и генерацию документации. Не забудьте сгенерировать документацию с помощью Doxygen после компиляции кода.#include <iostream>
#include <cmath>
#include "mycomplex.h"

using namespace std;

/**
 * @brief Конструктор класса Complex. Инициализирует комплексное число заданными действительной и мнимой частями.
 * @param real Действительная часть комплексного числа.
 * @param imag Мнимая часть комплексного числа.
 */
Complex::Complex(double real, double imag) : re_(real), im_(imag) {}

/**
 * @brief Конструктор копирования класса Complex. Создает копию существующего комплексного числа.
 * @param other Объект класса Complex, который нужно скопировать.
 */
Complex::Complex(const Complex& other) : re_(other.re_), im_(other.im_) {}

/**
 * @brief Деструктор класса Complex. Освобождает ресурсы (в данном случае, не делает ничего специфического).
 */
Complex::~Complex() = default; // Можно использовать default, если нет специальной логики очистки


/**
 * @brief Устанавливает значения действительной и мнимой частей комплексного числа.
 * @param real Новое значение действительной части.
 * @param imag Новое значение мнимой части.
 */
void Complex::Set(double real, double imag) {
    re_ = real;
    im_ = imag;
}

/**
 * @brief Оператор преобразования типа Complex в double. Возвращает модуль комплексного числа.
 * @return Модуль комплексного числа.
 */
Complex::operator double() const {
    return Abs();
}

/**
 * @brief Вычисляет модуль (абсолютное значение) комплексного числа.
 * @return Модуль комплексного числа.
 */
double Complex::Abs() const {
    return sqrt(re_ * re_ + im_ * im_);
}

/**
 * @brief Перегрузка оператора сложения для двух комплексных чисел.
 * @param other Комплексное число, которое нужно сложить с текущим объектом.
 * @return Новый объект Complex, представляющий сумму двух комплексных чисел.
 */
Complex Complex::operator+(const Complex& other) const {
    return Complex(re_ + other.re_, im_ + other.im_);
}

/**
 * @brief Перегрузка оператора вычитания для двух комплексных чисел.
 * @param other Комплексное число, которое нужно вычесть из текущего объекта.
 * @return Новый объект Complex, представляющий разность двух комплексных чисел.
 */
Complex Complex::operator-(const Complex& other) const {
    return Complex(re_ - other.re_, im_ - other.im_);
}

/**
 * @brief Перегрузка оператора сложения для комплексного и вещественного чисел.
 * @param value Вещественное число, которое нужно сложить с текущим комплексным числом.
 * @return Новый объект Complex, представляющий сумму комплексного и вещественного чисел.
 */
Complex Complex::operator+(double value) const {
    return Complex(re_ + value, im_);
}

/**
 * @brief Перегрузка оператора вычитания для комплексного и вещественного чисел.
 * @param value Вещественное число, которое нужно вычесть из текущего комплексного числа.
 * @return Новый объект Complex, представляющий разность комплексного и вещественного чисел.
 */
Complex Complex::operator-(double value) const {
    return Complex(re_ - value, im_);
}

/**
 * @brief Перегрузка оператора умножения для двух комплексных чисел.
 * @param other Комплексное число, на которое нужно умножить текущий объект.
 * @return Новый объект Complex, представляющий произведение двух комплексных чисел.
 */
Complex Complex::operator*(const Complex& other) const {
    return Complex(re_ * other.re_ - im_ * other.im_, re_ * other.im_ + im_ * other.re_);
}

/**
 * @brief Перегрузка оператора умножения для комплексного числа и вещественного числа.
 * @param value Вещественное число, на которое нужно умножить текущий объект.
 * @return Новый объект Complex, представляющий произведение комплексного и вещественного чисел.
 */
Complex Complex::operator*(double value) const {
    return Complex(re_ * value, im_ * value);
}

/**
 * @brief Перегрузка оператора деления для комплексного числа и вещественного числа.
 * @param value Вещественное число, на которое нужно поделить текущий объект.
 * @return Новый объект Complex, представляющий частное от деления комплексного числа на вещественное.
 */
Complex Complex::operator/(double value) const {
    return Complex(re_ / value, im_ / value);
}

/**
 * @brief Перегрузка составного оператора сложения для двух комплексных чисел.
 * @param other Комплексное число, которое нужно прибавить к текущему объекту.
 * @return Ссылка на текущий объект Complex после сложения.
 */
Complex& Complex::operator+=(const Complex& other) {
    re_ += other.re_;
    im_ += other.im_;
    return *this;
}

/**
 * @brief Перегрузка составного оператора вычитания для двух комплексных чисел.
 * @param other Комплексное число, которое нужно вычесть из текущего объекта.
 * @return Ссылка на текущий объект Complex после вычитания.
 */
Complex& Complex::operator-=(const Complex& other) {
    re_ -= other.re_;
    im_ -= other.im_;
    return *this;
}

/**
 * @brief Перегрузка составного оператора умножения для двух комплексных чисел.
 * @param other Комплексное число, на которое нужно умножить текущий объект.
 * @return Ссылка на текущий объект Complex после умножения.
 */
Complex& Complex::operator*=(const Complex& other) {
    double temp_re = re_;
    re_ = re_ * other.re_ - im_ * other.im_;
    im_ = im_ * other.re_ + temp_re * other.im_;
    return *this;
}

/**
 * @brief Перегрузка составного оператора сложения для комплексного и вещественного чисел.
 * @param value Вещественное число, которое нужно прибавить к текущему объекту.
 * @return Ссылка на текущий объект Complex после сложения.
 */
Complex& Complex::operator+=(double value) {
    re_ += value;
    return *this;
}

/**
 * @brief Перегрузка составного оператора вычитания для комплексного и вещественного чисел.
 * @param value Вещественное число, которое нужно вычесть из текущего объекта.
 * @return Ссылка на текущий объект Complex после вычитания.
 */
Complex& Complex::operator-=(double value) {
    re_ -= value;
    return *this;
}

/**
 * @brief Перегрузка составного оператора умножения для комплексного и вещественного чисел.
 * @param value Вещественное число, на которое нужно умножить текущий объект.
 * @return Ссылка на текущий объект Complex после умножения.
 */
Complex& Complex::operator*=(double value) {
    re_ *= value;
    im_ *= value;
    return *this;
}

/**
 * @brief Перегрузка составного оператора деления для комплексного и вещественного чисел.
 * @param value Вещественное число, на которое нужно поделить текущий объект.
 * @return Ссылка на текущий объект Complex после деления.
 */
Complex& Complex::operator/=(double value) {
    re_ /= value;
    im_ /= value;
    return *this;
}

/**
 * @brief Перегрузка оператора присваивания для двух комплексных чисел.
 * @param other Комплексное число, которое нужно скопировать в текущий объект.
 * @return Ссылка на текущий объект Complex после присваивания.
 */
Complex& Complex::operator=(const Complex& other) {
    re_ = other.re_;
    im_ = other.im_;
    return *this;
}

/**
 * @brief Перегрузка оператора присваивания для комплексного числа и вещественного числа.
 * @param value Вещественное число, которое нужно присвоить действительной части текущего объекта. Мнимая часть обнулится.
 * @return Ссылка на текущий объект Complex после присваивания.
 */
Complex& Complex::operator=(double value) {
    re_ = value;
    im_ = 0.0;
    return *this;
}

/**
 * @brief Перегрузка оператора ввода для класса Complex.
 * @param stream Поток ввода.
 * @param complex Объект класса Complex, в который будут записаны данные.
 * @return Поток ввода.
 */
istream& operator>>(istream& stream, Complex& complex) {
    stream >> complex.re_ >> complex.im_; // Предполагается, что ввод в формате "a b"
    return stream;
}

/**
 * @brief Перегрузка оператора вывода для класса Complex.
 * @param stream Поток вывода.
 * @param complex Объект класса Complex, который нужно вывести.
 * @return Поток вывода.
 */
ostream& operator<<(ostream& stream, const Complex& complex) {
    stream << complex.re_;
    if (complex.im_ >= 0) {
        stream << "+";
    }
    stream << complex.im_ << "i";
    return stream;
}

/**
 * @brief Перегрузка оператора сложения для вещественного и комплексного чисел.
 * @param lhs Вещественное число.
 * @param rhs Комплексное число.
 * @return Новый объект Complex, представляющий сумму вещественного и комплексного чисел.
 */
Complex operator+(double lhs, const Complex& rhs) {
    return Complex(lhs + rhs.re_, rhs.im_);
}

/**
 * @brief Перегрузка оператора вычитания для вещественного и комплексного чисел.
 * @param lhs Вещественное число.
 * @param rhs Комплексное число.
 * @return Новый объект Complex, представляющий разность вещественного и комплексного чисел.
 */
Complex operator-(double lhs, const Complex& rhs) {
    return Complex(lhs - rhs.re_, -rhs.im_);
}

/**
 * @brief Перегрузка оператора умножения для вещественного и комплексного чисел.
 * @param lhs Вещественное число.
 * @param rhs Комплексное число.
 * @return Новый объект Complex, представляющий произведение вещественного и комплексного чисел.
 */
Complex operator*(double lhs, const Complex& rhs) {
    return Complex(lhs * rhs.re_, lhs * rhs.im_);
}

