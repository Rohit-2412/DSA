#include <bits/stdc++.h>
using namespace std;
void reverseSentence(string s)
{
  stack<string> st;
  for (int i = 0; i < s.length(); i++)
  {
    string newWord = "";
    while (s[i] != ' ' && i < s.length())
    {
      newWord += s[i];
      i++;
    }
    st.push(newWord);
  }
  while (!st.empty())
  {
    cout << st.top() << " ";
    st.pop();
  }
}
void reverseChar(string s)
{
  stack<char> st;
  for (int i = 0; i < s.length(); i++)
  {
    st.push(s[i]);
  }
  while (!st.empty())
  {
    cout << st.top();
    st.pop();
  }
}
int main()
{

  string s = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  // reverseSentence(s);
  reverseChar(s);
  cout << endl;

  return 0;
}
