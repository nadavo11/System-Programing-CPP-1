//
// Created by nadavo on 14/12/2021.
//

#include "Clock.h"
#include <iostream>

using namespace std;


Clock::Clock(int h, int m, int s) {

    if (h >= 24 || m >= 60 || s >= 60)
        array[0],array[1],array[2] = 0,0,0;


    if (h <= 0 || m <= 0 || s <= 0)
        array[0],array[1],array[2] = 0,0,0;

    array[0] = h;
    array[1] = m;
    array[2] = s;
}


int Clock::getHour() {
    return array[0];
}

int Clock::getMin() {
    return array[1];
}

int Clock::getSecs() {
    return array[2];
}

void Clock::setHour(int hour) {
    array[0] = hour;
}

void Clock::setMin(int min) {
    array[1] = min;
}

void Clock::setSecs(int secs) {

}

void Clock::printTime() {
    cout<< ((array[0]>9)? "":"0" )<<array[0]
        <<":"<<((array[1]>9)? "":"0" )<<array[1]
        <<":"<<((array[2]>9)? "":"0" )<< array[2] <<"\n";
}

Clock::~Clock() {

}

void Clock::tick() {
    ++*this;
    this->printTime();
}

bool Clock::isMorning() {
    if(this->array[0] < 12)
        return true;
    return false;
}

bool Clock::isAfternoon() {
    if(this->isMorning())
        return false;
    if(this->isEvening())
        return false;
    return true;
}

bool Clock::isEvening() {
    if(this->array[0]>=18)
        return true;
    return false;
}

