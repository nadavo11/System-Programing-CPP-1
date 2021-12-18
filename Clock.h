//
// Created by nadavo on 14/12/2021.
//
/*******************************    CLASS Clock  ***********************************************/

/*******************************    HEADERS   ***********************************************/

#ifndef CP_3_CLOCK_H                                                                      /**/
#define CP_3_CLOCK_H
/********************************************************************************************/




class Clock {
/*******************************    private fields & methods  ****************************************/
    int array[3];
/*******************************    public  methods  ***********************************************/
public:

    Clock(int h = 0, int m = 0, int s = 0);


    Clock& operator+=(Clock clk){
        int time[3];
        for(int i = 0; i<3 ; i++)
            time[i] = clk.array[i];


        if ((array[2] + time[2]) >= 60)
            time[1] += 1;
        array[2] = (array[2] + time[2]) % 60;


        if ((array[1] + time[1]) >= 60)
            time[0] += 1;
        array[1] = (array[1] + time[1]) % 60;

        array[0] = (array[0] + time[0]) % 24;

    }

    Clock& operator ++(){
        Clock clk = Clock(0,0,1);
        *this += clk;
        return *this;
    }

    void setHour(int hour);
    void setMin(int min);
    void setSecs(int secs);

    int getHour();
    int getMin();
    int getSecs();

    void printTime();

    bool isMorning();
    bool isAfternoon();
    bool isEvening();

    void tick();

    /*******************************        Dtors       **********************************************/
    ~Clock();
};



#endif //CP_3_CLOCK_H
