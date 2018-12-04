#include <iostream>
#include "linkedlist.h"

using namespace std;

int readPid()
{
    int pid;
    string garbage;
    cout << "Please enter your pid: ";
    cin >> pid;
    getline(cin, garbage);
    return pid;
}

char readCommand()
{
    char cmd;
    string garbage;
    cout << "Please enter Q to quit\n"
         << "             A to add a new patient\n"
         << "             S to search for a patient\n"
         << "             V to view all in-patients\n"
         << "         and W to view all out-patinets\n";
    cin >> cmd;
    getline(cin, garbage);
    return toupper(cmd);
}

char readPatientType()
{
    char ptype = ' ';
    string garbage;

    while (ptype != 'I' && ptype != 'O') {
        cout << "Is this patient an in-patient or out-patient? (I/O): ";
        cin >> ptype;
        ptype = toupper(ptype);
    }
 
    return ptype;
}

int main()
{
    LinkedList inPatients;
    LinkedList outPatients;

    Patient *patient;
    char ptype;
    bool success = false;
    int pid;

    char cmd = readCommand();

    while (cmd != 'Q') {
        switch (cmd) {
            case 'A':
                patient = new Patient;
                ptype = readPatientType();
                if (ptype == 'I')
                    success = inPatients.addToBack(patient);
                else
                    success = outPatients.addToBack(patient);

                if (!success) {
                    cout << "Duplicate patient records!\n";
                    delete patient;
                }
                break;
            case 'S':
                pid = readPid();
                ptype = readPatientType();
                if (ptype == 'I')
                    patient = inPatients.search(pid);
                else
                    patient = outPatients.search(pid);
                if (patient == 0)
                    cout << "There is no such patient!\n";
                else
                    patient->display();
                break;
            case 'V':
                if (inPatients.getSize() == 0)
                    cout << "There is no in-patients.\n";
                else
                    inPatients.displayAll();
                break;
            case 'W':
                if (outPatients.getSize() == 0)
                    cout << "There is no out-patients.\n";
                else
                    outPatients.displayAll();
                break;
            default:
                cout << "Unknow command\n";
                break;
        }
        cmd = readCommand();
    }
}

