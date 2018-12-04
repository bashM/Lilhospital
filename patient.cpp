#include <iostream>
#include "patient.h"
using namespace std;

Patient::Patient()
{
    string garbage;
    cout << "Please enter your patient id: ";
    cin >> pid;
    getline(cin, garbage);
    cout << "Please enter your name: ";
    getline(cin, name);
    cout << "Please enter your address: ";
    getline(cin, address);
}

Patient::~Patient()
{ }

void Patient::display()
{
    cout << "    pid: " << pid << endl;
    cout << "   name: " << name << endl;
    cout << "address: " << address << endl;
}

int Patient::getPid()
{
    return pid;
}
