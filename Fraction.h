//
// Created by nadavo on 11/12/2021.
//
/*******************************    CLASS Line  ***********************************************/

/*******************************    HEADERS   ***********************************************/
#include <cmath>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#ifndef CP_3_FRACTION_H
#define CP_3_FRACTION_H


class Fraction{
    /*******************************    private fields & methods ***********************************************/
    int mone;
    int mehane;

    void reduce();
/*******************************    public  methods  ***********************************************/
public:
    void setNuminator(int nu);
    void setDenominator(int de);
    Fraction add(Fraction frac);
    bool isEqual(Fraction frac);
    void printVal();


/*******************************    Constructors  ***********************************************/
    //default constructor override
    Fraction();
    Fraction(int mone, int mehane);   // 2 argumrnts constructor
/*******************************        Dtors       **********************************************/
    ~Fraction();
};


#endif //CP_3_FRACTION_H
