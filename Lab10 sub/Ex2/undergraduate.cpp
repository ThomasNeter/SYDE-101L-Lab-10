#include "undergraduate.h"
#include <iostream>
#include <string>
using namespace std;

//creates array for student data
Undergraduate::Undergraduate() 
{
    for (int i=0 ; i < NUM_COURSES ; i ++)
        grades[i] = 0 ;
    s = UNDECIDED ;
}

//sets values for students
Undergraduate::Undergraduate( int const newcurrent_year, char const newterm) 
{
    set_currentyear(newcurrent_year) ;
    set_term(newterm) ;
    enter_grades() ;
    determine_status();   
}

//sets values for students
Undergraduate::Undergraduate(int const newgradyear, int const newcurrent_year, char const newterm ) : Student(newgradyear)
{
    set_currentyear(newcurrent_year) ;
    set_term( newterm) ;
    enter_grades() ;
    determine_status();
}

Undergraduate::Undergraduate(const string &newname, const int newid, const int newgradyear, int const newcurrent_year, char const newterm, const int day, const int month, const int year) : Student( newname, newid, newgradyear, day, month, year ) , date(day,month,year) , student(newgradyear)
{    
    set_currentyear(newcurrent_year) ;
    set_term( newterm) ;
    for (int i=0 ; i < NUM_COURSES ; i ++)
        grades[i] = 0 ;
    
    s = UNDECIDED ;
    stat = stat3 ;
}

Undergraduate::~Undergraduate()
{}

void Undergraduate::enter_grades ()
{
    for (int j = 0 ; j < NUM_COURSES ; j ++)
    {
        cout << "Enter the grade of course # " << j+1 << endl ;
        cin >> grades[j] ;
    }
}

void Undergraduate::print_grades () const
{
    for (int z = 0 ; z < NUM_COURSES ; z++)
        cout << grades[z] << "," ;
}

void Undergraduate::print() const
{
    Student::print() ;
    
    cout << "The grades are: " ;
    print_grades() ;
    cout<< endl ;
    cout << "The status is: " << get_status() << endl ;
    
    cout << "The Term is: " << get_term() << endl ;
    
    cout << "The current year is: " << get_currentyear() << endl ;
    
    cout << "The age at graduation is: " << age_at_convocation() << endl ;
}

void Undergraduate::determine_status()
{
    int gradeaverage = 0 ;
    
    for (int k = 0 ; k < NUM_COURSES ; k++)
        gradeaverage=gradeaverage+grades[k] ;
    
    if ( (double(gradeaverage)/NUM_COURSES) >= 50 )
    {s = PASS ;
    stat = stat1 ;
    }
    else
    { s = FAIL ;
        stat = stat2 ;
    }
}

string Undergraduate:: get_status() const
{
        return stat ;
}

int Undergraduate::get_currentyear() const
{
    return current_year ;
}
void Undergraduate::set_currentyear(  int const newcurrent_year)
{
    int  newnew_currentyear = newcurrent_year ;
    
    while (newnew_currentyear <1 || newnew_currentyear >4 )
    {
       cout << "Please Enter a valid current year (1,2,3,4)" << endl;
     cin >> newnew_currentyear ;
    }
    current_year = newnew_currentyear;
}

void Undergraduate::set_term(char const newterm )
{
    char newnewterm = newterm ;
    
   while ( newnewterm  != 'A' && newnewterm  != 'B' )
    {
       cout << "Please Enter a valid Term (A,B)" << endl;
        cin >> newnewterm ;
    }
    term = newnewterm ;
}

char Undergraduate::get_term() const 
{
    return term ;
}

int Undergraduate::age_at_convocation() const
{
    int finalday = 0;
    int finalmonth = 0;
    int finalyear = 0;
    
    finalday = GRAD_D - date.get_day()   ;
    finalmonth = GRAD_M - date.get_month() ;
    
    if(finalday<0)
        finalmonth-- ;
    
    finalyear = student.get_gradyear() - date.get_year() ;
    
    if(finalmonth<0)
        finalyear-- ;
    
    return finalyear ; 
}

























