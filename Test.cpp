#include <stdexcept>
#include <sstream>
#include "doctest.h"
#include "sources/Fraction.hpp"

using namespace std;
using namespace ariel;

TEST_CASE("Fraction constructor")
{
    CHECK_NOTHROW(Fraction(3, 4));
    CHECK_NOTHROW(Fraction(0, 4));
    CHECK_THROWS(Fraction(4, 0));
}

TEST_CASE("Arithmetics functions test")
{
    Fraction a(3, 4), b(2, 3);
    CHECK_NOTHROW(a + b);
    CHECK_NOTHROW(a - b);
    CHECK_NOTHROW(a * b);
    CHECK_NOTHROW(a / b);
    b.setNum(0), b.setDenom(0);
    CHECK_THROWS(a / b);
    CHECK_NOTHROW(a + 2);
    CHECK_NOTHROW(a - 2);
    CHECK_NOTHROW(a * 2);
    CHECK_NOTHROW(a / 2);
    CHECK_THROWS(a / 0);
    //CHECK_NOTHROW(2 + a);
    //CHECK_NOTHROW(2 - a);
    //CHECK_NOTHROW(2 * a);
    //CHECK_NOTHROW(2 / a);
}

TEST_CASE("Compare operators")
{
    Fraction a(3, 4), b(2, 3);
    CHECK((a == b) == false);
    CHECK((a > b) == true);
    CHECK((a < b) == false);
    CHECK((a >= b) == true);
    CHECK((a <= b) == false);
    CHECK_NOTHROW(a == b);
    CHECK_NOTHROW(a > b);
    CHECK_NOTHROW(a < b);
    CHECK_NOTHROW(a >= b);
    CHECK_NOTHROW(a <= b);
}

TEST_CASE("Ptint functions test")
{
    Fraction a(3, 4), b(2, 3);
    ostringstream output;
    streambuf *old_cout = cout.rdbuf(output.rdbuf());

    cout << "a: " << a << "b: " << b << endl;

    cout.rdbuf(old_cout);
    CHECK(output.str() == "");
}