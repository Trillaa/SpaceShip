#include "SpaceStation.h"

SpaceStation::SpaceStation()
{
    ///3 bays
    for (int i = 0; i < 3; i++)
    {
        Bays * bptr;
        bptr = new Bays;
        baysInStation.push_back(*bptr);//ctor
    }
}

SpaceStation::~SpaceStation()
{
    //dtor
}

SpaceStation::SpaceStation(const SpaceStation& other)
{
    /// 3 bays
     for (int i = 0; i < (int)other.baysInStation.size(); i++)
    {
        Bays * bptr;
        bptr = new Bays;
        baysInStation.push_back(*bptr);//ctor
    }
}       //copy ctor


SpaceStation& SpaceStation::operator=(const SpaceStation& rhs)
{
    if (this == &rhs) return *this;

    return *this;
}

bool SpaceStation::bayStatus(int i)
{
    ///Bay status checker
    if(baysInStation[i].ifFree()== true)
    {
        return true;
    }
    else
        return false;
}

void SpaceStation::timeStep(int i,ostream& outFile)
{
        cout << setw(12) << "Repair Bay " << i+1 << " Status: " << endl;
        outFile << setw(12) << "Repair Bay " << i+1 << " Status: " << endl;
        baysInStation[i].decrement(outFile);
}

void SpaceStation::addShip(int i, Ship * ptr,ostream& outFile)
{
    /// Adds a ship, displays ship ID and time
    baysInStation[i].SetcurrShip(ptr);
    cout << setw(12) << "Repair Bay " << i+1 << " Status: " << endl;
    outFile << setw(12) << "Repair Bay " << i+1 << " Status: " << endl;

    ///Bay pointer is set to ship
    int a = baysInStation[i].liveShipID();
    cout << setw(12) << "Ship ID: " << a << " is in Repair Bay " << i+1
    << " with a Repair Time of: " << baysInStation[i].GetrepairTime() << endl;

    outFile << setw(12) << "Ship ID: " << a << " is in Repair Bay " << i+1
    << " with a Repair Time of: " << baysInStation[i].GetrepairTime() << endl;
}



