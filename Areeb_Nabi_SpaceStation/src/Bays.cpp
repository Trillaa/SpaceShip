#include "Bays.h"

Bays::Bays()
{
   currShip = NULL;
   repairTime = 0;
       //ctor
}

Bays::~Bays()
{
    //dtor
}

Bays::Bays(const Bays& other)
{
    currShip = new Ship;
    currShip = other.currShip;
    repairTime = other.repairTime;  //copy ctor
}

Bays& Bays::operator=(const Bays& rhs)
{
    if (this == &rhs) return *this;
    currShip = rhs.currShip;
    repairTime = rhs.repairTime;

    return *this;
}

bool Bays::ifFree()
{
    if(currShip == NULL)                //Checks if bay is occupied, returns true if empty
    {
        return true;
    }
    else
        return false;
}

void Bays::decrement(ostream& outFile)
{                                                        //Decrements time for repairs
    repairTime--;                                     //Ships repair time is decremented and remaining time displays
    if(repairTime == 0)
    {
        cout << setw(12) << "Ship ID: " << currShip->getShipId() << " is repaired and is departing Station Zebra." << endl;
        outFile << setw(12) << "Ship ID: " << currShip->getShipId() << " is repaired and is departing Station Zebra." << endl;
        currShip = NULL;
    }
    else
    {
    cout << setw(12) << "Ship ID: " << currShip->getShipId() <<" has " << repairTime << " timesteps until repaired." << endl;
    outFile << setw(12) << "Ship ID: " << currShip->getShipId() <<" has " << repairTime << " timesteps until repaired." << endl;
    }
}

