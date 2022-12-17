#include <bits/stdc++.h>
using namespace std;
/*
basic function about class and how to declare how to enter values by both user input and initializiation

deleting value also

*/
class student
{
private:
    int phone_number;

public:
    string name;
    int age;
    bool gender;
    student()
    {
        cout << "Default constructor" << endl;
    }
    student(int num, string n, int a, bool gen)
    {
        cout << "Parameterized constructor" << endl;
        phone_number = num;
        name = n;
        age = a;
        gender = gen;
    }
    student(student &a)
    {
        cout << "Copy constructor" << endl;
        name = a.name;
        age = a.age;
        gender = a.gender;
    }
};

int main()
{

    return 0;
}
