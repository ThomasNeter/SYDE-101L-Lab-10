//********************************************* 
// Student Name: Thomas Neter
// Student Number: 20709080
//
// SYDE 121 Lab: 10 Assignment: 10 //
// Filename: main.cpp
// Date submitted: December 4, 2017
//
// I hereby declare that this code, submitted
// for credit for the course SYDE121, is a product 
// of my own efforts. This coded solution has
// not been plagiarized from other sources and
// as not been knowingly plagiarized by others. 
//*********************************************

// this code does not run succesffully due to non-static data member error

#include "person.h"
#include "student.h"
#include "undergraduate.h"
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    {
        Undergraduate under("THOMAS", 20709080, 2022, 6 , 'c', 23 , 8, 1999) ; //an object that contains all details with invalid input
    
        under.enter_grades();
        under.determine_status();
        under.print();        
    }
    
    system("pause");
    return 0;
}
