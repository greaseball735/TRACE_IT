//Harikrishna S 240424
#include "shape.h"
#include "circle.h"
#include "rec.h"
#include "tri.h"
#include "squ.h"
#include "hxgn.h"
#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>//just to clear console screan.(system("cls"))
using namespace std;

//operator overloading for comparison
bool operator<=( shape& lhs,  shape& rhs) {
        return lhs.area() <= rhs.area();
}

//class performing the main functions using vector of shape pointer.
class shapecollect {
   public:
   void create(vector<shape*>& shapes){
      //to get choic of shape (sch)
      int sch;
      cout<<"1)Circle\n2)Square\n3)Triangle\n4)Rectangle\n5)Hexagon\nEnter choice: ";
      cin>>sch;
      switch(sch){
            case 1:
            {
            string color;
            int id;
            int radius;
            cout<<"Enter color:";
            cin>>color;
            cout<<"Enter id:";
            cin>>id;
            try{
            cout<<"Enter radius:";
            cin>>radius;
            }
            catch(...){
               cout<<"input vsalid number";
            }
            circle*c=new circle(color,id,radius);
            shapes.push_back(c);
            break;
            }
            case 2:
            {
            string color;
            int id;
            int side;
            cout<<"Enter color:";
            cin>>color;
            cout<<"Enter id:";
            cin>>id;
            try{
            cout<<"Enter side:";
            cin>>side;
            }
            catch(...){
               cout<<"input vsalid number";
            }
            squ*c=new squ(color,id,side);
            shapes.push_back(c);
            break;
            }
            
            case 3:
            {
            string color;
            int id;
            int side;
            cout<<"Enter color:";
            cin>>color;
            cout<<"Enter id:";
            cin>>id;

            try{
            cout<<"Enter side:";
            cin>>side;
            }
            catch(...){
               cout<<"input vsalid number";
            }
            tri*c=new tri(color,id,side);
            shapes.push_back(c);
            break;
            }
            
            case 4:
            {
            string color;
            int id;
            int length;
            int bredth;
            cout<<"Enter color:";
            cin>>color;
            cout<<"Enter id:";
            cin>>id;
            try{
            cout<<"Enter length:";
            cin>>length;
            cout<<"Enter bredth:";
            cin>>bredth;
            }
            catch(...){
               cout<<"input vsalid number";
            }
            rec*c=new rec(color,id,length,bredth);
            shapes.push_back(c);
            break;
            }
            
            case 5:
            {
            string color;
            int id;
            int side;
            cout<<"Enter color:";
            cin>>color;
            cout<<"Enter id:";
            cin>>id;
            try{
            cout<<"Enter side:";
            cin>>side;
            }
            catch(...){
               cout<<"input vsalid number";
            }
            hxgn*c=new hxgn(color,id,side);
            shapes.push_back(c);
            break;
            }
            
      }
   }
   // finds the largest area
   double larea(vector<shape*>& shapes){
      double la=0;
      for (int i = 0; i < shapes.size()-1; ++i) {
         if(*shapes[i]<=*shapes[i+1]){
            la=shapes[i+1]->area();
         }
         else{
            la=shapes[i]->area();
         }
      }
      return la;
   }
   //finds the total area of all shapes
   double tarea(vector<shape*>& shapes){
      double ta=0;
      for (int i = 0; i < shapes.size(); ++i) {
         ta+=shapes[i]->area();
      }
      return ta;
   }

   void access(vector<shape*>& shapes){
      
      for (int i= 0; i < shapes.size(); ++i) {
         cout<<i;
         shapes[i]->display();
      }
      cout<<" Enter ith shape required:";
      int i;
      cin>>i;
      //acceseing the information
      shapes[i]->display();

      //transformation
      int scalar;
      cout<<" Enter tranformationg scaler:";
      cin>>scalar;
      
      (*shapes[i])+=scalar;
   }
};

int main(){
   int ch=0;
   system("cls");
   cout<<"\n\n\t\t\t\tWelcome to Harikrishna's shape project\t\t\t\t\n\n";
   vector<shape*> shapes;
   shapecollect sc;

   while(ch!=5){
         
         cout<<"1)Create a shape\n2)largest area out of all shapes\n3)Total area of all shapes\n4)List shapes and access one\n5)exit\nEnter the choice :";
         cin>>ch;
         switch(ch){
            case 1:
            sc.create(shapes);
            break;
            case 2:
            cout<<sc.larea(shapes);
            break;
            case 3:
            cout<<sc.tarea(shapes);
            break;
            case 4:
            sc.access(shapes);
            break;
            
         }
   }
   cout<<"Thank you";
   return 0;
}