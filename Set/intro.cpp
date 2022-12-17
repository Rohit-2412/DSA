#include <iostream>
#include <set>
#include <unordered_set>
using namespace std;

int main()
{
    // 1 set
    // properties -
    // no duplicates allowed
    // elements are in ascending order
    // functions allowed are -
    // insert, erase, lower_bound, upper_bound, size, find(), begin, end

    // 2 multi set
    // all properties same as set only difference is it can contain duplicates
    // if we erase one element all occurences will be deleted for that element

    // 3 unordered_set
    // random order of elements
    // here lower_bound and upper_bound are not available

    // set //

    // set<int> set;
    // set.insert(1);
    // set.insert(2);
    // set.insert(4);
    // set.insert(3);
    // set.insert(5);
    // set.insert(6);

    // // printing elements
    // for (auto i : set)
    //     cout << i << " ";
    // cout << endl;

    // cout << "Size : " << set.size() << endl;

    // // deletion
    // set.erase(3);
    // set.erase(5);

    // // printing elements
    // for (auto i : set)
    //     cout << i << " ";
    // cout << endl;

    // // size
    // cout << "Size : " << set.size() << endl;

    // // lower_bound

    // for (auto i : set)
    //     cout << i << " ";
    // cout << endl;

    // cout << "Lower Bound of 2: " << *set.lower_bound(2) << endl;
    // // gives value greater than or equal to passed parameter

    // cout << "Lower Bound of 4: " << *set.lower_bound(3) << endl;

    // // if passed value is the last value in the set then the end value will be printed
    // cout << "Lower Bound of 6: " << *set.lower_bound(6) << endl;

    // multi set
    // multiset<int> s;
    // s.insert(1);
    // s.insert(2);
    // s.insert(3);
    // s.insert(3);
    // s.insert(3);
    // s.insert(4);
    // s.insert(5);

    // for (auto i : s)
    //     cout << i << " ";
    // cout << endl;

    // s.erase(3);
    // for (auto i : s)
    //     cout << i << " ";
    // cout << endl;

    // // adding new elements
    // s.insert(0);
    // s.insert(0);
    // s.insert(0);

    // for (auto i : s)
    //     cout << i << " ";
    // cout << endl;

    // cout << s.size() << endl;

    //  unordered_set

    unordered_set<int> s;
    s.insert(0);
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    s.insert(5);
    s.insert(6);
    s.insert(7);
    s.insert(8);
    s.insert(9);

    // cout << *s.find(10);

    // for (auto i : s)
    //     cout << i << " ";
    // cout << endl;

    return 0;
}