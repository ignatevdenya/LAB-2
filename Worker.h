#pragma once
#include <iostream>

using namespace std;

class Worker {
    private:
        string name, surname, patronymic, job;
        int year;
    public:
        Worker();
        Worker(string name, string surname, string patronymic, string job, int year);
        ~Worker();
        void setName(string s);
        void setSurname(string s);
        void setPatronymic(string s);
        void setJob(string s);
        void setYear(int n);
        string getName();
        string getSurname();
        string getPatronymic();
        string getJob();
        int getYear();

        void validateString(string s);
        void validateInt(int n);

        friend ostream& operator<<(ostream &os, Worker &o);
        friend ostream& operator<<(ostream &os, Worker *o);
        friend istream& operator>>(istream &is, Worker &o);

        string getPaddedFullname();
        string getFormattedParams();

        void edit();
};