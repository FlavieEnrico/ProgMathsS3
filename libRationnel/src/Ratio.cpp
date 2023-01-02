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


Ratio Ratio::operator-(const Ratio &r) const {
    Ratio result;
    int left, right;
    if (this->Denom()==r.Denom()) {
        result.Num(this->Num() - r.Num());
        result.Denom(this->Denom());
        return result.simplify();
    }
    left=this->Num()*r.Denom();
    right=this->Denom()*r.Num();
    result.Num(left-right);
    result.Denom(this->Denom()*r.Denom());
    return result.simplify();
}


Ratio Ratio::operator-() const {
    Ratio minus(-(this->Num()),this->Denom());
    return minus.simplify();
}


Ratio Ratio::operator*(const Ratio &r) const {
    Ratio mult(r.Num()*this->Num(),r.Denom()*this->Denom());
    return mult.simplify();
}

Ratio Ratio::operator*(const double &f) const {
    Ratio r = convert_float_to_ratio(f, 10);
    Ratio mult(r.Num()*this->Num(),r.Denom()*this->Denom());
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

Ratio Ratio::sqrt() const{
    Ratio sqrt_Num;
    Ratio sqrt_Denom;
    if(this->Num()>0){
    double sqrt_Num_d = std::sqrt(this->Num());
    sqrt_Num = convert_float_to_ratio(sqrt_Num_d,10);
    }
    else{
        std::cout << "On peut pas faire sqrt d'un négatif!" << std::endl;
    }
    double sqrt_Denom_d = std::sqrt(this->Denom());
    sqrt_Denom = convert_float_to_ratio(sqrt_Denom_d,10);
    Ratio sqrt = sqrt_Num/sqrt_Denom;
    return sqrt.simplify();
}

//Je propose de faire simple d'abord et de voir si on a le temps d'implémenter le triangle de Pascal
Ratio Ratio::cos() const{
    float num = this->Num();
    float denom = this->Denom();
    float cosarg = num/denom;
    //std::cout<< cosarg<<std::endl;
    //std::cout <<std::cos(cosarg) << std::endl;
    return convert_float_to_ratio(std::cos(cosarg),10).simplify();
}

Ratio Ratio::sin() const{
    float num = this->Num();
    float denom = this->Denom();
    float sinarg = num/denom;
    return convert_float_to_ratio(std::sin(sinarg),10).simplify();
}

Ratio Ratio::tan() const{
    return (this->sin()/this->cos()).simplify();
}

Ratio Ratio::pow(const int &exp) const{
    Ratio pow(std::pow(this->Num(),exp), std::pow(this->Denom(),exp));
    return pow;
}

Ratio Ratio::exp() const{
    float num = this->Num();
    float denom = this->Denom();
    float exposant = num/denom;
    //std::cout<< exposant<<std::endl;
    //std::cout <<std::exp(exposant) << std::endl;
    return convert_float_to_ratio(std::exp(exposant),10);
}

Ratio convert_float_to_ratio(const double &d, int nbIter){

    if (d==0) {
        return Ratio(0,1);
    }
    if (nbIter==0) {
         return Ratio(0,1);
    }
    if (d<1) {
        return (convert_float_to_ratio(1/d,nbIter)).inverse();
    }
    if(d>=1){
    const int q = floor(d);
    return Ratio(q,1)+convert_float_to_ratio(d-double(q), nbIter-1);
    }
    return Ratio(0,1);
}

Ratio Ratio::simplify() const {
    Ratio simple;
    int pgcd=std::gcd(std::abs(this->Num()), this->Denom());
    simple.Num(this->Num()/pgcd);
    simple.Denom(this->Denom()/pgcd);
    return simple;
}

std::ostream &operator<<(std::ostream &os, const Ratio &r) {
    os << r.Num() << " / " << r.Denom();
    return os;
}

Ratio operator*(const double value, const Ratio &r){
	return r * value;
}