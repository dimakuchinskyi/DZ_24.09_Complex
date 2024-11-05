#include <iostream>
using namespace std;

class Complex
{
    double _real;
    double _imaginary;

public:
    Complex() 
    {
        _real = 0;
        _imaginary = 0;
    } 
    Complex(double real) : Complex()
    {
        SetReal(real);
    }
    Complex(double real, double imaginary) : Complex(real)
    {
        SetImaginary(imaginary);
    }

    void SetReal(double real)
    {
        _real = real;
    }
    void SetImaginary(double imaginary) 
    {
        _imaginary = imaginary;
    }

    double GetReal() const 
    {
        return _real;
    }
    double GetImaginary() const 
    {
        return _imaginary;
    }

    void Print() const 
    {
        if (_imaginary >= 0)
            cout << "Complex: " << _real << " + " << _imaginary << "i" << endl;
        else
            cout << "Complex: " << _real << " - " << -_imaginary << "i" << endl;
    }

    Complex operator+(Complex& other) const 
    {
        return Complex(_real + other._real, _imaginary + other._imaginary);
    }

    Complex operator-(Complex& other) const 
    {
        return Complex(_real - other._real, _imaginary - other._imaginary);
    }

    Complex operator*(Complex& other) const 
    {
        double realPart = _real * other._real - _imaginary * other._imaginary;
        double imaginaryPart = _real * other._imaginary + _imaginary * other._real;
        return Complex(realPart, imaginaryPart);
    }

    Complex operator/(Complex& other) const 
    {
        double denominator = other._real * other._real + other._imaginary * other._imaginary;
        double realPart = (_real * other._real + _imaginary * other._imaginary) / denominator;
        double imaginaryPart = (_imaginary * other._real - _real * other._imaginary) / denominator;
        return Complex(realPart, imaginaryPart);
    }
};

int main() {
    Complex complex1(2, 3);
    Complex complex2(1, 4);
    Complex result;

    result = complex1 + complex2;
    cout << "Add result: ";
    result.Print();

    result = complex1 - complex2;
    cout << "Subtract result: ";
    result.Print();

    result = complex1 * complex2;
    cout << "Multiply result: ";
    result.Print();

    result = complex1 / complex2;
    cout << "Divide result: ";
    result.Print();

    return 0;
}
