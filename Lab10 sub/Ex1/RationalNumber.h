#ifndef RationalNumber_h
#define RationalNumber_h

#include <fstream>
using namespace std ;
 class RationalNumber
{
    
public:
    
    RationalNumber() ;
    
    RationalNumber(const int n , const int d ) ;
    
    friend istream& operator >> (istream& in ,  RationalNumber& x ) ;
    
    friend ostream& operator << (ostream& out ,const  RationalNumber& x ) ;
    
    friend RationalNumber operator+ (const RationalNumber& a , const RationalNumber& b) ;
    
    friend RationalNumber operator-(const RationalNumber& a , const RationalNumber& b) ;
    
	friend RationalNumber operator*(const RationalNumber& a , const RationalNumber& b) ;
    
	friend RationalNumber operator/(const RationalNumber& a , const RationalNumber& b) ;
    
	friend bool operator<(const RationalNumber& a , const RationalNumber& b) ;
    
	friend bool operator>(const RationalNumber& a , const RationalNumber& b) ;
    
	friend bool operator<=(const RationalNumber& a , const RationalNumber& b) ;
    
	friend bool operator>=(const RationalNumber& a , const RationalNumber& b) ;
    
	friend bool operator==(const RationalNumber& a , const RationalNumber& b) ;
    
	friend bool operator!=(const RationalNumber& a , const RationalNumber& b) ;

        
private:
    
    int greatestCommonDivisor( int m, int n) ;
    void reduction() ;
    int num ;
    int den ;
    
    
};

#endif
