//Rectangle
//#pragma once
#include <string>
#include <iostream>
#include "shape.h"
using namespace std;

class rec : public shape {
    private :
    double length;
    double bredth;
    string type="rec";

    public :
    rec ( const string & dupcolor , int dupid , double duplength ,double dupbredth){
        color=dupcolor;
        id=dupid;
        length=duplength;
        bredth=dupbredth;
    };
    virtual ~rec (){}

    //virtual functions
    double area () override{
        
        return bredth*length;
    
    }
    double perimeter () override{
        
        return 2*(bredth+length);
    
    }
    
    void display () override{
        cout<<" ID:"<<id<<" color:"<<color<<" type:"<<type<<" length:"<<length<<" Area:"<<area()<<" perimeter:"<<perimeter();
    }

    // rec - specific methods
    double getlength () {
        return length;
    }

    double getbredth () {
        return bredth;
    }

    void setbredth ( double dupbredth ){
        bredth=dupbredth;
    }

    void setlength ( double duplength ){
        length=duplength;
    }

    // Operator overloads
    rec & operator +=( double scalar ){
        length+=scalar;
        bredth+=scalar;
        return *this;
    }
};