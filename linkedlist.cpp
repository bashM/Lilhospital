#include "linkedlist.h"

LinkedList::LinkedList()
{
    head = new Node;
    tail = head;
    head->next = 0;
    size = 0;
}

LinkedList::~LinkedList()
{
    Node *cur = head->next;
    Node *tmp;
    while (cur != 0) {
        tmp = cur->next;
        delete cur->data;
        delete cur;
        cur = tmp;
    }
    delete head;
}

bool LinkedList::addToBack(Patient *record)
{
    Node *cur = head->next;

    while (cur != 0) {
        if (cur->data->getPid() == record->getPid()) {
            return false;
        }
        cur = cur->next;
    }

    tail->next = new Node;
    tail = tail->next;
    tail->data = record;
    tail->next = 0;
    size++;
    return true;
}

void LinkedList::displayAll()
{
    Node *cur = head->next;
    while (cur != 0) {
        cur->data->display();
        cur = cur->next;
    }
}

int LinkedList::getSize()
{
    return size;
}

Patient *LinkedList::search(int pid)
{
    Node *cur = head->next;
    while (cur != 0) {
        if (cur->data->getPid() == pid)
            return cur->data;
        cur = cur->next;
    }
    return 0;
}

