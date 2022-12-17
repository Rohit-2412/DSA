#include <bits/stdc++.h>
using namespace std;
// types of function for a binary digit
// get bit - to know he bit of that pos like 0 or 1
// set bit - to set a bit(1) at a location if already 1 then break / nothing
// clear bit - to remove a bit(to make 1 to 0) from that location
// update bit - to to update a bit with given value like 0 or 1
int getBit(int n, int pos)
{
    // if following condition(and of 1 << position with number) becomes true then bit is 0
    // else bit is 1
    return ((n & (1 << pos)) != 0); // {{1 << n}} gives 1 followed by n zeroes
    // 1 << 3 gives 1000
}

int setBit(int n, int pos)
{
    return (n | (1 << pos));
}

int clearBit(int n, int pos)
{
    int mask = ~(1 << pos);
    return n & mask;
}

int updateBit(int n, int pos, int value)
{
    int mask = ~(1 << pos);
    n = n & mask;
    return (n | (value << pos));
}
int main()
{
    // 5 = 0101 indexing as 3 2 1 0
    // cout << getBit(5,3) << endl; // returns the bit as 0 or 1
    // cout << setBit(5,1) << endl; // 5 = 0101 if we set pos 1 as 1 then it becomes 0111 = 7
    // cout << clearBit(5,2) << endl; // clears the bit at that position if 1 then make it 0
    // cout << updateBit(5,1,1) << endl; // first we clear the bit of that pos..... then set the bit

    return 0;
}
