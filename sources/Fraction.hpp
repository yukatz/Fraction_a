#include <iostream>
#include <string>

using namespace std;

namespace ariel{
    
    class Fraction{
        private:
            int numerator;
            int denominator;
        public:
            Fraction();
            Fraction(int a, int b);

            string fractToString();

            Fraction operator+(const Fraction& other)const;
            Fraction operator-(const Fraction& other)const;
            Fraction operator/(const Fraction& other)const;
            Fraction operator*(const Fraction& other)const;

            int lcm(int a, int b)const;
            int gcd(int a, int b)const;






    };
};