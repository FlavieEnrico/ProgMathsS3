#include <iostream>
#include <cmath>
#include <numeric>

#include "../include/Ratio.hpp"

// Constructors 

Ratio::Ratio() : m_num(), m_denom()
{    
}

Ratio::Ratio(const int &numValue, const unsigned int &denomValue)
: m_num(numValue), m_denom(denomValue)
{
}

Ratio::Ratio(const Ratio &r) : m_num(r.m_num), m_denom(r.m_denom)
{
}

// Destructor 

Ratio::~Ratio()
{
}

// Operators 

Ratio &Ratio::operator=(const Ratio &ratio) {
    this->Num(ratio.Num());
    this->Denom(ratio.Denom());
    return *this;
}

Ratio Ratio::operator+(const Ratio &r) const {
    Ratio result;
    int left, right;
    if (this->Denom()==r.Denom()) {
        result.Num(this->Num()+r.Num());
        result.Denom(this->Denom());
        return result.simplify();
    }
    left=this->Num()*r.Denom();
    right=this->Denom()*r.Num();
    result.Num(left+right);
    result.Denom(this->Denom()*r.Denom());
    return result.simplify();
}

/*
Ratio Ratio::operator-(const Ratio &r) const {

}
*/

Ratio Ratio::operator-() const {
    Ratio minus;
    minus.Denom(this->Denom());
    minus.Num(-(this->Num()));
    return minus.simplify();
}


Ratio Ratio::operator*(const Ratio &r) const {
    Ratio mult;
    mult.Num(r.Num()*this->Num());
    mult.Denom(r.Denom()*this->Denom());
    return mult.simplify();
}


Ratio Ratio::operator/(const Ratio &r) const {
    return ((*this)*(r.inverse())).simplify();
}

//Comparison operators

bool Ratio::operator==(const Ratio &ratio) {
    this->simplify();
    ratio.simplify();
    if (this->Num()==ratio.Num() && this->Denom()==ratio.Denom()) {
        return true;
    }
    return false;
}

bool Ratio::operator!=(const Ratio &ratio) {
    this->simplify();
    ratio.simplify();
    if (this->Num()!=ratio.Num() || this->Denom()!=ratio.Denom()) {
        return true;
    }
    return false;
}

bool Ratio::operator>(const Ratio &ratio) {
    double d1,d2;
    d1=this->Num()/this->Denom();
    d2=ratio.Num()/ratio.Denom();
    if (d1>d2) {
        return true;
    }
    return false;
}

bool Ratio::operator<(const Ratio &ratio) {
    double d1,d2;
    d1=this->Num()/this->Denom();
    d2=ratio.Num()/ratio.Denom();
    if (d1<d2) {
        return true;
    }
    return false;

}

bool Ratio::operator<=(const Ratio &ratio) {
    double d1,d2;
    d1=this->Num()/this->Denom();
    d2=ratio.Num()/ratio.Denom();
    if (d1<=d2) {
        return true;
    }
    return false;
}

bool Ratio::operator>=(const Ratio &ratio) {
    double d1,d2;
    d1=this->Num()/this->Denom();
    d2=ratio.Num()/ratio.Denom();
    if (d1>=d2) {
        return true;
    }
    return false;
}

// Other operators : 

Ratio Ratio::inverse() const {
    Ratio inv;
    int a = this->Num();
    inv.Num(this->Denom());
    if (a<0) {
        inv.Num(-inv.Num());
        a=std::abs(a);
    }
    inv.Denom(a);
    return inv.simplify();
}

Ratio Ratio::abs() const {
    Ratio abs;
    abs.Num(this->Num());
    if (this->Num()<0) {
        abs.Num(-abs.Num());
    }
    abs.Denom(this->Denom());
    return abs.simplify();
}

/*Ratio Ratio::convert_float_to_ratio(const double &d, int nbIter) const {
    Ratio myRatio;
    if (d==0) {
        myRatio.Num(0);
        myRatio.Denom(1);
        return myRatio;
    }
    if (nbIter==0) {
        myRatio.Num(0);
        myRatio.Denom(1);
        return myRatio;
    }
    if (d<1) {
        return (convert_float_to_ratio(1/d,nbIter)).inverse();
    }
    Ratio q;
    q.Num(floor(d));
    q.Denom(1);
    return q+convert_float_to_ratio(d-q.Num(), nbIter-1);
}*/

Ratio Ratio::simplify() const {
    Ratio simple;
    int pgcd=std::gcd(this->Num(), this->Denom());
    simple.Num(this->Num()/pgcd);
    simple.Denom(this->Denom()/pgcd);
    return simple;
}

std::ostream &operator<<(std::ostream &os, const Ratio &r) {
    os << r.Num() << " / " << r.Denom();
    return os;
}