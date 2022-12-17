#include <bits/stdc++.h>
using namespace std;
// algortihm
/*
operand means 1 2 3 4 5 6 7 8 9
operator means + - * /
if operand
    print
if '('
    push to stack
if ')'
pop from stack until '(' is found

if operator
    pop from stack and print until an operator is found with less precedence is found

*/
int prec(char c)
{
    if (c == '^')
    {
        return 3;
    }
    if (c == '*' || c == '/')
    {
        return 2;
    }
    if (c == '+' || c == '-')
    {
        return 1;
    }
    else
        return -1;
}
string infixTopostfix(string s)
{
    stack<char> st;
    string res;
    for (int i = 0; i < s.length(); i++)
    {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
        {
            res += s[i];
        }

        else if (s[i] == '(')
        {
            st.push(s[i]);
        }

        else if (s[i] == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                res += st.top();
                st.pop();
            }
            if (!st.empty())
            {
                st.pop();
            }
        }
        else
        {
            while (!st.empty() && prec(st.top()) > prec(s[i]))
            {
                res += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while (!st.empty())
    {
        res += st.top();
        st.pop();
    }

    return res;
}
int main()
{
    cout << infixTopostfix("(a-b/c)*(a/k-l)") << endl;

    return 0;
}
// (a-b/c)*(a/k-l)
