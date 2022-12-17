#include <bits/stdc++.h>
using namespace std;
/*
add 
sub
mult
divide
sqr
sqrt
cube
power
*/

int main()
{
    int a, b, choice;
    cout << "Enter your choice:\n 1 for addition, 2 for subtraction, 3 for multiplication, 4 for division, 5 for square, 6 for power,7 for cube,8 for sqaure root " << endl;
    bool task = true;
    while (task == 1)
    {
        cin >> choice;
        cout << "Enter a and b: " << endl;
        cin >> a >> b;
        if (choice == 1)
        {
            cout << "your addition is: " << a + b << endl;
        }
        if (choice == 2)
        {
            cout << "your subtraction is: " << a - b << endl;
        }
        if (choice == 3)
        {
            cout << "your multiplication is: " << a * b << endl;
        }
        if (choice == 4)
        {
            if (b == 0)
            {
                cout << "wrong input" << endl;
                break;
            }
            cout << "your division is " << a / b << endl;
        }
        if (choice == 5)
        {
            cout << "your square is: " << a * a << endl;
        }
        if (choice == 6)
        {
            cout << "your power for" << a << "raised to " << b << "is" << endl;
        }
        if (choice == 7)
        {
            cout << "your cube is" << a * a * a << endl;
        }
        if (choice == 8)
        {
            cout << "your square root is:" << sqrt(a) << endl;
        }
        cout << "do yo want to continue?\npress 1 for yes 0 for no." << endl;

        cin >> task;
        if (task == 0)
        {
            return 0;
        }
    }

    return 0;
}
