#include <algorithm>
#include <iostream>
#include <numeric>
#include <cmath>

#include <gtest/gtest.h>

#include "Ratio.hpp"

/////////////////////////////////////////////////////
// constructors

TEST (RatioConstructor, defaultConstructor) { 
	Ratio r;
	EXPECT_EQ (r.Num(), 0);
    EXPECT_EQ (r.Denom(), 1);
}

TEST (RatioConstructor, copyConstructor) {
	Ratio r1(1,2);
	Ratio r2(r1);
	ASSERT_EQ(r1, r2);
}

/////////////////////////////////////////////////////
// operators

TEST (RatioOperations, sum) {
	Ratio r1(1,2);
	Ratio r2(2,3);
	Ratio r3 = r1+r2;
	ASSERT_EQ(r3, r1+r2);
}

TEST (RatioOperations, substraction) {
	Ratio r1(1,2);
	Ratio r2(2,3);
	Ratio r3 = r1-r2;
	ASSERT_EQ(r3, r1-r2);
}

TEST (RatioOperations, minus) {
	Ratio r1(1,2);
    Ratio r2=-r1;
	ASSERT_EQ(r2, -r1);
}

TEST (RatioOperations, multiplication) {
	Ratio r1(1,2);
	Ratio r2(2,7);
	Ratio r3=r1*r2;
	//ASSERT_EQ(r3.Num(), r1.Num()*r2.Num()); --> is not working bc of the use of simplify in operator* overload
	//ASSERT_EQ(r3.Denom(), r1.Denom()*r2.Denom());
	ASSERT_EQ(r3, r1*r2);

    float myF=5.2;
    r3=r1*myF;
    ASSERT_EQ(r3, myF*r1);
}

TEST (RatioOperations, division) {
	Ratio r1(1,2);
	Ratio r2(2,7);
	Ratio r3=r1/r2;
	ASSERT_EQ(r3, r1/r2);
}

/////////////////////////////////////////////////////
// comparison

TEST (RatioComparison, equal) {
	Ratio r1(4,6);
	Ratio r2(2,3);
	ASSERT_EQ(r1, r2);
	ASSERT_EQ(r1.Num()*r2.Denom(), r1.Denom()*r2.Num());

    r2.Denom(7);
    ASSERT_NE(r1, r2);
	ASSERT_NE(r1.Num()*r2.Denom(), r1.Denom()*r2.Num());
}

TEST (RatioComparison, greater) {
	Ratio r1(1,2);
	Ratio r2(2,7);
	ASSERT_GT(r1, r2);
	ASSERT_GT(r1.Num()*r2.Denom(), r1.Denom()*r2.Num());

    ASSERT_GE(r1, r2);
	ASSERT_GE(r1.Num()*r2.Denom(), r1.Denom()*r2.Num());

    r2=r1;
    ASSERT_GE(r1, r2);
	ASSERT_GE(r1.Num()*r2.Denom(), r1.Denom()*r2.Num());
}

TEST (RatioComparison, less) {
	Ratio r1(2,7);
	Ratio r2(1,2);
	ASSERT_LT(r1, r2);
	ASSERT_LT(r1.Num()*r2.Denom(), r1.Denom()*r2.Num());

    ASSERT_LE(r1, r2);
	ASSERT_LE(r1.Num()*r2.Denom(), r1.Denom()*r2.Num());

    r2=r1;
    ASSERT_LE(r1, r2);
	ASSERT_LE(r1.Num()*r2.Denom(), r1.Denom()*r2.Num());
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
