#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define ff first
#define ss second

class Trie
{
public:
    class node
    {
    public:
        bool end;
        node *next[26];

        node()
        {
            end = false;
            rep(i, 0, 26)
            {
                next[i] = NULL;
            }
        }
    };

    node *trie;
    Trie()
    {
        trie = new node();
    }

    void insert(string word)
    {
        int i = 0;
        node *it = trie;
        while (i < word.size())
        {
            if (it->next[word[i] - 'a'] == NULL)
            {
                it->next[word[i] - 'a'] = new node();
            }
            it = it->next[word[i] - 'a'];
            i++;
        }
        it->end = true; // indicating that word is ending here
    }

    bool search(string word)
    {
        int i = 0;
        node *it = new node();
        while (i < word.size())
        {
            if (it->next[word[i] - 'a'] == NULL)
                return false;
            it = it->next[word[i] - 'a'];
            it++;
        }
        return it->end;
    }
};

int main()
{
    Trie *root = new Trie();
    vector<string> word = {"ayush", "ashish"};

    for (auto w : word)
    {
        root->insert(w);
    }

    if (root->search("madhav"))
        cout << "madhav found" << endl;
    else
        cout << "madhav doesn't exist" << endl;

    if (root->search("ayush"))
        cout << "ayush found" << endl;
    else
        cout << "ayush doesn't exist" << endl;

    return 0;
}