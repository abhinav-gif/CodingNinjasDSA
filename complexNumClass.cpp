#include <iostream>
using namespace std;

class ComplexNumber
{
    int real, imaginary;

public:
    ComplexNumber(int real, int imaginary)
    {
        this->real = real;
        this->imaginary = imaginary;
    }
    void add(ComplexNumber const &c)
    {
        this->real = this->real + c.real;
        this->imaginary += c.imaginary;
    }
    void print()
    {
        cout << this->real << " + i" << this->imaginary << endl;
    }
    void multiply(ComplexNumber const &c)
    {
        int real = (this->real * c.real) - (this->imaginary * c.imaginary);
        int imaginary = (this->real * c.imaginary) + (this->imaginary * c.real);
        this->real = real;
        this->imaginary = imaginary;
    }
};

int main()
{
    int r1, i1;
    cin >> r1 >> i1;
    ComplexNumber c1(r1, i1);
    int r2, i2;
    cin >> r2 >> i2;
    ComplexNumber c2(r2, i2);
    int choice;
    cin >> choice;
    if (choice == 1)
    {
        c1.add(c2);
        c1.print();
    }
    else if (choice == 2)
    {
        c1.multiply(c2);
        c1.print();
    }
    else
    {
        return -1;
    }
}