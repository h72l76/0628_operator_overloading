//// 0628_complex_numbers.cpp : This file contains the 'main' function. Program execution begins and ends there.
////
//
//#include <iostream>
//
//class Complex {
//private:
//    double _real{ 0.0 };
//    double _image{ 0.0 };
//public:
//    Complex() = default;
//    explicit Complex(double real, double image = 0.0)
//        : _real{ real }, _image{ image } {}
//    double getReal() const { return _real; }
//    double getImage() const { return _image; }
//    void setReal(double real) { _real = real; }
//    void setImage(double image) { _image = image; }
//
//    // friend functions have access to private members
//    friend Complex mul(const Complex& c1, const Complex& c2);
//    friend Complex div(const Complex& c1, const Complex& c2);
//
//    // operator overloading 
//    friend Complex operator + (const Complex& c1, const Complex& c2);
//    friend Complex operator - (const Complex& c1, const Complex& c2);
//
//    friend bool operator == (const Complex& c1, const Complex& c2);
//
//    // use member function to overload operators
//    // by default, the calling object will be passed to this operator 
//    // as the first operand
//    Complex operator * (const Complex& c);
//    Complex operator / (const Complex& c);
//
//
//    // overload + operator with Complex and int
//    friend Complex operator+ (const Complex& c, int i);
//
//};
//
//// independent functions that use getter/setters
//Complex add(const Complex& c1, const Complex& c2) {
//    auto real = c1.getReal() + c2.getReal();
//    auto image = c1.getImage() + c2.getImage();
//    Complex result = Complex{ real, image };
//    return result;
//}
//
//Complex sub(const Complex& c1, const Complex& c2) {
//    return Complex{ c1.getReal() - c2.getReal(),
//                        c1.getImage() - c2.getImage()
//    };
//}
//
//void print(const Complex& c) {
//    std::cout << c.getReal() << (c.getImage() >= 0 ? "+" : "")
//
//        << c.getImage() << "i" << std::endl;
//}
//
//int main()
//{
//    Complex c1{ 20, -4 };
//    Complex c2{ 3, 2 };
//
//    //print(add(c1, c2));
//    //print(sub(c1, c2));
//
//    // c1 + c1 + c2 + c2 ; 
//    auto result = add(add(add(c1, c1), c2), c2);
//    auto result_1 = c1 + c1 + c2 + c2;
//    auto result_1_1 = operator+ (c1, c2);
//
//    //auto result_2 = c1 + c2 * c3; 
//
//    auto result_3 = c1 - c2;
//    //print(result_3);
//
//    //c1 == c2; 
//
//    //print(10 * c2);
//    //print(c2 * Complex{ 10 });
//    //print(mul(c2, Complex{ 10 }));
//    //print(mul(Complex{ 10 }, c2));
//
//
//    //print(mul(c1, c2));
//    //print(c1 * c2);
//    //print(c1.operator*(c2));
//
//    //print(c1 + 10);
//
//    //print(div(c1, c2));
//
//    //print(div(c1, Complex{ 0,0 }));
//
//    print(div(c1, c2));
//    print(c1 / c2);
//
//}
//
//Complex mul(const Complex& c1, const Complex& c2)
//{
//    auto real = c1._real * c2._real - c1._image * c2._image;
//    auto image = c1._real * c2._image + c1._image * c2._real;
//
//    return Complex{ real, image };
//}
//
//Complex div(const Complex& c1, const Complex& c2)
//{
//    if (c2._real == 0.0 and c2._image == 0.0) {
//        std::cerr << "cannot divide zero" << std::endl;
//        exit(1);
//    }
//
//    auto conjugate = Complex{ c2._real, -1 * c2._image };
//    auto numerator = mul(c1, conjugate);
//    auto denominator = mul(c2, conjugate).getReal();
//
//    return Complex
//    { numerator._real / denominator,
//     numerator._image / denominator };
//}
//
//Complex operator+(const Complex& c1, const Complex& c2)
//{
//    return Complex(c1._real + c2._real, c1._image + c2._image);
//}
//
//Complex operator-(const Complex& c1, const Complex& c2)
//{
//    return Complex(c1._real - c2._real, c1._image - c2._image);
//}
//
//bool operator==(const Complex& c1, const Complex& c2)
//{
//    return c1._real == c2._real && c1._image == c2._image;
//}
//
//Complex operator+(const Complex& c, int i)
//{
//    return Complex(c._real + i, c._image);
//}
//
//Complex Complex::operator*(const Complex& c)
//{
//    return Complex{
//        _real * c._real - _image * c._image,
//        _image * c._real + _real * c._image
//    };
//}
//
//Complex Complex::operator/(const Complex& c)
//{
//    if (c._real == 0 && c._image == 0) {
//        std::cerr << "cannot divide zero. " << std::endl;
//        exit(1);
//    }
//
//    auto conjugate = Complex{ c._real, -1 * c._image };
//    auto numerator = Complex{ _real, _image } *conjugate;
//    auto denominator = (conjugate * c).getReal();
//
//    return Complex{ numerator._real / denominator,
//                    numerator._image / denominator
//    };
//
//    //return div(*this, c);
//}
