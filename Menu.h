//
// Created by nadavo on 10/12/2021.
//
/*******************************    CLASS Menu  ***********************************************/


/*******************************    HEADERS   ***********************************************/
#include <cmath>
#include "iostream"
using namespace std;
#ifndef CP_3_MENU_H
#define CP_3_MENU_H
/********************************************************************************************/


class Menu{

//default constructor override
/*******************************    private fields  ***********************************************/
    double x1;
    double y1;
    double x2;
    double y2;
/*******************************    public  methods  ***********************************************/
public:

    void mainMenu();

    static void lineMenu();

    void fractionMenu();

    void clockMenu();

/*******************************    Constructors  ***********************************************/
    Menu();
};

#endif //CP_3_MENU_H
