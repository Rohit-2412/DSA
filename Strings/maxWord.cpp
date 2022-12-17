#include <bits/stdc++.h>
using namespace std;
// palindrome and max word out of a sentence with its length
int main()
{
    //     int n;
    //     cin >> n;
    //     char arr[n+1];
    //     cin >> arr; // taking input
    // cout <<arr;
    // printing array

    // for palindrome check
    // if its a palndrome then its first and last char will be same ans so on...
    // bool check = true;
    // for (int i = 0; i < n/2; i++)
    // {
    //     if(arr[i] != arr[n-1-i])
    //         check = false;
    // }
    // check == true ? (cout << "palindrome string" << endl) : (cout << "not a palindrome string" << endl) ;

    // Largest word out of a string
    int n;
    cin >> n;
    char arr[n + 1];
    cin.ignore();
    cin.getline(arr, n);
    cin.ignore();
    int i = 0;
    int currLen = 0, maxLen = 0;
    int st = 0, maxSt = 0;
    while (i < n)
    {
        if (arr[i] == ' ' || arr[i] == '\0')
        {
            if (currLen > maxLen)
            {
                maxSt = st;
                maxLen = currLen;
            }
            st = i + 1;
            currLen = 0;
        }
        else
            currLen++;
        if (arr[i] == '\0')
            break;
        i++;
    }
    // cout << arr << endl; //for printing string
    cout << maxLen << endl;
    for (int i = 0; i < maxLen; i++)
    {
        cout << arr[maxSt + i];
    }
    cout << endl;

    return 0;
}
