// 0628_complex_numbers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class Complex {
private: 
    double _real{0.0}; 
    double _image{0.0}; 
public: 
    Complex() = default; 
    Complex(double real, double image = 0.0)
        : _real{ real }, _image{ image } {} 
    double getReal() const { return _real;  }
    double getImage() const { return _image;  }
    void setReal(double real) { _real = real;  }
    void setImage(double image) { _image = image;  }
};

// independent functions that use getter/setters
Complex add(const Complex& c1, const Complex& c2) {
    auto real = c1.getReal() + c2.getReal(); 
    auto image = c1.getImage() + c2.getImage(); 
    Complex result = Complex{ real, image }; 
    return result;
}

Complex sub(const Complex& c1, const Complex& c2) { 
    return Complex{ c1.getReal() - c2.getReal(),
                        c1.getImage() - c2.getImage()
    };
}

Complex mul(const Complex& c1, const Complex& c2)
{
    auto real = c1.getReal() * c2.getReal() - c1.getImage() * c2.getImage();
    auto image = c1.getReal() * c2.getImage() + c1.getImage() * c2.getReal();

    return Complex{ real, image };
}

Complex div(const Complex& c1, const Complex& c2)
{
    if (c2.getReal() == 0.0 and c2.getImage() == 0.0) {
        std::cerr << "cannot divide zero" << std::endl;
        exit(1);
    }

    auto conjugate = Complex{ c2.getReal(), -1 * c2.getImage() };
    auto numerator = mul(c1, conjugate);
    auto denominator = mul(c2, conjugate).getReal();

    return Complex
    { numerator.getReal() / denominator,
     numerator.getImage() / denominator };
}

void print(const Complex& c) {
    std::cout << c.getReal() << (c.getImage() >= 0? "+" : "")
        
        << c.getImage() << "i" << std::endl;
}

int main()
{
    Complex c1{20, -4}; 
    Complex c2{ 3, 2 }; 

    print(add(c1, c2));
    print(sub(c1, c2));
    print(mul(c1, c2));
    print(div(c1, c2));

    return 0;
}


