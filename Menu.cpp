
//
// Created by nadavo on 15/12/2021.
//
/*****************************      includes    ***********************************************/
#include "Menu.h"
#include "Line.h"
#include "Fraction.h"
#include "Clock.h"
#include <iostream>

using namespace std;

/********************************** ALIASES ************************************/ // TODO Add aliases
#define ILLEGAL "illegal choice"                                     // Maximum input length
/********************************** PROTOTYPES ***********************************************/
void sortLines(Line sortedLines[3]);
/*******************************    CLASS Menu  ***********************************************/
Menu::Menu() {
    this->mainMenu();
}
void Menu:: mainMenu() {
    int chs;
    int Q = 1;
    while (Q) {
        std::cout <<"(1) - line menu\n(2) - fraction menu\n(3) - clock menu\n(4) - exit\n";

        cin >> chs ;
        switch (chs) {
            case 1:
                lineMenu();
                break;
            case 2:
                Menu::fractionMenu();
                break;
            case 3:
                Menu::clockMenu();
                break;
            case 4:
                Q = 0;
                cout <<"Goodbye!" ;
                break;
            default:
                cout << ILLEGAL;
        }
    }
}


void Menu:: lineMenu(){
    double x1,y1,x2,y2;  //we will ask for these for each line
    Line lines[3];       //here we will store 3 lines
    Line sortedLines[3];

    for(int i = 0; i<=2; i++){              //we ask for 3 lines from the user
        cout<<"Enter the first point of Line "<< i+1<<":\n";
        cin >> x1;
        cin >> y1;

        cout<<"Enter the second point of Line "<< i+1<<":\n";
        cin >> x2;
        cin >> y2;


        lines[i].setLine(x1,y1,x2,y2);
    }

    for(int i = 0; i<3 ; i++){
        sortedLines[i] = lines[i];
    }

    int chs;
    int q = 1;
    while (q) {

        cout
                << "<1> To view first Line coordinates and length.\n"
                << "<2> To view second Line coordinates and length.\n"
                << "<3> To view third Line coordinates and length.\n"
                << "<4> To print line order by length\n"
                << "<5> To exit\n";
        cin >> chs; // Get user input from the keyboard
        switch (chs) {
            case 1:
                std::cout <<"the coordinate of line 1:\n";
                lines[0].printLine();
                break;
            case 2:
                std::cout <<"the coordinate of line 2:\n";
                lines[1].printLine();
                break;
            case 3:
                std::cout <<"the coordinate of line 3:\n";
                lines[2].printLine();
                break;
            case 4: {
                sortLines(sortedLines);


            }
                break;
            case 5:
                q = 0;
                break;
            default:
                cout << "ME WANT VALID INPUT!";
        }
    }
}

void Menu::fractionMenu() {
    int mo,me;  //we will ask for these for each frac
    Fraction fractions[2];       //here we will store the 2 fracs

    for(int i = 0; i<=1; i++){              //we ask for 2 fracs from the user
        if(i==1)
            cout<<"Set the second fraction: \n";
        else
            cout<<"Set the first fraction: \n";
        cout<<"Numerator: \n";
        cin>> mo;
        cout<<"Denominator: \n";
        cin>> me;

        fractions[i] = Fraction(mo,me);

    }
    int chs;
    int q = 1;
    while (q) {

        cout << "<1> calculate sum of f1 and f2.\n<2> is equal?.\n<3> print first fraction.\n<4> print second fraction.\n<5> exit.\n";
        cin >> chs; // Get user input from the keyboard
        switch (chs) {
            case 1:
                fractions[0].add(fractions[1]).printVal();
                break;
            case 2:         //equality check
                fractions[0].isEqual(fractions[1])? cout<<"equal\n" : cout<<"not equal\n";
                break;
            case 3:         //print frac1
                fractions[0].printVal();
                break;
            case 4: {        //print frac2
                fractions[1].printVal();
                break;
            }
            case 5: //Quit
                q = 0;
                break;
            default:
                cout << ILLEGAL; //default
        }
    }

}

void Menu::clockMenu() { //clk menu
    int h,m,s;  //we will ask for these for each frac

    cout<<"enter hours \n";
    cin >> h;       //hour
    cout<<"Enter minutes\n";
    cin >> m;       //minut
    cout<<"Enter seconds\n";
    cin >> s;       //sex

    Clock clk = Clock(h, m, s);       //here we will store the 2 fracs

    int chs;        //chs input
    int q = 1;
    while (q) {     //q

        cout
                << "<1> what is the time\n"
                << "<2> add second\n"
                << "<3> add 10 seconds\n"
                << "<4> add 02:30:15\n"
                << "<5> exit\n";
        cin >> chs; // Get user input from the keyboard
        switch (chs) {
            case 1:
                clk.printTime();            //time chk
                break;

            case 2:
                (++clk).printTime();            //1sec incremebnt
                break;

            case 3:
                for(int i = 0; i < 10 ; i++)
                    (++clk).printTime();            //10 sec incremebnt +lots of prints
                break;

            case 4: {
                clk += Clock(2,30,15);      //stupid num increment
                clk.printTime();
                break;
            }
            case 5:
                q = 0;      //Quit
                break;
            default:
                cout << "illegal choice";
        }
    }

};
/********************************** HELPER FUNCTIONS *********************************/
/*this function takes in array of 3 lines
 * sorts it by selection sort
 * and returns it*/

void sortLines(Line sortedLines[3]){
    Line temp;
    //init
    for(int n = 0; n<3 ; n++){
        double max = 0;
        int imax;

        //run loop up until the already sorted part
        for(int i=n ; i < 3; i++){
            double l = sortedLines[i].getLen();

            //find maximal index
            if (l >= max){
                max = l;
                imax = i;
            }
        }// swich if necessery
        temp = sortedLines[n];
        sortedLines[n] = sortedLines[imax];
        sortedLines[imax] = temp;
    }
    cout<<"the coordinate ordered from high to low(by length):\n";
    for(int i = 0; i<3; i++){
        cout<<"cord: ";
        sortedLines[i].printLine();
    }
}