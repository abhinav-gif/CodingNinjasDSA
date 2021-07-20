#include <iostream>
#include <cmath>
using namespace std;

class Fraction
{
    int numerator;
    int denominator;

public:
    Fraction(int num, int denom)
    {
        numerator = num;
        denominator = denom;
    }

    void simplify()
    {
        int minimum = min(abs(numerator),abs(denominator));
        while (minimum > 0)
        {
            if (numerator % minimum == 0 && denominator % minimum == 0)
            {
                numerator = numerator / minimum;
                denominator = denominator / minimum;
                break;
            }
            minimum--;
        }
    }

    Fraction operator+(Fraction const & f2)
    {
        int n = (this->numerator * f2.denominator) + (f2.numerator * this->denominator);
        int d = this->denominator * f2.denominator;
        Fraction fnew(n, d);
        fnew.simplify();
        return fnew;
    }
     Fraction operator-(Fraction const & f2)
    {
        int n = (this->numerator * f2.denominator) - (f2.numerator * this->denominator);
        int d = this->denominator * f2.denominator;
        Fraction fnew(n, d);
        fnew.simplify();
        return fnew;
    }
    Fraction operator*(Fraction const & f2)
    {
       int n=this->numerator*f2.numerator;
       int d=this->denominator*f2.denominator;
        Fraction fnew(n, d);
        fnew.simplify();
        return fnew;
    }
    Fraction operator/(Fraction const & f2)
    {
         int n=this->numerator*f2.denominator;
       int d=this->denominator*f2.numerator;
        Fraction fnew(n, d);
        fnew.simplify();
        return fnew;
    }

    Fraction operator++(){
        int n=numerator+denominator;
        int d=denominator;
        this->numerator=this->numerator+this->denominator;
        this->simplify();
        Fraction fnew(n, d);
        fnew.simplify();
        return fnew;
    }
    Fraction operator++(int){
        int n=numerator;
        int d=denominator;
         Fraction fnew(n, d);
        fnew.simplify();
        this->numerator=this->numerator+this->denominator;
        this->simplify();
        return fnew;
    }

    void display()
    {
        cout << numerator << "/" << denominator << endl;
    }
};

int main()
{
    Fraction f1(1, 2);
    Fraction f2(6, 4);
    Fraction f3 = ++f1;
    f1.display();
    f2.display();
    f3.display();
}