#pragma once

#include <iostream>

class Ratio
{
private:
    int m_num;
    unsigned int m_denom;
public:
    // default constructor
    Ratio();

    //value constructor
    Ratio(const int &numValue, const unsigned int &denomValue);

    //copy constructor
    Ratio(const Ratio &r);

    // destructor
    ~Ratio();

    void display() const;

    //Getters

    int Num() const {
        return m_num;
    }

    unsigned int Denom() const {
        return m_denom;
    }

    //Setters

    void Num(int value) {
        m_num = value;
    }

    void Denom(unsigned int value) {
        m_denom=value;
    }

    //Operators
    Ratio& operator=(const Ratio &ratio);
    Ratio operator+(const Ratio &r) const;
    Ratio operator-(const Ratio &r) const;
    Ratio operator-() const;
    Ratio operator*(const Ratio &r) const;
    Ratio operator/(const Ratio &r) const;

    Ratio operator+=(const Ratio &r) const;
    Ratio operator-=(const Ratio &r) const;
    Ratio operator*=(const Ratio &r) const;
    Ratio operator/=(const Ratio &r) const;

    bool operator==(const Ratio &ratio);
    bool operator!=(const Ratio &ratio);
    bool operator>(const Ratio &ratio);
    bool operator<(const Ratio &ratio);
    bool operator<=(const Ratio &ratio);
    bool operator>=(const Ratio &ratio);

    Ratio inverse() const;
    Ratio abs() const;

  
    Ratio simplify() const;
};

std::ostream& operator<< (std::ostream& stream, const Ratio& r);
Ratio convert_float_to_ratio(const double &d, int nb_iter);