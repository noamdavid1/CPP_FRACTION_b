#include "Fraction.hpp"
#include <iostream>
#include <cmath>
#include <numeric>

namespace ariel
{
    Fraction::Fraction() : _numerator(1), _denominator(1) {} // default constructor.

    Fraction::Fraction(int numer, int denom) // initialization constructor.
    {
        if (denom == 0)
        {
            throw std::invalid_argument("denominator can not be 0!");
        }
        this->_numerator = numer;
        this->_denominator = denom;
        reduction();
        if (this->_denominator < 0)
        {
            this->_numerator = this->_numerator * (-1);
            this->_denominator = this->_denominator * (-1);
        }
    }
    Fraction::Fraction(float other)
    {
        int numer = other * 1000;
        int denom = 1000;
        this->_numerator = numer;
        this->_denominator = denom;
        reduction();
    }

    int Fraction::getNumerator() const
    {
        return this->_numerator;
    }
    int Fraction::getDenominator() const
    {
        return this->_denominator;
    }

    // The + operator to add two fractions and return their sum as another fraction in reduced form.
    Fraction Fraction::operator+(const Fraction &fraction)
    {
        int max_int = std::numeric_limits<int>::max();
        int min_int = std::numeric_limits<int>::min();
        if ((this->_numerator == min_int || this->_denominator == min_int) || (fraction._numerator == min_int || fraction._denominator == min_int))
        {
            throw std::overflow_error("overflow!");
        }
        if ((this->_numerator == max_int || this->_denominator == max_int) || (fraction._numerator == max_int || fraction._denominator == max_int))
        {
            throw std::overflow_error("overflow!");
        }
        long ans_numerator = long(this->_numerator * fraction._denominator) + (this->_denominator * fraction._numerator);
        long ans_denominator = long(this->_denominator * fraction._denominator);
        Fraction ans(ans_numerator, ans_denominator);

        return ans;
    }
    Fraction Fraction::operator+(float other)
    {
        Fraction f(other);
        return *this + f;
    }
    Fraction operator+(float other, const Fraction &fraction)
    {
        Fraction f(other);
        long ans_numerator = long(f._numerator * fraction._denominator) + (f._denominator * fraction._numerator);
        long ans_denominator = long(f._denominator * fraction._denominator);
        Fraction ans(ans_numerator, ans_denominator);
        return ans;
    }

    // The - operator to subtract two fractions and return their difference as another fraction in reduced form.
    Fraction Fraction::operator-(const Fraction &fraction)
    {
        int max_int = std::numeric_limits<int>::max();
        int min_int = std::numeric_limits<int>::min();
        if ((this->_numerator == min_int || this->_denominator == min_int) || (fraction._numerator == min_int || fraction._denominator == min_int))
        {
            throw std::overflow_error("overflow!");
        }
        if ((this->_numerator == max_int || this->_denominator == max_int) || (fraction._numerator == max_int || fraction._denominator == max_int))
        {
            throw std::overflow_error("overflow!");
        }
        long ans_numerator = long(this->_numerator * fraction._denominator) - (this->_denominator * fraction._numerator);
        long ans_denominator = long(this->_denominator * fraction._denominator);
        if (ans_numerator < min_int || ans_denominator < min_int || ans_denominator > max_int || ans_numerator > max_int)
        {
            throw std::overflow_error("overflow!");
        }
        // std::cout << "ans_num:" + std::to_string(ans_numerator) + ", ans_den:" + std::to_string(ans_denominator) << endl;
        Fraction ans(ans_numerator, ans_denominator);

        return ans;
    }
    Fraction Fraction::operator-(float other)
    {
        Fraction f(other);
        return *this - f;
    }
    Fraction operator-(float other, const Fraction &fraction)
    {
        Fraction f(other);
        long ans_numerator = long(f._numerator * fraction._denominator) - (f._denominator * fraction._numerator);
        long ans_denominator = long(f._denominator * fraction._denominator);
        Fraction ans(ans_numerator, ans_denominator);
        return ans;
    }

    // The * operator to multiply two fractions and return their product as another fraction in reduced form.
    Fraction Fraction::operator*(const Fraction &fraction)
    {
        int max_int = std::numeric_limits<int>::max();
        int min_int = std::numeric_limits<int>::min();

        if ((this->_numerator == min_int || this->_denominator == min_int) && (fraction._numerator == min_int || fraction._denominator == min_int))
        {
            throw std::overflow_error("overflow!");
        }
        if ((this->_numerator == max_int || this->_denominator == max_int) && (fraction._numerator == max_int || fraction._denominator == max_int))
        {
            throw std::overflow_error("overflow!");
        }
        long ans_numerator = long(this->_numerator * fraction._numerator);
        long ans_denominator = long(this->_denominator * fraction._denominator);
        Fraction ans(ans_numerator, ans_denominator);

        return ans;
    }
    Fraction Fraction::operator*(float other)
    {
        Fraction f(other);
        return *this * (f);
    }
    Fraction operator*(float other, const Fraction &fraction)
    {
        Fraction f(other);
        long ans_numerator = long(f._numerator * fraction._numerator);
        int ans_denominator = long(f._denominator * fraction._denominator);
        Fraction ans(ans_numerator, ans_denominator);
        return ans;
    }

