#ifndef __RATIO__HPP
#define __RATIO__HPP

#include <iostream>

// Doxygen menu
/// \version 0.1
/// \mainpage
/// \image html myImage.jpg
/// \tableofcontents
/// \section instroduction_sec What for?
/// With this library is provided an awesome tool to easily experiment with rational numbers. Whether you simply want to play with sums or dive deep into maths with cosine and sine, it has it all ! 
/// \section install_bigsec How to install
/// \subsection dependencies_sec Dependencies
/// \li nothing
/// \li Doxygen (if you want the documentation)
/// \subsection install_sec Install with cmake (Linux / Mac)
/// \li go to main dir
/// \li mkdir build
/// \li cd build
/// \li cmake ..
/// \li make
/// \li if Doxygen installed: make html
/// \li The documentation is located in :
/// 	- [path to build]/doc/doc-doxygen/html/index.html or 
/// 	- or [path to build]/INTERFACE/doc/doc-doxygen/html/index.html



/// \class Ratio
/// \brief class defining a rational number for easy operations.
class Ratio
{
private:
    int m_num;
    unsigned int m_denom;
public:

    // Constructors and destructor



    /// \brief constructor from default constructor
    Ratio();

    /// \brief constructor from 2 values
	/// \param numValue : the value that's going to be attributed to the numerator of the rational number
	/// \param denomValue : the value that's going to be attributed to the denominator of the rational number
    Ratio(const int &numValue, const unsigned int &denomValue);

     /// \brief copy-constructor
	/// \param r : the rational number which values you want to copy to the new rational you are creating
    Ratio(const Ratio &r);

    /// \brief destructor
    ~Ratio();



    //Getters

    int Num() const {
        return m_num;
    }

    unsigned int Denom() const {
        return m_denom;
    }

    //Setters

    void Num(int value) {
        m_num = value;
    }

    void Denom(unsigned int value) {
        m_denom=value;
    }



    // Operators



    /// \brief overload of the = operator
	/// \param  ratio: the rational number which values are going to be assigned to an other one
	/// \return the rational number
    Ratio& operator=(const Ratio &ratio);

    /// \brief overload of the + operator
	/// \param  r: the second rational number to consider in the sum
	/// \return the rational number corresponding to the sum of the 2 others
    Ratio operator+(const Ratio &r) const;

    /// \brief overload of the - operator
	/// \param  r: the second rational number to consider in the substraction
	/// \return the rational number corresponding to the substraction of the argument rational and the current rational
    Ratio operator-(const Ratio &r) const;

    /// \brief unary minus
	/// \return the minus of the current rational
    Ratio operator-() const;

    /// \brief overload of the * operator
	/// \param  r: the second rational number to consider in the multiplication
	/// \return the rational number corresponding to the multiplication of the 2 others
    Ratio operator*(const Ratio &r) const;

    /// \brief second overload of the * operator
	/// \param  f: the float value to consider in the multiplication
	/// \return the rational number corresponding to the multiplication of the current rational and the float
    Ratio operator*(const double &f) const;

    /// \brief overload of the / operator
	/// \param  r: the second rational number to consider in the division
	/// \return the rational number corresponding to the division of the current rational by the the argument rational
    Ratio operator/(const Ratio &r) const;

    /// \brief overload of the += operator
	/// \param  r: the second rational number to consider in the operation
	/// \return the rational number corresponding to the sum of the two rationals
    Ratio& operator+=(const Ratio &r);

    /// \brief overload of the -= operator
	/// \param  r: the second rational number to consider in the operation
	/// \return the rational number corresponding to the substraction of the two rationals
    Ratio& operator-=(const Ratio &r);

    /// \brief overload of the *= operator
	/// \param  r: the second rational number to consider in the operation
	/// \return the rational number corresponding to the multiplication of the two rationals
    Ratio& operator*=(const Ratio &r);

    /// \brief overload of the /= operator
	/// \param  r: the second rational number to consider in the operation
	/// \return the rational number corresponding to the division of the two rationals
    Ratio& operator/=(const Ratio &r);




    //Other operations


    /// \brief convert the rational number into an approximated percentage
	/// \return the percentage as a rational
    Ratio convert_to_percentage();

    /// \brief return the reciproqual of the given rational
	/// \return the reciproqual
    Ratio inverse() const;

    /// \brief return the absolute value of the given rational
	/// \return the absolute value
    Ratio abs() const;

    /// \brief compute the square root of the given rational
	/// \return the square root value, as a rational number
    Ratio sqrt() const;

    /// \brief compute the cosine of the given rational
	/// \return the cosine value, as a rational number
    Ratio cos() const;

    /// \brief compute the sine of the given rational
	/// \return the sine value, as a rational number
    Ratio sin() const;

    /// \brief compute the tangent of the given rational
	/// \return the tangent value, as a rational number
    Ratio tan() const;

    /// \brief calculate the power of the given rational number
    /// \param  exp: a number, the exponent
	/// \return the power value
    Ratio pow(const int &exp) const;

    /// \brief calculate the exponential of the given rational number
	/// \return the exponential value
    Ratio exp() const;

    /// \brief calculate the e logarithm of the given rational number
	/// \return the log value
    Ratio logE() const;

    /// \brief calculate the 10 logarithm of the given rational number
	/// \return the log value
    Ratio log10() const;




    /// \brief return the given rational as a simplified rational
	/// \return the simplified rational
    Ratio simplify() const;


    /// \brief convert the rational into a float
	/// \return the given rational as a float
    float convert_ratio_to_float();
};

/// \brief overload the operator << for Ratio
/// \param stream : input stream
/// \param v : the rational number to output
/// \return the output stream containing the rational data
std::ostream& operator<< (std::ostream& stream, const Ratio& r);

/// \brief converting a float into a rational number
/// \param d : the float number you'd like to convert
/// \param nb_iter : the number of iterations
/// \return the converted rational
Ratio convert_float_to_ratio(const double &d, int nb_iter);

/// \brief multiply a float with a rational number
/// \param value : the float to consider in the multiplication
/// \param r : the rational number to multiply with
/// \return the result of the multiplication
Ratio operator*(const double value, const Ratio &r);

/// \brief overload of the == operator
/// \param  r1: the first rational number to compare
/// \param  r2: the second rational number to compare
/// \return whether the two rational numbers are equivalent or not
bool operator==(const Ratio & r1, const Ratio &r2);

/// \brief overload of the != operator
/// \param  r1: the first rational number to compare
/// \param  r2: the second rational number to compare
/// \return whether the two rational numbers are equivalent or not
bool operator!=(const Ratio & r1, const Ratio &r2);




//Comparison operators

/// \brief overload of the > operator
/// \param  r1: the first rational number to compare
/// \param  r2: the second rational number to compare
/// \return whether the argument rational is less than the current rational
bool operator>(const Ratio & r1, const Ratio &r2);

/// \brief overload of the < operator
/// \param  r1: the first rational number to compare
/// \param  r2: the second rational number to compare
/// \return whether the argument rational is greater than the current rational
bool operator<(const Ratio & r1, const Ratio &r2);

/// \brief overload of the <= operator
/// \param  r1: the first rational number to compare
/// \param  r2: the second rational number to compare
/// \return whether the argument rational is greater than or equal to the current rational
bool operator<=(const Ratio & r1, const Ratio &r2);

/// \brief overload of the >= operator
/// \param  r1: the first rational number to compare
/// \param  r2: the second rational number to compare
/// \return whether the argument rational is less than or equal to the current rational
bool operator>=(const Ratio & r1, const Ratio &r2);

#endif