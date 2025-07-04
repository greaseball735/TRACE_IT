//Redular Hexagon
#pragma once
#include <string>
#include <iostream>
#include "shape.h"
using namespace std;



class hxgn : public shape {
    private :
    double side ;
    string type="hexagon";

    public :
    hxgn ( const string & dupcolor , int dupid , double dupside ){
        color=dupcolor;
        id=dupid;
        side=dupside;
    } ;
    virtual ~hxgn (){}

    //virtual functions
    double area ()override{
        
        return (2.6)*side*side;
    
    }
    double perimeter () override {
        
        return 6*side;
    
    }
    
    void display () override{
        cout<<" ID:"<<id<<" color:"<<color<<" type:"<<type<<" side:"<<side<<" Area:"<<area()<<" perimeter:"<<perimeter();
    }

    // hxgn - specific methods
    double getside () {
        return side;
    }

    void setside ( double dupside ){
        side=dupside;
    }

    
    // Operator overloads
    hxgn & operator +=( double scalar ) {
        side+=scalar;
        return *this;
    }
    
};