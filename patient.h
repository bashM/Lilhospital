#ifndef PATIENT_H
#define PATIENT_H
#include <iostream>

class Patient {
  public:
    Patient();
    ~Patient();
    void display();
    int getPid();
  private:
    int pid;
    std::string name;
    std::string address;
};
#endif
