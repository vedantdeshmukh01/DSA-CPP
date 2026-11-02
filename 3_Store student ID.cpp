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

    Student s[3] = {
        {101, "Rahul", 8.5},
        {102, "Amit", 7.5},
        {103, "Vedant", 9.0}
    };

        for(int i = 0; i < n-1; i++) {

        for(int j = 0; j < n-i-1; j++) {

            if(s[j].cgpa > s[j+1].cgpa) {

                Student temp = s[j];
                s[j] = s[j+1];
                s[j+1] = temp;
            }
        }
    }

        cout << "Students sorted by CGPA:\n";

    for(int i = 0; i < n; i++) {

        cout << "ID: " << s[i].id << endl;
        cout << "Name: " << s[i].name << endl;
        cout << "CGPA: " << s[i].cgpa << endl;
        cout << "----------------\n";
    }

    return 0;
}