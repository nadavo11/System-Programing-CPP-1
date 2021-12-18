//
// Created by nadavo on 15/12/2021.
//


/*******************************    includes  ***********************************************/
#include "Line.h"
#include <iostream>

using namespace std;
/*******************************    CLASS Line  ***********************************************/
// Default constructor
/*******************************        Ctors       **********************************************/
Line::Line() {};
Line::Line(double x1,double y1,double x2,double y2) {
    this->x1 = x1;
    this->y1 = y1;
    this->x2 = x2;
    this->y2 = y2;
};
/*******************************        Methods       **********************************************/
// Line member function
void Line::setLine(double x1,double y1,double x2,double y2){  //this function simply redifines object's fields according
    // to user's choice
    this->x1 = x1;
    this->y1 = y1;
    this->x2 = x2;
    this->y2 = y2;
}

double Line::getLen(){ //this function simply returns a double representing the cartesian distance betwen the two points
    // that define it.

    double deltaX = this->x2 - this->x1;
    double deltaY = this->y2 - this->y1;

    return sqrt(pow(deltaX,2) + pow(deltaY,2));
}

void Line:: printLine(){
    std::cout <<"("<< this->x1 << "," << this->y1 << ") --> (" <<"("<< this->x2 << "," << this->y2 << ")\n";
    std::cout <<"the length is: "<< this->getLen()<<"\n";
}
/*******************************        Dtors       **********************************************/
Line::~Line() {

}
