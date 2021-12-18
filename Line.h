//
// Created by nadavo on 10/12/2021.
//
/*******************************    CLASS Line  ***********************************************/

/*******************************    HEADERS   ***********************************************/
#include <cmath>
#include <iostream>
#ifndef CP_3_LINE_H
#define CP_3_LINE_H
/********************************************************************************************/


class Line{


/*******************************    private fields  ***********************************************/
    double x1;
    double y1;
    double x2;
    double y2;
/*******************************    public  methods  ***********************************************/
public:

    void setLine(double x1, double y1, double x2, double y2);

    void printLine();

    double getLen();

/*******************************    Constructors  ***********************************************/
    //default constructor override
    Line();
    Line(double x1, double y1, double x2, double y2);   // 4 argumrnts constructor
/*******************************        Dtors       **********************************************/
    ~Line();
};
#endif //CP_3_LINE_H
