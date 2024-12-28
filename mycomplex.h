#ifndef MY_COMPLEX_H
#define MY_COMPLEX_H

#include <iostream>
using namespace std;

class Complex {
private:
    double Re; // �������� �����
    double Im; // ������ �����

public:
    /**
    * @brief ����������� � ������������ ������ �������� ������ ������������ �����
    * @param aRe �������������� ����� (�� ��������� 0)
    * @param ������ �����(�� ��������� 0)
    */
    Complex(double aRe = 0, double aIm = 0);

    /**
    * @brief ����������� �����������
    * @param other ������ ������ Complex ��� �����������
    */
    Complex(const Complex& other);

    /** 
    * @brief ����������
    */
    ~Complex();

    /**
    * @brief ����� ��� ��������� �������� ������
    * @param aRe ����� �������� �������������� �����
    * @param aIm ����� �������� ������ �����(�� ��������� 0)
    */
    void Set(double aRe, double aIm = 0);

    /**
    * @brief �������� �������������� � double(��������, ��� ��������� ����� �������)
    */
    operator double();

    // ����� ��� ���������� ������ ������������ �����
    double abs();

    // ���������� ��������� �����
    friend istream& operator>>(istream& input, Complex& c);

    // ���������� ��������� ������
    friend ostream& operator<<(ostream& output, Complex& c);

    // ���������� ��������� �������� (� ������ ����������� ������)
    Complex operator+(const Complex& other);

    // ���������� ��������� ��������� (� ������ ����������� ������)
    Complex operator-(const Complex& other);

    // ���������� ��������� �������� (� ������ ���� double)
    Complex operator+(const double& value);

    // ���������� ��������� �������� (� ������ ���� double) � ������ �������
    friend Complex operator+(const double& value, const Complex& c);

    // ���������� ��������� ��������� (� ������ ���� double)
    Complex operator-(const double& value);

    // ���������� ��������� ��������� (� ������ ���� double) � ������ �������
    friend Complex operator-(const double& value, const Complex& c);

    // ���������� ��������� ��������� (� ������ ����������� ������)
    Complex operator*(const Complex& other);

    // ���������� ��������� ��������� (� ������ ���� double)
    Complex operator*(const double& value);

    // ���������� ��������� ��������� (� ������ ���� double) � ������ �������
    friend Complex operator*(const double& value, const Complex& c);

    // ���������� ��������� ������� (�� ����� ���� double)
    Complex operator/(const double& value);

    // ���������� ��������� += (� ������ ����������� ������)
    Complex& operator+=(const Complex& other);

    // ���������� ��������� -= (� ������ ����������� ������)
    Complex& operator-=(const Complex& other);

    // ���������� ��������� *= (� ������ ����������� ������)
    Complex& operator*=(const Complex& other);

    // ���������� ��������� += (� ������ ���� double)
    Complex& operator+=(const double& value);

    // ���������� ��������� -= (� ������ ���� double)
    Complex& operator-=(const double& value);

    // ���������� ��������� *= (� ������ ���� double)
    Complex& operator*=(const double& value);

    // ���������� ��������� /= (� ������ ���� double)
    Complex& operator/=(const double& value);

    // ���������� ��������� ������������ (����������� ������������ �����)
    Complex& operator=(const Complex& other);

    // ���������� ��������� ������������ (������������ ����� ���� double)
    Complex& operator=(const double& value);
};

#endif // MY_COMPLEX_H
