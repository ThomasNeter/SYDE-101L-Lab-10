//*********************************************
// Student Name: Thomas Neter
// Student Number: 20709080
//
// SYDE 121 Lab: 10 Assignment: 10 //
// Filename: RationalNumber.cpp
// Date submitted: December 4, 2017
// this code runs successfully.
//
// I hereby declare that this code, submitted
// for credit for the course SYDE121, is a product 
// of my own efforts. This coded solution has
// not been plagiarized from other sources and
// as not been knowingly plagiarized by others. 
//*********************************************
#include <iostream>
#include <fstream>
#include "RationalNumber.h"
using namespace std;

RationalNumber::RationalNumber()
{
    num = 0 ;
    den = 1 ;
}

RationalNumber::RationalNumber(const int n , const int d )
{
    num = n ;
    den = d ;
}

//Function for finding greatest common divisor
int RationalNumber::greatestCommonDivisor( int m, int n) 
{
    if(n == 0)
        return m;
    return greatestCommonDivisor(n, m % n);
}

//Function for reducing fractions
void RationalNumber::reduction() 

{
    int m = num ;
    int n = den ;
    
    num = num / greatestCommonDivisor( m, n) ;
    den = den / greatestCommonDivisor( m, n) ;
}

//All operator overloads
 istream& operator >> (istream& in ,  RationalNumber& x )
{
    in >> x.num >> x.den ;
    
    return in;
}

//Responsible for outputing rational number
ostream& operator << (ostream& out ,const  RationalNumber& x ) 
{
     if(x.den==0)
    {
        cout << "THE DENOMINATOR !=0 ERROR" << endl ;
        exit (1) ;
    }
    else if (x.num==0)
        out << 0 ;
    
    else if(x.den ==1)
        out<< x.num ;
    
    else if (x.den == x.num)
        out << 1 ;
        
    
    else
       out << x.num << "/" << x.den ;
    
   
    return out ;
}

RationalNumber operator+ (const RationalNumber& a , const RationalNumber& b)
{
    RationalNumber result ;
    
    result.num = ( a.num * b.den ) + ( b.num * a.den )  ;
    result.den = a.den * b.den ;
    
    result.reduction() ;
        
    return result ;
}

RationalNumber operator- (const RationalNumber& a , const RationalNumber& b)
{
    RationalNumber result ;
    
    result.num = ( a.num * b.den ) - ( b.num * a.den )  ;
    result.den = a.den * b.den ;
    
    result.reduction() ;
    
    return result ;
}

RationalNumber operator*(const RationalNumber& a , const RationalNumber& b)
{
    RationalNumber result ;
    
    result.num = a.num * b.num   ;
    result.den = a.den * b.den ;
    
    result.reduction() ;
    
    return result ;
}
RationalNumber operator/(const RationalNumber& a , const RationalNumber& b)
{
    RationalNumber result ;
    
    result.num = a.num * b.den   ;
    result.den = a.den * b.num;
    
    result.reduction() ;
    
    return result ;
}

//Overloads for inequality operators
bool operator<(const RationalNumber& a , const RationalNumber& b)
{
    return (double(a.num) / a.den ) < (double(b.num) / b.den) ;
}

bool operator>(const RationalNumber& a , const RationalNumber& b)
{
   return (double(a.num) / a.den ) > (double(b.num) / b.den) ;
}
bool operator<=(const RationalNumber& a , const RationalNumber& b)
{
    return (double(a.num) / a.den ) <= (double(b.num) / b.den) ;
}

bool operator>=(const RationalNumber& a , const RationalNumber& b)
{
    return (double(a.num) / a.den ) >= (double(b.num) / b.den) ;
}
bool operator==(const RationalNumber& a , const RationalNumber& b)
{
    return (double(a.num) / a.den ) == (double(b.num) / b.den) ;
}
bool operator!=(const RationalNumber& a , const RationalNumber& b)
{
    return (double(a.num) / a.den ) != (double(b.num) / b.den) ;
}









