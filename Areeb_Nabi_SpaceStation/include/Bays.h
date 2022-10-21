#ifndef BAYS_H
#define BAYS_H
#include <iostream>
#include <Ship.h>

using namespace std;

class Bays
{
    public:
        Bays();
        virtual ~Bays();
        Bays(const Bays& other);
        Bays& operator=(const Bays& other);

        Ship * GetcurrShip() { return currShip; }
        void SetcurrShip(Ship * val) { currShip = val; repairTime = currShip->getRepairTime();}
        int GetrepairTime() { return repairTime; }
        void SetrepairTime(int val) { repairTime = val; }
        int liveShipID() {return currShip->getShipId();}
        void sendShip() {delete currShip;}
        bool ifFree();
        void decrement(ostream& fout);

    protected:

    private:
        Ship * currShip;
        int repairTime;
};

#endif // BAYS_H
