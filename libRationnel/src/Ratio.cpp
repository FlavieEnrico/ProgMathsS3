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

/*
Ratio Ratio::operator/(const Ratio &r) const {

}

// Other operators : 

Ratio inverse(const Ratio &r) const {

}

Ratio abs(const Ratio &r) const {

}
*/
