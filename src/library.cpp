#include "library.hpp"
#include <cmath>
#include <stdexcept>

namespace template_library {

    // Конструкторы
    Complex::Complex() : m_real(0.0), m_imag(0.0) {}
    Complex::Complex(double real, double imag) : m_real(real), m_imag(imag) {}

    // real возвращает действительную часть, imag мнимую
    double Complex::real() const { return m_real; }
    double Complex::imag() const { return m_imag; }

    // Арифметические операции
    Complex Complex::operator+(const Complex& other) const {
        return Complex(m_real + other.m_real, m_imag + other.m_imag);
    }

    Complex Complex::operator-(const Complex& other) const {
        return Complex(m_real - other.m_real, m_imag - other.m_imag);
    }

    Complex Complex::operator*(const Complex& other) const {
        return Complex(
            m_real * other.m_real - m_imag * other.m_imag,
            m_real * other.m_imag + m_imag * other.m_real
        );
    }

    Complex Complex::operator/(const Complex& other) const {
        double denominator = other.m_real * other.m_real + other.m_imag * other.m_imag;
        if (denominator == 0) {
            throw std::runtime_error("Division by zero"); // обработка ошибок
        }
        return Complex(
            (m_real * other.m_real + m_imag * other.m_imag) / denominator,
            (m_imag * other.m_real - m_real * other.m_imag) / denominator
        );
    }

    // Умножение на скаляр (реализация дружественных функций)
    Complex operator*(double m, const Complex& other) {
        return Complex(m * other.m_real, m * other.m_imag);
    }

    Complex operator*(const Complex& other, double m) {
        return Complex(m * other.m_real, m * other.m_imag);
    }

    // Операторы ввода/вывода
    std::ostream& operator<<(std::ostream& os, const Complex& c) {
        if (c.m_imag == 0) {
            os << c.m_real << ".0";  // Всегда добавляем .0 для нулевой мнимой части
        }
        else {
            os << c.m_real << (c.m_imag >= 0 ? " + " : " - ") << std::abs(c.m_imag) << "i";
        }
        return os;
    }

    std::istream& operator>>(std::istream& is, Complex& c) {
        is >> c.m_real >> c.m_imag;
        return is;
    }

} 