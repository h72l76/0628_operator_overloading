// file to demonstrate operator overloading 
// overloaded operators are 
// binary arithematic +, -, *, / 
// binary equaility comparison 

#include <iostream>

class Complex {
private:
    double _real{ 0.0 };
    double _image{ 0.0 };
public:
    Complex() = default;
    Complex(double real, double image = 0.0)
        : _real{ real }, _image{ image } {}

    // operator overloading, all as friend functions
    friend Complex operator + (const Complex& c1, const Complex& c2);
    friend Complex operator - (const Complex& c1, const Complex& c2);
    friend Complex operator * (const Complex& c1, const Complex& c2);
    friend Complex operator / (const Complex& c1, const Complex& c2);

    friend bool operator == (const Complex& c1, const Complex& c2);

    friend void print(const Complex& c); 
};


int main()
{
    Complex c1{ 20, -4 };
    Complex c2{ 3, 2 };

    print(c1 + c2);
    print(c1 - c2);
    print(c1 * c2);
    print(c1 / c2);

    std::cout << std::boolalpha << (c1 == c1) << std::endl;
    std::cout << std::boolalpha << (c1 == c2) << std::endl;
    return 0; 
}

Complex operator+(const Complex& c1, const Complex& c2)
{
    return Complex(c1._real + c2._real, c1._image + c2._image);
}

Complex operator-(const Complex& c1, const Complex& c2)
{
    return Complex(c1._real - c2._real, c1._image - c2._image);
}

Complex operator*(const Complex& c1, const Complex& c2)
{
    return Complex{
        c1._real * c2._real - c1._image * c2._image,
        c1._image * c2._real + c1._real * c2._image
    };
}

Complex operator/(const Complex& c1, const Complex& c2)
{
    if (c2._real == 0 && c2._image == 0) {
        std::cerr << "cannot divide zero. " << std::endl;
        exit(1);
    }

    auto conjugate = Complex{ c2._real, -1 * c2._image };
    auto numerator = c1 * conjugate;
    auto denominator = (conjugate * c2)._real;

    return Complex{ numerator._real / denominator,
                    numerator._image / denominator };
}

bool operator==(const Complex& c1, const Complex& c2)
{
    return c1._real == c2._real && c1._image == c2._image;
}

void print(const Complex& c) {
    std::cout << c._real << (c._image >= 0 ? "+" : "")
        << c._image << "i" << std::endl;
}
