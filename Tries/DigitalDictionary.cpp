#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define ff first
#define ss second

class node
{
public:
    node *next[26];
    bool end;
    node()
    {
        rep(i, 0, 26)
            next[i] = NULL;
        end = false;
    }
};

class trie
{
private:
    node *root;

public:
    trie()
    {
        root = new node();
    }

    void insert(string &s)
    {
        node *it = root;
        for (auto c : s)
        {
            if (!it->next[c - 'a'])
                it->next[c - 'a'] = new node();
            it = it->next[c - 'a'];
        }
        it->end = true;
    }

    void find(string &s)
    {
        node *it = root;
        for (auto c : s)
        {
            if (!it->next[c - 'a'])
            {
                cout << "No suggestions" << endl;
                insert(s);
                return;
            }

            it = it->next[c - 'a'];
        }
        vector<string> res; // rest of string or remaining characters of strings
        print(it, s, res, "");

        for (auto c : res)
            cout << s << c << " " << endl;
    }

    void print(node *it, string &s, vector<string> &res, string cur)
    {
        if (it == NULL)
            return;
        if (it->end)
            res.push_back(cur);

        rep(i, 0, 26)
        {
            if (it->next[i])
            {
                print(it->next[i], s, res, cur + char('a' + i));
            }
        }
    }
};

int main()
{
    trie t;
    int n;
    cin >> n;

    vector<string> a(n);

    for (auto &i : a)
    {
        cin >> i;
        t.insert(i);
    }

    int q; // no. of queries
    cin >> q;
    while (q--)
    {
        string s;
        cin >> s;
        t.find(s);
    }
    return 0;
}