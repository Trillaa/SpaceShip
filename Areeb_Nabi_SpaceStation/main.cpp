///Header files
#include <iostream>
#include <queue>
#include <random>   //Header file for using random generator
#include <ctime>
#include <fstream>  //Header file for using input/output files
#include "SpaceStation.h"

using namespace std;

int main()
{
    ofstream outFile;  ///Declare output file
    outFile.open("diary.txt"); ///Name of output file

    ///Random engine generator
    default_random_engine * gptr;
    gptr = new default_random_engine(time(NULL));

    ///Poisson distribution to show to determine likelihood of event occurrence
    poisson_distribution<int> Pdist(1.2);
    queue<Ship> shipQ;

    //Declare variables
    int shipID = 100;
    int timeStamp = 0;
    Ship * shipPointer;
    Ship * shipList;
    SpaceStation base;
    int q = Pdist(*gptr);

    ///Timestep for ships
    //Must be < 10
    for(int timestep = 0; timestep < 10; timestep++)
    {
        cout << "Timestamp " << timeStamp << ": " << endl;
        outFile << "Timestamp " << timeStamp << ": " << endl;
        int shipsInbound = Pdist(*gptr);

        ///For loop for ship details and broken parts
        for(int i = 0; i < shipsInbound; i++)
        {
            shipPointer = new Ship;
            shipPointer->setShipId(shipID);
            shipPointer->setShipType(shipPointer->createShipType(gptr));
            shipPointer->createBrokenPts(gptr);
            shipPointer->generateRTime(gptr);
            shipPointer->setIterator();
            shipPointer->display(outFile);
            shipQ.push (*shipPointer);
            shipID++;
            delete shipPointer;
            shipPointer = NULL;
        }

        shipList = &(shipQ.front());

        for(int j = 0; j < 3; j++)
        {
            if(shipQ.empty() == true)
            {
               break;
            }
            if(base.bayStatus(j) == true)
            {
                base.addShip(j, shipList, outFile);
                shipQ.pop();
                shipList = &(shipQ.front());
            }
            else
            {
                base.timeStep(j, outFile);
            }
        }


        cout << endl;
        outFile << endl;
        timeStamp++;
        if(timestep == 9)
        {
            char answer;
            cout << "Enter Y to run again." << endl;
            outFile << "Enter Y to run again." << endl;
            cin >> answer;
            outFile << answer;
            if (answer == 'Y' || answer == 'y')
            {
                timestep = -1;
            }
        }
    }
    ///Output details
    // Screen
    cout << endl;
    cout << setw(10)<< " " << "-------------------" << endl;
    cout << setw(11)<< " " << "End of Simulation" << endl;
    cout << setw(10)<< " " << "-------------------" << endl << endl;

    //Output File
    outFile << endl;
    outFile << setw(10)<< " " << "-------------------" << endl;
    outFile << setw(11)<< " " << "End of Simulation" << endl;
    outFile << setw(10)<< " " << "-------------------" << endl << endl;
    shipPointer = &(shipQ.front());
    cout << "Ships still remaining in queue post-simulation: " << endl << endl;
    outFile << "Ships still remaining in queue post-simulation: " << endl << endl;

    while(!shipQ.empty())
    {
        shipPointer->display2(outFile);
        shipQ.pop();
        shipPointer = &(shipQ.front());
    }

    //Close output file
    outFile.close();
    return 0;
}
