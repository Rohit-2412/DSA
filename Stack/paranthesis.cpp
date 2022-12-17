#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define nl "\n"

bool BalancedParenthesis(string s)
{
    stack<char> st;

    for (int i = 0; i < s.length(); i++)
    {
        // if the string starts with the closing bracket return false
        if (st.empty() && (s[i] == ')' || s[i] == '}' || s[i] == ']'))
            return false;

        else if (s[i] == '(' || s[i] == '[' || s[i] == '{') // opening bracket : direct push
            st.push(s[i]);

        else if (s[i] == ')' && st.top() == '(') // 3 cases of different closing brackets
            st.pop();
        else if (s[i] == '}' && st.top() == '{')
            st.pop();
        else if (s[i] == ']' && st.top() == '[')
            st.pop();
        else
            st.push(s[i]);
    }
    if (st.empty())
        return true;
    return false;
}

int main()
{
    string s;
    s = "{([})]";
    if (BalancedParenthesis(s))
        cout << "Valid String" << nl;
    else
    {
        cout << "Invalid String" << nl;
    }
    s = "{([])}";
    if (BalancedParenthesis(s))
        cout << "Valid String" << nl;
    else
    {
        cout << "Invalid String" << nl;
    }

    return 0;
}