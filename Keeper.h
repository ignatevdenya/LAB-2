#include <iostream>
#include "Worker.h"

class Keeper {
    private:
        struct Node {
            Worker *data;
            struct Node *next;
        };
        Node *head, *tail;
    public:        
        Keeper();
        ~Keeper();
        
        void push(Worker *val, int to);
        void pop(int num);
        Worker *get(int num);
        void display();
        void free();

        void pushSorted(Worker *val);
        void workExpLargerThan(int years);

        bool isEmpty();
        Node *getHead();
        int amount = 0;

        void operator++(int);
        void operator--(int);
        void checkEmptiness();
};