#include <bits/stdc++.h>
using namespace std;
// top 7 questions --->
// rev a string
void revString(string s)
{
    if (s.length() == 0)
    {
        return;
    }
    string ros = s.substr(1); //substr makes a sub string after removing i-th position char
    revString(ros);
    cout << s[0];
}
// replace pi with 3.14 in string
// example pippxxppiixipi
// 3.14ppxxp3.14ixi3.14
void replacePi(string s)
{
    if (s.length() == 0)
    {
        return;
    }
    if (s[0] == 'p' && s[1] == 'i')
    {
        cout << "3.14";
        replacePi(s.substr(2));
    }
    else
    {
        cout << s[0];
        replacePi(s.substr(1));
    }
}
// tower of hanoi
void towerOfHanoi(int n, char src, char dest, char helper)
{
    if (n == 0)
    {
        return;
    }
    towerOfHanoi(n - 1, src, helper, dest);
    cout << "Move from " << src << " to " << dest << endl;
    towerOfHanoi(n - 1, helper, dest, src);
}
// remove all duplicates from a string
string removeDup(string s)
{
    if (s.length() == 0)
    {
        return "";
    }
    char ch = s[0];
    string ans = removeDup(s.substr(1));
    if (ch == ans[0])
    {
        return ans;
    }
    return (ch + ans);
}
// move all 'x' to end of the string
string moveAllX(string s)
{
    if (s.length() == 0)
    {
        return "";
    }
    char ch = s[0];
    string ans = moveAllX(s.substr(1));

    if (ch == 'x')
    {
        return ans + ch;
    }
    return ch + ans;
}
// generate all substring of a string
void subseq(string s, string ans)
{
    if (s.length() == 0)
    {
        cout << ans << endl;
        return;
    }
    char ch = s[0];
    string ros = s.substr(1);

    subseq(ros, ans);
    subseq(ros, ans + ch);
}
// generate substring with ascii code
// A = 65 & B = 66
void subseq2(string s, string ans)
{
    if (s.length() == 0)
    {
        cout << ans << endl;
        return;
    }
    char ch = s[0];
    int code = ch;
    string ros = s.substr(1);
    subseq2(ros, ans);
    subseq2(ros, ans + ch);
    subseq2(ros, ans + to_string(code));
}
// to print all possible letters from 2 digits on keypad phone
string keypadArr[] = {"", ".,/", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
void keypad(string s, string ans)
{
    if (s.length() == 0)
    {
        cout << ans<<endl;
        return;
    }
    char ch = s[0];
    string code = keypadArr[ch - '0'];
    string ros = s.substr(1);
    for (int i = 0; i < code.length(); i++)
    {
        keypad(ros, ans + code[i]);
    }
}

int main()
{
    // string s = "abcdefgh";
    // revString(s);

    // string s="pippxxppiixipi";
    // replacePi(s);

    // towerOfHanoi(3, 'A', 'C', 'B');

    // string s="aaaaabbbbbcccdddeeee";
    // cout <<removeDup(s) << endl;

    // string s="axxggxxguguxxx";
    // cout <<moveAllX(s) <<endl;

    // subseq("ABC","");

    // subseq2("XY", "");

    keypad("29", "");

    return 0;
}
