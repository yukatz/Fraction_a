#include "Fraction.hpp"


namespace ariel
{
    Fraction::Fraction() {}
    Fraction::Fraction(int n, int d)
    {
        if (d == 0)
            __throw_invalid_argument("Can't divide by 0");
        else
        {
            numerator = n;
            denominator = d;
        }
    }

    int Fraction::getNum(){
        return numerator;
    }

    int Fraction::getDenom(){
        return denominator;
    }

    void Fraction::setNum(int n){
        numerator = n;
    }
    void Fraction::setDenom(int n){
        denominator = n;
    }

    Fraction Fraction::operator+(const Fraction &other) const
    {
        int common_denominator = lcm(denominator, other.denominator);
        int new_numerator = numerator * (common_denominator / denominator) + other.numerator * (common_denominator / other.denominator);
        return Fraction(new_numerator, common_denominator);
    }

    Fraction Fraction::operator-(const Fraction &other) const
    {
        int common_denominator = lcm(denominator, other.denominator);
        int new_numerator = numerator * (common_denominator / denominator) - other.numerator * (common_denominator / other.denominator);
        return Fraction(new_numerator, common_denominator);
    }

    Fraction Fraction::operator*(const Fraction &other) const
    {
        int new_numerator = numerator * other.numerator;
        int new_denominator = denominator * other.denominator;
        return Fraction(new_numerator, new_denominator);
    }

    Fraction Fraction::operator/(const Fraction &other) const
    {
        if (other.denominator==0 && other.numerator==0) __throw_invalid_argument("Can't divide by 0");
        else{
        int new_numerator = numerator * other.denominator;
        int new_denominator = denominator * other.numerator;
        return Fraction(new_numerator, new_denominator);
        }
    }

// Fraction VS Number
        Fraction Fraction::operator+(double number) const{
            return Fraction();
        }
        Fraction Fraction::operator-(double number) const{
            return Fraction();
        }
        Fraction Fraction::operator*(double number) const{
            return Fraction();
        }
        Fraction Fraction::operator/(double number) const{
             if (number == 0)
            __throw_invalid_argument("Can't divide by 0");
            else
            return Fraction();
        }

        // Number VS Fraction
        Fraction operator+(double number, const Fraction &other){
            return Fraction();
        }
        Fraction operator-(double number, const Fraction &other){
            return Fraction();
        }
        Fraction operator*(double number, const Fraction &other){
            return Fraction();
        }
        Fraction operator/(double number, const Fraction &other){
            if (other.denominator==0 && other.numerator==0)
            __throw_invalid_argument("Can't divide by 0");
            else
            return Fraction();
        }

        // Overloading comperators ==,<,>,<=,>=
        // Fraction VS Fraction
        bool Fraction::operator==(const Fraction &other) const{
            return true;
        }
        bool Fraction::operator<(const Fraction &other) const{
            return true;
        }
        bool Fraction::operator>(const Fraction &other) const{
            return true;
        }
        bool Fraction::operator<=(const Fraction &other) const{
            return true;
        }
        bool Fraction::operator>=(const Fraction &other) const{
            return true;
        }

        // Fraction VS Number
        bool Fraction::operator==(double number) const{
                        return true;

        }
        bool Fraction::operator<(double number) const{
                        return true;

        }
        bool Fraction::operator>(double number) const{
                        return true;

        }
        bool Fraction::operator<=(double number) const{
                        return true;

        }
        bool Fraction::operator>=(double number) const{
                        return true;

        }

        // Number VS Fraction
        bool operator==(double number, const Fraction &other){
                        return true;

        }
        bool operator<(double number, const Fraction &other){
                        return true;

        }
        bool operator>(double number, const Fraction &other){
                        return true;

        }
        bool operator<=(double number, const Fraction &other){
                        return true;

        }
        bool operator>=(double number, const Fraction &other){
                        return true;

        }

        // Fraction ++/--
        Fraction &Fraction::operator++(int number){
            return *this;
        }
        Fraction &Fraction::operator--(int number){
            return *this;
        }

        //++/--Fraction
        Fraction Fraction::operator--(){
                        return Fraction();

        }
        Fraction Fraction::operator++(){
                        return Fraction();

        }

        // Consule In & Consule Out
        ostream &operator<<(ostream &os, const Fraction &f){
            return os;
        }
        istream &operator>>(istream &is, Fraction &f){
          is >> f.numerator>>f.denominator;
           return is;
        }

    int Fraction::gcd(int a, int b) const
    {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }
    int Fraction::lcm(int a, int b) const
    {
        return (a * b) / gcd(a, b);
    }



}