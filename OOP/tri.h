//Equilateral Triangle
//#pragma once
#include <string>
#include <iostream>
#include "shape.h"
using namespace std;

class tri : public shape {
    private :
    double side ;
    string type="triangle";

    public :
    tri ( const string & dupcolor , int dupid , double dupside ){
        color=dupcolor;
        id=dupid;
        side=dupside;
    } ;
    virtual ~tri (){}

    //virtual functions
    double area ()override{
        
        return (0.433)*side*side;
    
    }
    double perimeter () override{
        
        return 3*side;
    
    }
    
    void display () override{
        cout<<" ID:"<<id<<" color:"<<color<<" type:"<<type<<" side:"<<side<<" Area:"<<area()<<" perimeter:"<<perimeter();
    }

    // tri - specific methods
    double getside () {
        return side;
    }

    void setside ( double dupside ){
        side=dupside;
    }

    
    // Operator overloads
    tri & operator +=( double scalar ) {
        side+=scalar;
        return *this;
    }
};