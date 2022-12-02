#pragma once

#include <iostream>

class Ratio
{
private:
    /* data */
    int num_;
    unsigned int denom_;
public:
    // default constructor
    Ratio();

    //copy constructor
    Ratio(const Ratio &r);

    // destructor
    ~Ratio();

    void display() const;

    //Getters

    int Num() const {
        return num_;
    }

    unsigned int Denom() const {
        return denom_;
    }

    //Setters

    void Num(int value) {
        num_ = value;
    }

    void Denom(unsigned int value) {
        denom_=value;
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