#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "patient.h"

struct Node {
    Patient * data;
    Node * next;
};

class LinkedList {
  public:
    LinkedList();
    ~LinkedList();
    bool addToBack(Patient *);
    void displayAll();
    int getSize();
    Patient * search(int pid);
  private:
    Node * head;
    Node * tail;
    int size;
};
#endif
