#pragma once

#include <iostream>

class Ratio
{
private:
    /* data */
    int num;
    unsigned int denom;
public:
    // default constructor
    Ratio();

    //copy constructor
    Ratio(const Ratio &r);

    // destructor
    ~Ratio();

    void display() const;
    //Getters

    int getNum() {
        return num;
    }

    unsigned int getDenom() {
        return denom;
    }

    //Setters

    void setNum(const int value) {
        num = value;
    }

    void setDenom(const int value) {
        denom = value;
    }

    //Operators
    Ratio& operator=(const Ratio &ratio);
    Ratio operator+(const Ratio &r) const;
    Ratio operator-(const Ratio &r) const;
    Ratio operator-() const;
    Ratio operator*(const Ratio &r) const;
    Ratio operator/(const Ratio &r) const;

    Ratio inverse(const Ratio &r) const;
    Ratio abs(const Ratio &r) const;

};

std::ostream& operator<< (std::ostream& stream, const Ratio& r);