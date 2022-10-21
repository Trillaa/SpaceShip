#ifndef SPACESTATION_H
#define SPACESTATION_H
#include <iostream>
#include <Bays.h>
#include <vector>


using namespace std;

class SpaceStation
{
    public:
        SpaceStation();
        virtual ~SpaceStation();
        SpaceStation(const SpaceStation& other);
        SpaceStation& operator=(const SpaceStation& other);

        bool bayStatus(int i);
        void addShip(int i, Ship * ptr,ostream& fout);
        void timeStep(int i,ostream& fout);


    protected:

    private:
        vector<Bays> baysInStation;
};

#endif // SPACESTATION_H
