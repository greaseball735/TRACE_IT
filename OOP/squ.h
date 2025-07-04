//Square
//#pragma once
#include <string>
#include <iostream>
#include "shape.h"
using namespace std;


class squ : public shape {
    private :
    double side ;
    string type="square";

    public :
    squ ( const string & dupcolor , int dupid , double dupside ){
        color=dupcolor;
        id=dupid;
        side=dupside;
    } ;
    virtual ~squ (){}

    //virtual functions
    double area ()override{
        
        return side*side;
    
    }
    double perimeter () override{
        
        return 4*side;
    
    }
    
    void display () override{
        cout<<" ID:"<<id<<" color:"<<color<<" type:"<<type<<" side:"<<side<<" Area:"<<area()<<" perimeter:"<<perimeter();
    }

    // squ - specific methods
    double getside () {
        return side;
    }

    void setside ( double dupside ){
        side=dupside;
    }

    
    // Operator overloads
    squ & operator +=( double scalar ) {
        side+=scalar;
        return *this;
    }
    
};