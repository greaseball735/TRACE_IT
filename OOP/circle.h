//Circle
//#pragma once
#include <string>
#include <iostream>
#include "shape.h"
using namespace std;

class circle : public shape {
    private :
    double radius ;
    string type="Circle";

    public :
    circle ( const string & dupcolor , int dupid , double dupradius ){
        color=dupcolor;
        id=dupid;
        radius=dupradius;
    } ;
    virtual ~circle (){}

    //virtual functions
    double area () override{
        
        return (3.14)*radius*radius;
    
    }
    double perimeter () override {
        
        return 2*(3.14)*radius;
    
    }
    
    void display () override{
        cout<<" ID:"<<id<<" color:"<<color<<" type:"<<type<<" radius:"<<radius<<" Area:"<<area()<<" perimeter:"<<perimeter();
    }

    // circle - specific methods
    double getradius () {
        return radius;
    }

    void setradius ( double dupradius ){
        radius=dupradius;
    }

    double getdiameter (){
        return 2*radius;
    }  
    // Operator overloads
    circle& operator+=(double scalar) {
    radius += scalar;
    return *this;
    }
};