#include <iostream>
#include <numeric>
#include <algorithm>

#include "./include/Ratio.hpp"

int main()
{
    Ratio mult, inversed, div, absolute, unitMinus, minus, add, convert,sqrt,pow,exp;
    double testFloat=10.28;

    Ratio myRatio(1,2);
    Ratio myORatio(2,3);
    Ratio testEqual(1,2);
    
    std::cout << "Test cout : " << myRatio << std::endl;

    Ratio myCopyRatio(myORatio);
    std::cout << "Copy constructor : " << myCopyRatio << std::endl;

    mult = myRatio*myORatio;
    std::cout << "Test multiplication : " << mult << std::endl;

    inversed = myRatio.inverse();
    std::cout << "Test inverse : " << inversed << std::endl;

    div = myRatio/myORatio;
    std::cout << "Test division : " << div << std::endl;

    absolute = myRatio.abs();
    std::cout << "Test valeur absolue : " << absolute << std::endl;

    unitMinus = -myRatio;
    std::cout << "Test moins unaire : " << unitMinus << std::endl;

    add = myRatio+myORatio;
    std::cout << "Test addition : " << add << std::endl;

    minus = myRatio-myORatio;
    std::cout << "Test soustraction : " << minus << std::endl;

    sqrt = myRatio.sqrt();
    std::cout << "Test racine carré : " << sqrt << std::endl;

    pow = myRatio.pow(5);
    std::cout << "Test pow : " << pow << std::endl;

    exp = myRatio.exp();
    std::cout <<"Test exponentiel : " << exp << std::endl;

    /*testEqual*=myRatio;
    std::cout << testEqual << std::endl;*/

    //Comparison operators test

    if(add==mult) {
        std::cout << "c'est un mensonge" << std::endl;
    }

    if(add!=mult) {
        std::cout << "c'est la vérité" << std::endl;
    }

    if(add>mult) {
        std::cout << "c'est la vérité" << std::endl;
    }

    if(add<mult) {
        std::cout << "c'est un mensonge" << std::endl;
    }

    convert = convert_float_to_ratio(testFloat, 10);
    std::cout << convert.simplify() << std::endl;



    return 0;
}
