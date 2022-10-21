#ifndef SHIP_H
#define SHIP_H
#include <list>
#include <iostream>
#include <random>
#include <cmath>
#include <ctime>
#include <iomanip>

#include "Parts.h"
using namespace std;

class Ship
{
    public:
        Ship();
        virtual ~Ship();
        Ship(const Ship& other);
        Ship& operator=(const Ship& other);

        int getRepairTime(){return rpTime;}
        void setRepairTime(int t){ rpTime = t;}
        int getShipId() {return id;}
        void setShipId(int a) { id = a;}
        char getShipType() {return shipType;}
        void setShipType(char b) { shipType = b;}
        void setIterator() {bParts = brokenParts.begin();}
        char createShipType(default_random_engine * gptr);
        void createBrokenPts(default_random_engine * gptr);
        void generateRTime(default_random_engine * gptr);
        void display(ostream& outFile);
        void display2(ostream& outFile);

    protected:

    private:
        int rpTime, id;
        char shipType;
        list<Parts> brokenParts;
        list<Parts>::iterator bParts;

};

#endif // SHIP_H
