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

            int getNum();
            int getDenom();

            void setNum(int n);
            void setDenom(int n);

            string fractToString();

            Fraction operator+(const Fraction& other)const;
            Fraction operator-(const Fraction& other)const;
            Fraction operator/(const Fraction& other)const;
            Fraction operator*(const Fraction& other)const;

            bool operator==(const Fraction& other)const;
            bool operator<(const Fraction& other)const;
            bool operator>(const Fraction& other)const;
            bool operator<=(const Fraction& other)const;
            bool operator>=(const Fraction& other)const;

            Fraction& operator++(int);
            Fraction operator++();
            Fraction& operator--(int);
            Fraction operator--();

            Fraction operator+(int)const;
            Fraction operator-(int)const;
            Fraction operator*(double)const;
            Fraction operator/(int)const;

            Fraction& operator+(int);
            Fraction& operator-(int);
            Fraction& operator*(double);
            Fraction& operator/(int);


            bool operator==(int)const;
            bool operator<(int)const;
            bool operator>(int)const;
            bool operator<=(int)const;
            bool operator>=(int)const;


            friend ostream& operator<<(ostream& os, const Fraction& f);
            friend istream& operator>>(istream& is, Fraction& f);


            

            int lcm(int a, int b)const;
            int gcd(int a, int b)const;






    };
};