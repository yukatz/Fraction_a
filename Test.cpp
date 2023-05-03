#include <stdexcept>
#include <sstream>
#include "doctest.h"
#include "sources/Fraction.hpp"

using namespace std;
using namespace ariel;

TEST_CASE("Fraction constructor")
{
    CHECK_NOTHROW(Fraction(3, 4)); // Fraction constructor
    CHECK_NOTHROW(Fraction(0, 4));
    CHECK_THROWS(Fraction(4, 0));
    CHECK_EQ(Fraction(1.5), Fraction(3, 2)); // Fraction constructor from float
}

TEST_CASE("Arithmetics functions test")
{
    //////Throws tests////////
    Fraction a(3, 4), b(2, 3);
    CHECK_NOTHROW(a + b);
    CHECK_NOTHROW(a - b);
    CHECK_NOTHROW(a * b);
    b.setNum(0), b.setDenom(0);
    CHECK_THROWS(a / b);
    CHECK_NOTHROW(a + 2);
    CHECK_NOTHROW(a - 2);
    CHECK_NOTHROW(a * 2);
    CHECK_NOTHROW(a / 2);
    CHECK_THROWS(a / 0);
    CHECK_NOTHROW((2 + a));
    CHECK_NOTHROW((2 - a));
    CHECK_NOTHROW((2 * a));
    a.setNum(0), a.setDenom(0);
    CHECK_THROWS((2 / a));
    a.setNum(3), a.setDenom(4);
    b.setNum(2), b.setDenom(3);
    //////Value tests////////
    // Fraction VS Fraction
    CHECK_EQ((a + b), Fraction(17, 12));
    CHECK_EQ((a - b), Fraction(1, 12));
    CHECK_EQ((a * b), Fraction(6, 12));
    CHECK_EQ((a * b), Fraction(1, 2));
    CHECK_EQ((a / b), Fraction(9, 8));
    // Fraction VS Number
    CHECK_EQ((a + 2), Fraction(11, 4));
    CHECK_EQ((a - 2), Fraction(-5, 4));
    CHECK_EQ((a * 2), Fraction(6, 4));
    CHECK_EQ((a / 2), Fraction(3, 8));
    // Number VS Fraction
    CHECK_EQ((2 + a), Fraction(11, 4));
    CHECK_EQ((2 - a), Fraction(5, 4));
    CHECK_EQ((2 * a), Fraction(6, 12));
    CHECK_EQ((2 / a), Fraction(8, 3));
}

TEST_CASE("Compare operators")
{
    Fraction a(3, 4), b(2, 3);
    //////Value tests////////
    // Fraction VS Fraction
    CHECK((a == b) == false);
    CHECK((a > b) == true);
    CHECK((a < b) == false);
    CHECK((a >= b) == true);
    CHECK((a <= b) == false);
    a.setNum(2);
    CHECK((a == b) == false);
    CHECK((a > b) == false);
    CHECK((a < b) == true);
    CHECK((a >= b) == false);
    CHECK((a <= b) == true);
    b.setDenom(4);
    CHECK((a == b) == true);
    a.setNum(8);
    CHECK((b.getNum() == a) == true);
    CHECK((b < a.getNum()) == true);
    Fraction c(4, 8), d(100, 200);
    CHECK((c == d) == true);
    // Fraction VS Number
    Fraction f(1, 2);
    CHECK((f == 3) == false);
    CHECK((f > 0.25) == true);
    CHECK((f < 1) == false);
    CHECK((f >= 0.5) == true);
    CHECK((f <= 0.55) == false);

    // Number VS Fraction
    Fraction ff(5, 10);
    CHECK((3 == f) == false);
    CHECK((0.25 > f) == true);
    CHECK((1 < f) == false);
    CHECK((0.5 >= f) == true);
    CHECK((0.55 <= f) == false);

    /////4'th digit////
    Fraction aa(0.333), bb(0.3334);
    CHECK((a == b) == true);
}

TEST_CASE("Countup and countdownd operators")
{

    Fraction a(2, 1);
    CHECK_EQ((a++), Fraction(3, 1));
    CHECK_EQ((a--), Fraction(1, 1));
    CHECK_EQ((++a), Fraction(3, 1));
    CHECK_EQ((--a), Fraction(1, 1));

    CHECK_NOTHROW((a++));
    CHECK_NOTHROW((a--));
    CHECK_NOTHROW((++a));
    CHECK_NOTHROW((--a));
}

TEST_CASE("sout and sin cases")
{

    // Control out
    Fraction a(1, 2);
    stringstream ss;
    ss << a;
    string output = ss.str();
    CHECK(output == "1/2");
    // Control in
    Fraction b;
    stringstream ss1("1/2");
    ss1 >> b;
    CHECK(b == Fraction(3, 4));

    CHECK_NOTHROW(ss << a);
    stringstream ss2("1");
    CHECK_THROWS(ss2 >> a);
}
