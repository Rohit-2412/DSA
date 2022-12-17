#include <bits/stdc++.h>
using namespace std;
// we have to find the smallest missing positive integer in thr given array
// we will make an array of size INT MAX and intialize the whole array with false and if there is an element and marks its position with true like for array 1 2 5 we will make a[1]= true same for a[2] and also for a[5].
// then we will check the first false value's index and print it as ans
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    const int N = 1e6 + 2;
    bool check[N];
    for (int i = 0; i < N; i++)
    {
        check[i]=false;
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i]>0)
        {
            check[a[i]]=true;
        }
        
    }
    for (int i = 1; i < N; i++)
    {
        if (check[i]==false)
        {
            cout << i << endl;
            break;
        }
        
    }
    
    

    return 0;
}
