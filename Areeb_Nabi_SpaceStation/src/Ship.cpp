#include "Ship.h"

Ship::Ship()
{
   ///Declare and initialize variables
   id = 0;
   shipType = 'Q';
   rpTime = 0;
   bParts = brokenParts.begin(); //ctor
}

Ship::~Ship()
{

    //dtor
}

Ship::Ship(const Ship& other)                   //Copies Ship
{
    id = other.id;
    shipType = other.shipType;
    rpTime = other.rpTime;
    brokenParts.assign(other.brokenParts.begin(), other.brokenParts.end());
    bParts = brokenParts.begin();
    //copy ctor
}

Ship& Ship::operator=(const Ship& rhs)
{
    if (this == &rhs) return *this;
    id = rhs.id;
    shipType = rhs.shipType;
    rpTime = rhs.rpTime;
    bParts = rhs.bParts;
    return *this;
}

char Ship::createShipType(default_random_engine *gptr)
{
    ///Generates ship type
    char s;
    int t;
    uniform_int_distribution<int> Tdist(0, 100);
    t = Tdist(*gptr);
    if(t <= 5){s = 'R';}
    else if(t <= 15){s = 'K';}
    else if(t <= 30){s = 'F';}
    else if(t <= 50){s = 'O';}
    else (s = 'H');

    return s;
}

void Ship::createBrokenPts(default_random_engine *gptr)
{
    ///Broken Parts generator
    Parts * part;
    int partsbroke;
    uniform_int_distribution<int> Pdist(0,100);
    if (shipType == 'H')
    {
        for(int i=0; i<100; i++)
        {
            partsbroke = Pdist(*gptr);
            if (partsbroke <= 5)
            {
                part = new Parts;
                part->Setid(i+1);
                brokenParts.push_back(*part);
                delete part;
            }
        }
    }
    else if (shipType == 'F')
    {
        for(int i = 74; i < 150; i++)
        {
            partsbroke = Pdist(*gptr);
            if (partsbroke <= 8)
            {
                part = new Parts;
                part->Setid(i+1);
                brokenParts.push_back(*part);
            }
        }
    }
    else if (shipType == 'K')
    {
        for(int i = 2; i < 200; i++)
        {
            partsbroke = Pdist(*gptr);
            if (partsbroke <= 6 && i%2 == 0)
            {
                part = new Parts;
                part->Setid(i);
                brokenParts.push_back(*part);
            }
        }
    }
    else if (shipType == 'R')
    {
        for(int i = 1; i < 199; i++)
        {
            partsbroke = Pdist(*gptr);
            if (partsbroke <= 6 && i%2 == 1)
            {
                part = new Parts;
                part->Setid(i);
                brokenParts.push_back(*part);
            }
        }
    }
    else
    {
        for(int i = 0; i < 100; i++)
        {
            partsbroke = Pdist(*gptr);
            if (partsbroke <= 8)
            {
                part = new Parts;
                uniform_int_distribution<int> Odist (200, 999);
                int k = Odist(*gptr);
                part->Setid(k);
                brokenParts.push_back(*part);
            }
        }
    }
    if (brokenParts.size() == 0)
    {
          if (shipType == 'H')
            {
                uniform_int_distribution<int> Ndist (1, 100);
                partsbroke = Ndist(*gptr);
                part = new Parts;
                part->Setid(partsbroke);
                brokenParts.push_back(*part);
            }

        else if (shipType == 'F')
            {
                uniform_int_distribution<int> F2dist (75, 150);
                partsbroke = F2dist(*gptr);
                part = new Parts;
                part->Setid(partsbroke);
                brokenParts.push_back(*part);
            }

        else if (shipType == 'K')
            {
                uniform_int_distribution<int> K2dist (2, 100);
                partsbroke = K2dist(*gptr);
                if (partsbroke%2 == 0)
                {
                    part = new Parts;
                    part->Setid(partsbroke);
                    brokenParts.push_back(*part);
                }
                else
                {
                    partsbroke = partsbroke * 2;
                    part = new Parts;
                    part->Setid(partsbroke);
                    brokenParts.push_back(*part);
                }

            }
        else if (shipType == 'R')
        {
            uniform_int_distribution<int> R2dist (1, 199);
            partsbroke = R2dist(*gptr);
            if (partsbroke%2 == 1)
                {
                    part = new Parts;
                    part->Setid(partsbroke);
                    brokenParts.push_back(*part);
                }
            else
                {
                    partsbroke += 1;
                    part = new Parts;
                    part->Setid(partsbroke);
                    brokenParts.push_back(*part);
                }
        }
        else
        {
            part = new Parts;
            uniform_int_distribution<int> Odist (200, 999);
            int k = Odist(*gptr);
            part->Setid(k);
            brokenParts.push_back(*part);
        }
    }
}

