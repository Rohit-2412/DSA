#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define ff first
#define ss second

// given eqn : (a * b ) % n = 1
// given a & n find b

struct triplet
{
    int x, y, gcd;
};

triplet extendedEuclid(int a, int b)
{
    if (b == 0)
    {
        triplet ans;
        ans.x = 1;
        ans.gcd = a;
        ans.y = 0;
        return ans;
    }

    triplet smallAns = extendedEuclid(b, a % b);
    triplet ans;
    ans.x = smallAns.y;
    ans.gcd = smallAns.gcd;
    ans.y = smallAns.x - (a % b) * smallAns.y;
    return ans;
}

int multiplicativeModuloInverse(int a, int m)
{
    triplet temp = extendedEuclid(a, m);
    return temp.x;
}
/*
a%m = (a+m) % m
if ans comes out to be -1 it implies 
    ans = a%m  + ans
    example for a=14 m=5
    14%5 = 4
    4 + (-1) = 3 ans
*/
int main()
{
    int a, m;
    cin >> a >> m;

    cout << multiplicativeModuloInverse(a, m) << endl;

    return 0;
}