    // The / operator to divide two fractions and return their quotient as another fraction in reduced form.
    Fraction Fraction::operator/(const Fraction &fraction)
    {
        int max_int = std::numeric_limits<int>::max();
        int min_int = std::numeric_limits<int>::min();

        if (fraction._numerator == 0)
        {
            throw runtime_error("there is no possibility to divide by 0!");
        }
        if ((this->_numerator == min_int || this->_denominator == min_int) && (fraction._numerator == min_int || fraction._denominator == min_int))
        {
            throw std::overflow_error("overflow!");
        }
        if ((this->_numerator == max_int || this->_denominator == max_int) && (fraction._numerator == max_int || fraction._denominator == max_int))
        {
            throw std::overflow_error("overflow!");
        }
        long ans_numerator = long(this->_numerator * fraction._denominator);
        long ans_denominator = long(this->_denominator * fraction._numerator);
        Fraction ans(ans_numerator, ans_denominator);

        return ans;
    }
    Fraction Fraction::operator/(float other)
    {
        Fraction f(other);
        return *this / f;
    }
    Fraction operator/(float other, const Fraction &fraction)
    {
        Fraction f(other);
        long ans_numerator = long(f._numerator * fraction._denominator);
        long ans_denominator = long(f._denominator * fraction._numerator);
        Fraction ans(ans_numerator, ans_denominator);
        return ans;
    }

    // The ++ and -- operator that adds (or substracts) 1 to the fraction. implement both pre and post fix.
    Fraction Fraction::operator++()
    {
        this->_numerator += this->_denominator;
        reduction();
        return *this;
    }
    Fraction Fraction::operator++(int)
    {
        Fraction temp(*this);
        this->_numerator += this->_denominator;
        return temp;
    }
    Fraction Fraction::operator--()
    {
        this->_numerator -= this->_denominator;
        reduction();
        return *this;
    }
    Fraction Fraction::operator--(int)
    {
        Fraction temp(*this);
        this->_numerator -= this->_denominator;
        return temp;
    }

    void Fraction::reduction() //fraction reduction function.
    {
        int gcd = std::__gcd(this->_numerator, this->_denominator); //the greater common divider.
        this->_numerator = this->_numerator / gcd;
        this->_denominator = this->_denominator / gcd;
    }

    // The == operator to compare two fractions for equality and return true or false.
    bool Fraction::operator==(const Fraction &fraction) const
    {
        float thisf = (float)this->_numerator / this->_denominator;
        float fracf = (float)fraction._numerator / fraction._denominator;
        return thisf == fracf;
    }
    bool Fraction::operator==(float other)
    {
        Fraction f(other);
        return *this == f;
    }
    bool operator==(float other, const Fraction &fraction)
    {
        Fraction f(other);
        Fraction temp(fraction);
        return f == temp;
    }

    // All comparison operations (>,<,>=,<=)
    bool Fraction::operator<=(const Fraction &other) const
    {
        float thisf = (float)this->_numerator / this->_denominator;
        float otherf = (float)other._numerator / other._denominator;
        return thisf <= otherf;
    }
    bool Fraction::operator<=(float other)
    {
        Fraction f(other);
        return *this <= f;
    }
    bool operator<=(float other, const Fraction &fraction)
    {
        Fraction f(other);
        return f <= fraction;
    }
    bool Fraction::operator>=(const Fraction &other) const
    {
        float thisf = (float)this->_numerator / this->_denominator;
        float otherf = (float)other._numerator / other._denominator;
        return thisf >= otherf;
    }
    bool Fraction::operator>=(float other)
    {
        Fraction f(other);
        return *this >= f;
    }
    bool operator>=(float other, const Fraction &fraction)
    {
        Fraction f(other);
        return f >= fraction;
    }
    bool Fraction::operator<(const Fraction &other) const
    {
        float thisf = (float)this->_numerator / this->_denominator;
        float otherf = (float)other._numerator / other._denominator;
        return thisf < otherf;
    }
    bool Fraction::operator<(float other)
    {
        Fraction f(other);
        return *this < (f);
    }
    bool operator<(float other, const Fraction &fraction)
    {
        Fraction f(other);
        return f < fraction;
    }
    bool Fraction::operator>(const Fraction &other) const
    {
        float thisf = (float)this->_numerator / this->_denominator;
        float otherf = (float)other._numerator / other._denominator;
        return thisf > otherf;
    }
    bool Fraction::operator>(float other)
    {
        Fraction f(other);
        return *this > (f);
    }
    bool operator>(float other, const Fraction &fraction)
    {
        Fraction f(other);
        return f > fraction;
    }

    // The << operator to print a fraction to an output stream in the format “numerator/denominator”.
    ostream &operator<<(ostream &ostream_os, const Fraction &fraction)
    {
        ostream_os << fraction.getNumerator() << "/" << fraction.getDenominator();
        return ostream_os;
    }
    // The >> operator to read a fraction from an input stream by taking two integers as input.
    istream &operator>>(istream &istream_is, Fraction &fraction)
    {
        int numerator, denominator;
        if (istream_is >> numerator >> denominator)
        {
            if (denominator == 0)
            {
                istream_is.setstate(std::ios::failbit);
                throw runtime_error("there is no possibility to divide by 0!");
            }
            else
            {
                if (denominator < 0)
                {
                    fraction._numerator = numerator * (-1);
                    fraction._denominator = denominator * (-1);
                }
                else
                {
                    fraction._numerator = numerator;
                    fraction._denominator = denominator;
                    fraction.reduction();
                }
            }
        }
        else
        {
            istream_is.setstate(std::ios::failbit);
            throw std::runtime_error("invaild input format!");
        }
        return istream_is;
    }

}