#include <iostream>

#include "./include/Ratio.hpp"

int main(int argc, char const *argv[])
{
    Ratio myRatio;
    myRatio.setNum(1);
    myRatio.setDenom(2);
    std::cout << myRatio.getNum() << " ; " << myRatio.getDenom() << std::endl;
    return 0;
}
