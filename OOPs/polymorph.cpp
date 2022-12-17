#include <bits/stdc++.h>
using namespace std;
/*
function overloading - when we have same name of functions then we diffrentiate them by there arguments or return type
operator overloading - when we need to define a operator in a diff. way to perform our task
and
virtual functions - if the parent and child class both as same name of member function then by default it will call the func of class B(child) to solve this problem we use term "virtual" before function name of class A(parent) like virtual void funcA()
*/
class A
{
public:
    void fun()
    {
        cout << "I am a function with no arguments.\n";
    };
    void fun(int x)
    {
        cout << "I am a function with int argument.\n";
    }
    void fun(double x)
    {
        cout << "I am a function with double argument.\n";
    }
};

class complex_number
{

private:
    int real;
    int imag;

public:
    complex_number(int r = 0, int i = 0)
    {
        real = r;
        imag = i;
    }
    complex_number operator+(complex_number const &obj)
    {
        complex_number res;
        res.imag = imag + obj.imag;
        res.real = real + obj.real;
        return res;
    }
    void display()
    {
        cout << real << "+" << imag << "i" << endl;
    }
};
int main()
{
    A obj;
    // obj.fun();
    // obj.fun(5);
    // obj.fun(1.256);
    complex_number c1(7, 4);
    complex_number c2(2, 8);
    complex_number c3 = c1 + c2;
    c3.display();
    return 0;
}
