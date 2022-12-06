#include <iostream>
#include <numeric>
#include <algorithm>

#include "./include/Ratio.hpp"

int main()
{
    Ratio mult, inversed, div, absolute, minus, add, convert;
    //double testFloat=10.28;

    Ratio myRatio(1,2);
    Ratio myORatio(2,3);
    
    std::cout << myRatio << std::endl;

    Ratio myCopyRatio(myORatio);
    std::cout << "Copy constructor : " << myCopyRatio << std::endl;

    mult = myRatio*myORatio;
    std::cout << mult << std::endl;

    inversed = myRatio.inverse();
    std::cout << inversed << std::endl;

    div = myRatio/myORatio;
    std::cout << div << std::endl;

    absolute = myRatio.abs();
    std::cout << absolute << std::endl;

    minus = -myRatio;
    std::cout << minus << std::endl;

    add = myRatio+myORatio;
    std::cout << add << std::endl;

    /*convert.convert_float_to_ratio(testFloat, 7);
    std::cout << convert << std::endl;*/
    return 0;
}
