#include <iostream>
#include <string>
using namespace std;

struct Student {
    int id;
    string name;
    float cgpa;
};

int main() {

    int n = 3;

    Student *s = new Student[n];

    s[0] = {101, "Rahul", 8.5};
    s[1] = {102, "Amit", 9.1};
    s[2] = {103, "Vedant", 9.5};

    int key = 102;
    int found = -1;

    for(int i = 0; i < n; i++) {
        if(s[i].id == key) {
            found = i;
            break;
        }
    }

    if(found == -1) {
        cout << "Student not found";
    }
    else {
        cout << "Student Found!" << endl;
        cout << "ID: " << s[found].id << endl;
        cout << "Name: " << s[found].name << endl;
        cout << "CGPA: " << s[found].cgpa << endl;
    }

    delete[] s;

    return 0;
}