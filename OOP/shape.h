#pragma once
#include <string>
#include <iostream>
using namespace std;

class shape{
    protected :
    string color;
    int id;
    
    public :
    shape()=default;
    
    shape ( const string & dupcolor , int dupid ):color(dupcolor),id(dupid){}
    
    virtual ~shape()=default;

    string type;

    //virtual functions
    virtual double area ()=0;
    virtual double perimeter ()=0;
    virtual void display ()=0;

    // Common methods
    string getcolor ();
    void setcolor ( const string & dupcolor );
    int getid ();

    //operator overload
    virtual shape& operator+=(double scalar) = 0;

};