#include <bits/stdc++.h>
using namespace std;
class A
{
private:
    void funcA();

public:
    void funcB();

protected:
    void funcC();
};
class B : public A
{ // all public members and data types of A will come under public of B
};

int main()
{

    return 0;
}
