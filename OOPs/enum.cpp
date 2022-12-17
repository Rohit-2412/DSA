#include <bits/stdc++.h>
using namespace std;
/*

public data members can be accessed from anywhere
prtoected can be accessed only from inherited class
private can be accessed only inside parent class

*/
class A
{
	// can only be accessed with in parent class
private:
	int a;
	void funcA()
	{
		cout << "function A\n";
	}
	// can be accessed by any one
public:
	int b;
	void funcB()
	{
		cout << "function B\n";
	}
	// can be accessed only by inherited classes
protected:
	int c;
	void funcC()
	{
		cout << "function c\n";
	}
};
int main()
{
	A obj;
	obj.funcB();
	// obj.funcC(); // cant be accessed beacuse its protected
	// obj.funcA(); // can be accessed beacuse its private
	return 0;
}
