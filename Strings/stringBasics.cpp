#include <bits/stdc++.h>
using namespace std;
// basics = a - A = 32
int main()
{
    // string str = "a b c d e f g h";
    // // convert string to uppercase
    // for (int i = 0; i < str.size(); i++)
    // {
    //     if (str[i] >= 'a' && str[i] <= 'z')
    //     {
    //         str[i] -= 32;
    //     }
    // }
    // cout << str << endl;
    // // ---------------------------- //

    // // convert string to lowercase

    // for (int i = 0; i < str.size(); i++)
    // {
    //     if (str[i] >= 'A' && str[i] <= 'Z')
    //     {
    //         str[i] += 32;
    //     }
    // }
    // cout << str << endl;

    // Alterantive "transform" operator

    // string s = "zxcvbn";
    // transform(s.begin(), s.end(), s.begin(), ::toupper);

    // // start index , end index , from where to perform the operation , type of operation (first two input pass whole string)

    // cout << s << endl;

    // transform(s.begin(), s.end(), s.begin(), ::tolower);

    // cout << s << endl;

    // form the biggest number from numeric string

    // string s = "5749860";
    // sort(s.begin(),s.end(), greater<int>()); // sort the string in decreasing order
    // cout << s ;

    // ------------------------- //

    // form the smallest number from numeric string

    // string s = "5749860";
    // sort(s.begin(),s.end(), less<int>()); // sort the string in increaing order
    // cout << s ;

    // find the char occuring max times
    string s = "abcddddeeee";
    int freq[26] = {0}; // initializing the count of every alphabet as 0
    for (int i = 0; i < s.size(); i++)
    {
        freq[s[i] - 'a']++; // counting freq of each char 0 index for a 1 for b and so on ......
    }
    char ans = 'a';
    int maxF = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (freq[i] > maxF)
        {
            maxF = freq[i];
            ans = i + 'a';
        }
    }
    cout <<maxF <<endl;
    cout <<ans;

    return 0;
}
