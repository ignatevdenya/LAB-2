#include "Worker.h"
#include <string>
#define _CRT_SECURE_NO_WARNINGS
#define MAX_STR_SZ 20

using namespace std;

Worker::Worker() {
    cout << "Constructor Worker" << "\n";
};

Worker::Worker(string name, string surname, string patronymic, string job, int year):
name(name), surname(surname), patronymic(patronymic), job(job), year(year)
{
    cout << "Constructor with params Worker" << endl;
};

Worker::~Worker() {
    system("cls");
    cout << "Destructor Worker" << "\n";
};

void Worker::setName(string s) {
    validateString(s);
    name = s;
};

void Worker::setSurname(string s) {
    validateString(s);
    surname = s;
};

void Worker::setPatronymic(string s) {
    validateString(s);
    patronymic = s;
};

void Worker::setJob(string s) {
    validateString(s);
    job = s;
};

void Worker::setYear(int n) {
    validateInt(n);
    year = n;
};

string Worker::getName() {
    return name;
};

string Worker::getSurname() {
    return surname;
};

string Worker::getPatronymic() {
    return patronymic;
};

string Worker::getJob() {
    return job;
};

int Worker::getYear() {
    return year;
};

void Worker::validateString(string s) {
    if (s.length() <= 0) 
        throw invalid_argument("empty string");
    else if (s.length() >= 21)
        throw invalid_argument("string is too big(max size is 20)");
}

void Worker::validateInt(int n) {
    if (n <= 0) {
        cin.clear();
        cin.ignore(10000, '\n');
        throw invalid_argument("value cannot be negative or zero");
    }
}

ostream& operator<<(ostream &os, Worker &o) {
    os << o.getFormattedParams();
    return os;
}

ostream& operator<<(ostream &os, Worker *o) {
    os << o->getFormattedParams();
    return os;
}

istream& operator>>(istream &is, Worker &o) {
    float n; string s;
    system("cls");
    cout << "name: "; cin >> s; o.setName(s);
    cout << "surname: "; cin >> s; o.setSurname(s);
    cout << "patronymic: "; cin >> s; o.setPatronymic(s);
    cout << "job: "; cin >> s; o.setJob(s);
    cout << "year: "; cin >> n; o.setYear(n);
    return is;
}

string Worker::getPaddedFullname() {
    string res;
    string s[] = {name, surname, patronymic};
    for (int i = 0; i < 3; i++) {
        res += s[i];
        string pad(MAX_STR_SZ - s[i].length(), '{');
        res += pad;
    }
    return res;
}

string Worker::getFormattedParams() {
    return "\nname: " + name + ";\n" + "surname: " + surname + ";\n" + "patronymic: " + patronymic + ";\n" + "job: " + job + ";\n" + "year: " + to_string(year) + ".\n";
}

void Worker::edit() {
    while (1) {
        system("cls");
        cout << "Type command number\n(1 - edit name, 2 - edit surname, 3 - edit patronymic, 4 - edit job, 5 - edit year, 6 - exit)" << endl;
        int num; cin >> num;
        bool error = false;
        if (num == 1) {
            cout << "Type new name: " << endl;
            string value;
            cin >> value;
            try {
                validateString(value);
            } catch (const exception &e) {
                cout << e.what() << endl;
                error = true;
            }
            if (!error) 
                setName(value);
        } else if (num == 2) {
            cout << "Type new surname: " << endl;
            string value;
            cin >> value;
            try {
                validateString(value);
            } catch (const exception &e) {
                cout << e.what() << endl;
                error = true;
            }
            if (!error) 
                setSurname(value);
        } else if (num == 3) {
            cout << "Type new patronymic: " << endl;
            string value;
            cin >> value;
            try {
                validateString(value);
            } catch (const exception &e) {
                cout << e.what() << endl;
                error = true;
            }
            if (!error) 
                setPatronymic(value);
        } else if (num == 4) {
            cout << "Type new job: " << endl;
            string value;
            cin >> value;
            try {
                validateString(value);
            } catch (const exception &e) {
                cout << e.what() << endl;
                error = true;
            }
            if (!error) 
                setJob(value);
        } else if (num == 5) {
            cout << "Type new year: " << endl;
            int value;
            cin >> value;
            try {
                validateInt(value);
            } catch (const exception &e) {
                cout << e.what() << endl;
                error = true;
            }
            if (!error) 
                setYear(value);
        } else if (num == 6) {
            break;
        } else {
            cout << "Such property is not specified. Try again." << endl;
            system("pause");
            system("cls");
        }
    }
}