void Ship::generateRTime(default_random_engine * gptr)
{
    int a, tot;                                                 //Takes the size of the list and for each ship type generates
    a = brokenParts.size();                                     //a part repair time total and returns it
    uniform_int_distribution<int> Qdist(1,5);

    for(int i = 0; i < a; i++)
        {
        if (shipType == 'H')
        {
                uniform_int_distribution<int> Hdist(1,5);
                tot = Hdist(*gptr);
                rpTime += tot;
        }
        else if (shipType == 'F')
        {
                uniform_int_distribution<int> Fdist(2,7);
                tot = Fdist(*gptr);
                rpTime += tot;
        }
        else if (shipType == 'K')
        {
                uniform_int_distribution<int> Kdist(3,7);
                tot = Kdist(*gptr);
                rpTime += tot;
        }
        else if (shipType == 'R')
        {
                uniform_int_distribution<int> Rdist(2,6);
                tot = Rdist(*gptr);
                rpTime += tot;
        }
        else
        {
                uniform_int_distribution<int> Odist(1,10);
                tot = Odist(*gptr);
                rpTime += tot;
        }

    }
  double b = (double)rpTime/5;                                          //cast rpTime to a double for rounding
  rpTime = (int)ceil(b);                                                //round and cast as an int for storage
}
void Ship::display(ostream& outFile)                                                    //Display for creation of ships
{
     cout << setw(10) <<"Ship ID: " << id << "," << setw(5) <<" Type: " << shipType << "," << setw(10) << " Repair Time: " << rpTime << endl;
     cout << setw(15) <<"Broken Parts: " << brokenParts.size() << setw(15)<< " Broken Part List: [ ";
     outFile << setw(10) <<"Ship ID: " << id << "," << setw(5) <<" Type: " << shipType << "," << setw(10) << " Repair Time: " << rpTime << endl;
     outFile << setw(15) <<"Broken Parts: " << brokenParts.size() << setw(15)<< " Broken Part List: [ ";
        while(bParts != brokenParts.end())
        {
            bParts->display(outFile);
            bParts++;
        }
    cout << "], has been added to the Queue." << endl << endl;
    outFile << "], has been added to the Queue." << endl << endl;
}
void Ship::display2(ostream& outFile)                                                      //Display for the end of simulation queue output
{
     cout << setw(10) <<"Ship ID: " << id << "," << setw(5) <<" Type: " << shipType << "," << setw(10) << " Repair Time: " << rpTime << endl;
     cout << setw(15) <<"Broken Parts: " << brokenParts.size() << setw(15)<< " Broken Part List: [ ";
     outFile << setw(10) <<"Ship ID: " << id << "," << setw(5) <<" Type: " << shipType << "," << setw(10) << " Repair Time: " << rpTime << endl;
     outFile << setw(15) <<"Broken Parts: " << brokenParts.size() << setw(15)<< " Broken Part List: [ ";
        while(bParts != brokenParts.end())
        {
            bParts->display(outFile);
            bParts++;
        }
    cout << "] is in the Queue." << endl << endl;
    outFile << "] is in the Queue." << endl << endl;
}
