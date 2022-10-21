#ifndef PARTS_H
#define PARTS_H
#include <iostream>
#include <fstream>

using namespace std;
class Parts
{
    public:
        Parts();
        virtual ~Parts();
        Parts(const Parts& other);
        Parts& operator=(const Parts& other);

        int Getid() { return id; }
        void Setid(int val) { id = val; }
        void display(ostream& outFile) { cout << id << " "; outFile << id << " "; }
    protected:

    private:
        int id;

};

#endif // PARTS_H
