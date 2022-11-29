#include <iostream>
#include <cmath>
#include <numeric>

#include "../include/Ratio.hpp"

// Constructors 

Ratio::Ratio() : num(), denom()
{
}

Ratio::Ratio(const Ratio &r) : num(r.num), denom(r.denom)
{
}

// Destructor 

Ratio::~Ratio()
{
}

// Operators 
/*
Ratio& operator=(const Ratio &ratio) {

}

Ratio operator+(const Ratio &r) const {
    
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

Ratio operator-(const Ratio &r) const {

}

Ratio operator-() const {

}

Ratio operator*(const Ratio &r) const {

}

Ratio operator/(const Ratio &r) const {

}

// Other operators : 

Ratio inverse(const Ratio &r) const {

}

Ratio abs(const Ratio &r) const {

}
*/
