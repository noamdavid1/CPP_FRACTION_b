
#include <iostream>
using namespace std;

namespace ariel
{
    class Fraction
    {
    private:
        int _numerator;
        int _denominator;

    public:
        Fraction();
        Fraction(float other);
        Fraction( int numer,  int denom);

        Fraction operator+(const Fraction &fraction);
        Fraction operator+(float other);
        friend Fraction operator+(float other, const Fraction &fraction);

        Fraction operator-(const Fraction &fraction);
        Fraction operator-(float other);
        friend Fraction operator-(float other, const Fraction &fraction);

        Fraction operator*(const Fraction &fraction);
        Fraction operator*(float other);
        friend Fraction operator*(float other, const Fraction &fraction);

        Fraction operator/(const Fraction &fraction);
        Fraction operator/(float other);
        friend Fraction operator/(float other, const Fraction &fraction);

        void reduction();

        bool operator==(const Fraction &fraction) const;
        bool operator==(float other);
        friend bool operator==(float other, const Fraction &fraction);

        bool operator>(const Fraction &fraction) const;
        bool operator>(float other);
        friend bool operator>(float other, const Fraction &fraction);

        bool operator<(const Fraction &fraction) const;
        bool operator<(float other);
        friend bool operator<(float other, const Fraction &fraction);

        bool operator<=(const Fraction &fraction) const;
        bool operator<=(float other);
        friend bool operator<=(float other, const Fraction &fraction);

        bool operator>=(const Fraction &fraction) const;
        bool operator>=(float other);
        friend bool operator>=(float other, const Fraction &fraction);

        Fraction operator++();
        Fraction operator++(int);
        Fraction operator--();
        Fraction operator--(int);

        friend ostream& operator<<(ostream &ostream_os, const Fraction &fraction);
        friend istream& operator>>(istream &istream_is, Fraction &fraction);

        int getNumerator() const;
        int getDenominator() const;
    };
}