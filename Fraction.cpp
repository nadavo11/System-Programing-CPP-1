//
// Created by nadavo on 15/12/2021.
//
#include "Fraction.h"
#include <iostream>

using namespace std;
/*******************************    CLASS Fraction  ***********************************************/
/*******************************        Ctors       **********************************************/
//default Ctor
Fraction::Fraction(){}
//2 args Ctor
Fraction::Fraction(int mone,int mehane) {
    this->mone = mone;
    this->mehane = mehane;
    this->reduce();
}
/*******************************      Methods      **********************************************/
void Fraction::reduce(){
    int d =__gcd(mone,mehane);
    mone /= d;
    mehane /=d;
}
/******************************* `    Setters        **********************************************/
void Fraction::setNuminator(int nu) {
    this->mone = nu;
    this->reduce();
}

void Fraction::setDenominator(int de) {
    this->mehane = de;
    this->reduce();
}
/**************************************************/
Fraction Fraction::add(Fraction frac) {
    int me = this->mehane * frac.mehane;                            //here we implement 5th grade fraction addition
    int mo = this->mone * frac.mehane + this->mehane * frac.mone;

    return Fraction(mo,me);                           // and return a fraction accordingly.
}

bool Fraction::isEqual(Fraction frac) {
    if(this->mone == frac.mone && this->mehane ==frac.mehane) return true;
    return false;                                                   //there is equality if and only if both components are
    //of equal value
}

void Fraction::printVal() {
    cout<<"The value is:" << this->mone<<"/"<<this->mehane<<"\n";
}

Fraction::~Fraction() {

};

