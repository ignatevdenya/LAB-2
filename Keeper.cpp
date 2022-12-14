#define _CRT_SECURE_NO_WARNINGS
#include <ctime>
#include "Keeper.h"


using namespace std;

Keeper::Keeper() {
    head = NULL;
    tail = NULL;
}

Keeper::~Keeper() {
    free();
}

void Keeper::push(Worker *val, int to) {
    if (to < 0 || to > amount)
        throw out_of_range("Out of list range");
    Node *tmp = head, *prev_tmp = head;
    Node *new_tmp = new Node;
    new_tmp->data = val;
    new_tmp->next = NULL;
    amount++;
    for (int i = 0; i <= to; prev_tmp = tmp, tmp = tmp->next) {
        if (i == to) {
            if (isEmpty()) {
                head = new_tmp;
                tail = new_tmp;
            } else if (to == 0) {
                new_tmp->next = head;
                head = new_tmp;
            } else if (to == amount - 1) {
                tail->next = new_tmp;
                tail = new_tmp;
            } else {
                new_tmp->next = tmp;
                prev_tmp->next = new_tmp;
            }
            break;
        }
        i++;
    }
}

void Keeper::pop(int num) {
    checkEmptiness();

    amount--;
    Node *tmp = head, *prev_tmp = head;
    int i = 0;
    do {
        if (i == num) {
            if (tmp == head) 
                head = tmp->next;
            else if (tmp == tail) {
                tail = prev_tmp;
                tail->next = NULL;
            } else
                prev_tmp->next = tmp->next;
            delete tmp->data;
            delete tmp;
            break;
        } 
    } while (tmp->next != NULL, i++, prev_tmp = tmp, tmp = tmp->next);
}

Worker *Keeper::get(int num) {
    checkEmptiness();

    Node *tmp = head, *prev_tmp = head;
    int i = 0;
    do {
        if (i == num) 
            return tmp->data;
    } while (tmp->next != NULL, i++, prev_tmp = tmp, tmp = tmp->next);
}

void Keeper::display() {
    system("cls");
    checkEmptiness();

    Node *tmp = head;
    int i = 0;
    do {
        cout << i << " " << tmp->data;
    } while (tmp->next != NULL, i++, tmp = tmp->next);
}

void Keeper::free() {
    try {
        checkEmptiness();
    } catch(const exception &e) {
        return;
    }
    Node *tmp = head, *next;
    do {
        next = tmp->next;
        delete tmp->data;
        delete tmp;
    } while (next != NULL, tmp = next);
    head = NULL; tail = NULL; amount = 0;
}

void Keeper::pushSorted(Worker *val) {
    Node *tmp = head;
    string name_to_insert = val->getPaddedFullname();
    if (isEmpty())
        push(val, 0);
    else {
        for (int i = 0; i < amount;) {
            string name = tmp->data->getPaddedFullname();
            if (name_to_insert.compare(name) < 0) {
                push(val, i);
                return;
            } 
            tmp = tmp->next;
            i++;
        }
        push(val, amount);
    }
}

void Keeper::workExpLargerThan(int years) {
    Node *tmp = head;
    time_t t = time(nullptr);
    tm *const pTInfo = localtime(&t);
    int cur_year = 1900 + pTInfo->tm_year;
    bool found = false;
    for (int i = 0; i < amount;) {
        if (cur_year - tmp->data->getYear() >= years) {
            if (!found)
                cout << "\nWorkers with such work experience: " << endl;
            found = true;
            cout << i << " " << tmp->data->getSurname() << endl;
        } 
        tmp = tmp->next;
        i++;
    }
    if (!found) 
        cout << "No workers with such work experience." << endl;
}

bool Keeper::isEmpty() {
    return head == NULL;
}

Keeper::Node *Keeper::getHead() {
    return head;
}

void Keeper::operator++(int) {
    Worker *worker = new Worker();
    cin >> *worker;
    push(worker, amount);
}

void Keeper::operator--(int) {
    cout << "Specify worker number to remove:" << endl;
    int val; cin >> val;
    if (val < 0 || val >= amount)
        cout << "Out of bounds. Try again." << endl;
    else 
        pop(val);
}

void Keeper::checkEmptiness() {
    if (isEmpty()) throw out_of_range("Keeper is empty");
}