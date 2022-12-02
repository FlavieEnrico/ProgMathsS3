#include <iostream>

#include "./include/Ratio.hpp"

int main(int argc, char const *argv[])
{
    Ratio myRatio, myORatio, mult;
    myRatio.Num(1);
    myRatio.Denom(2);
    myORatio.Num(2);
    myORatio.Denom(3);
    std::cout << myRatio.Num() << " ; " << myRatio.Denom() << std::endl;
    mult = myRatio*myORatio;
    std::cout << mult.Num() << " ; " << mult.Denom() << std::endl;
    return 0;
}
