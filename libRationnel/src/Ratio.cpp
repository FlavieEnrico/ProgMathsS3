#include <iostream>
#include <cmath>
#include <numeric>

#include "../include/Ratio.hpp"

// Constructors 

Ratio::Ratio() : num_(), denom_()
{
}

Ratio::Ratio(const Ratio &r) : num_(r.num_), denom_(r.denom_)
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

/*
Ratio Ratio::operator+(const Ratio &r) const {
    
    if (this->getDenom()!=r.getDenom()) {
        // on évite d'écrabouiller les valeurs 
        this->setNum(this->getNum()*r.getDenom());
        this->setDenom(this->getDenom()*r.getDenom());
        r.setNum(this->getDenom()*r.getNum());
        r.setDenom(this->getDenom()*r.getDenom());
    }
    Ratio sum;
    sum.setNum(this->getNum()+r.getNum()); 
    sum.setDenom(this->getDenom());
    int pgcd = std::gcd(sum.getNum(),sum.getDenom());
    if (pgcd!=1) {
        sum.setNum((sum.getNum())/pgcd);
        sum.setDenom((sum.getDenom())/pgcd);
    }
    return sum;
}

Ratio Ratio::operator-(const Ratio &r) const {

}

Ratio Ratio::operator-() const {

}
*/

Ratio Ratio::operator*(const Ratio &r) const {
    Ratio mult;
    mult.Num(r.Num()*this->Num());
    mult.Denom(r.Denom()*this->Denom());
    return mult;
}


Ratio Ratio::operator/(const Ratio &r) const {
    Ratio r2=r.inverse();
    return *this*r2;
}

// Other operators : 

Ratio Ratio::inverse() const {
    Ratio inv;
    int a = this->Num();
    inv.Num(this->Denom());
    if (a<0) {
        inv.Num(-inv.Num());
        a=-a;
    }
    inv.Denom(a);
    return inv;
}

Ratio Ratio::abs() const {
    Ratio abs;
    abs.Num(this->Num());
    if (this->Num()<0) {
        abs.Num(-abs.Num());
    }
    abs.Denom(this->Denom());
    return abs;
}