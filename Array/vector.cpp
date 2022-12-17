#include <bits/stdc++.h>
using namespace std;

int main()
{
    // declaration of vector
    vector<int> v;
    // initializing vector values
    v.push_back(1); // insert element to last of the vector
    v.push_back(2); // insert next last element
    v.push_back(3);
    // for printing elements of vector
    // simple for loop and accessing each element
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    // by creating an iterator(like a pointer) and de-referncing it to print the value
    vector<int>::iterator it;
    for (it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    // by using auto (this key-word automatically fetch the type of vector element)
    for (auto element : v)
    {
        cout << element << " ";
    }
    cout << endl;
    // to remove the last element of the vector
    v.pop_back();          // 1 2
    vector<int> v2(3, 50); // vector<int> v2(3,50)  here 3 represent number of element and 50 represent the value to be filled at all places
    // 50 50 50
    swap(v, v2); // it just swap the whole data
    cout << "vector v" << endl;
    for (auto element : v)
    {
        cout << element << " ";
    }
    cout << "\n";
    cout << "vector v2" << endl;
    for (auto element : v2)
    {
        cout << element << " ";
    }
    cout << "\n";
    cout << "after sorting";
    sort(v2.begin(), v2.end());
    for (auto element : v2)
    {
        cout << element << " ";
    }

    // pair
    pair<int, char> p; // pair<type 1, type 2> pair name
    p.first = 10;
    p.second = 'a';
    cout << p.first << endl;
    cout << p.second << endl;

    return 0;
}
