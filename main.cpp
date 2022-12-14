#include <iostream>
#include <fstream>
#include <string>
#include "Keeper.h"

using namespace std;

void dispMenu() {
    cout << "Choose:\n1 - workers;\n2 - files and string streams" << endl;
}

void dispWorkersMenu() {
    cout << "\t\tType command:\t\t\t\t\tIgnatiev 's laboratory work\n\t\t1 - add new worker\n\t\t2 - display workers\n\t\t3 - edit worker\n\t\t4 - remove worker (delete)\n\t\t5 - display workers with specified work experience\n\t\t6 - exit\n";
}

void dispFilesTaskMenu() {
    cout << "Type command:\n1 - display sentences without commas from file\n2 - display sentences without commas from string\n3 - exit" << endl;
}

void displayWithoutCommas(string line) {
    bool has_commas = false;
    string s, res;
    for (char& c : line) {
        s += c;
        if (c == '.') {
            if (!has_commas)
                res += s;
            has_commas = false;
            s = "";
        }
        else if (c == ',') {
            has_commas = true;
        }
    }
    if (res.length())
        cout << res << endl;
    else cout << endl;
}

void displayWithoutCommas() {
    fstream in("text.txt", fstream::in);
    string line, s;
    bool has_commas = false;
    while (getline(in, line)) {
        for (char& c : line) {
            s += c;
            if (c == '.') {
                if (!has_commas)
                    cout << s;
                has_commas = false;
                s = "";
            }
            else if (c == ',') {
                has_commas = true;
            }
        }
        s += '\n';
    }
    cout << endl;
}

int main() {
    Keeper k;
    while (1) {
        dispMenu();
        int num; cin >> num;
        if (num == 1) {
            while (1) {
                dispWorkersMenu();
                int num; cin >> num;
                if (num == 1) {
                    Worker* w = new Worker();
                    cin >> *w;
                    k.pushSorted(w);
                }
                else if (num == 2) {
                    try {
                        k.display();
                    }
                    catch (const exception& e) {
                        system("cls");
                        cout << "empty\n" << endl;//cout << "\nThere are no workers in a list." << endl;
                    }
                }
                else if (num == 3) {
                    cout << "Specify worker number to edit:" << endl;
                    int val; cin >> val;
                    if (val < 0 || val >= k.amount)
                        cout << "Out of bounds. Try again." << endl;
                    else
                        k.get(val)->edit();
                }
                else if (num == 4) {
                    cout << "Specify worker number to remove:" << endl;
                    int val; cin >> val;
                    if (val < 0 || val >= k.amount)
                        cout << "Out of bounds. Try again." << endl;
                    else
                        k.pop(val);
                }
                else if (num == 5) {
                    cout << "\nSpecify worker experience:" << endl;
                    int val; cin >> val;
                    k.workExpLargerThan(val);
                }
                else if (num == 6) {
                    system("cls");
                    break;
                    
                }
                else {
                    cout << "No such command. Try again." << endl;
                }
            }
        }
        else if (num == 2) {
            while (1) {
                dispFilesTaskMenu();
                int num; cin >> num;
                if (num == 1) {
                    system("cls");
                    displayWithoutCommas();
                    cout << "\n";
                }
                else if (num == 2) {
                    system("cls");
                    cout << "Specify string:\n";
                    cin.ignore();
                    string s; getline(cin, s);
                    cout << "result:\n";
                    displayWithoutCommas(s);
                    cout << "\n";
                }
                else if (num == 3) {
                    system("cls");
                    break;
                }
                else {
                    cout << "No such command. Try again." << endl;
                }
            }
        }
        else {
            cout << "No such command. Try again." << endl;
        }
    }
}
