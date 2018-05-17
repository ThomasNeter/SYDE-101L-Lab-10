#ifndef undergraduate_h
#define undergraduate_h
#include "student.h"
#include <cstring>
class Undergraduate : public Student
{
private:
    
    static const int NUM_COURSES = 5;
    const int GRAD_M = 5;
    const int GRAD_D = 15;

    int grades[NUM_COURSES] ;
    enum status {PASS,FAIL,UNDECIDED} ;
    status s = UNDECIDED ;
// Made strings to return status because enums return numbers.
    string stat1 = "PASS"; 
    string stat2 = "FAIL" ;
    string stat3 = "UNDECIDED" ;
    string stat;
    Date date ;
    Student student ;
    int current_year;
    char term ;
    
public:
    
    Undergraduate() ;
    Undergraduate(int  const current_year, char const term);
    Undergraduate(int const gradyear, int  const current_year, char const term ) ;
    Undergraduate(const string &newname, const int newid, const int newgradyear, int constcurrent_year, char const term , const int day, const int month, const int year  ) ;
    ~Undergraduate() ;
    
    void enter_grades () ;
    void print_grades () const ;
    void print() const ;
    void determine_status () ;
    string get_status() const ;
    int get_currentyear() const ;
    void set_currentyear(const int current_year) ;
    char get_term() const;
    void set_term(const char term ) ;
    int age_at_convocation() const ;    
};
#endif

