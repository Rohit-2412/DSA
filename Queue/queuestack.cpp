#include <bits/stdc++.h>
using namespace std;
// make a queue using stack
// class que
// {
//     stack<int> s1;
//     stack<int> s2;

// public:
//     void push(int x)
//     {
//         s1.push(x);
//     }
//     int pop()
//     {
//         if (s1.empty() && s2.empty())
//         {
//             cout << "Queue is empty" << endl;
//             return -1;
//         }
//         if (s2.empty())
//         {
//             while (!s1.empty())
//             {
//                 s2.push(s1.top());
//                 s1.pop();
//             }
//         }
//         int topValue = s2.top();
//         s2.pop();
//         return topValue;
//     }
//     bool empty()
//     {
//         if(s1.empty() && s2.empty()){
//             return true;
//         }
//         return false;
//     }

// };

// method 2 using recursion
class que
{
    stack<int> s;

public:
    void push(int x)
    {
        s.push(x);
    }
    int pop()
    {
        if (s.empty())
        {
            cout << "Queue is empty" << endl;
            return -1;
        }

        int x=s.top();
        s.pop();
        if (s.empty())
        {
            return x;
        }
        int item=pop();
        s.push(x);
        return item;
    }
    bool empty()
    {
        if(s.empty()){
            return true;
        }
        return false;
    }

};

int main()
{
    // que q;
    // q.push(1);
    // q.push(2);
    // q.push(3);
    // q.push(4);
    // cout<<q.pop()<<endl;
    // cout<<q.pop()<<endl;
    // cout<<q.pop()<<endl;
    // cout<<q.pop()<<endl;
    // cout<<q.empty()<<endl;

    // for approach 2
    que q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.empty()<<endl;

    return 0;
}
