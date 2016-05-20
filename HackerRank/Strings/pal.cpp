#include <string>
#include <cstring>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

bool isPal(string word)
{
    string comp = word;
    reverse(comp.begin(), comp.end());
    for(int i = 0; i < word.size(); ++i)
    {
        if(comp[i] != word[word.size()-1-i])
            return false;
    }
    return true;
}
int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        string word;
        cin >> word;
        if(isPal(word))
            cout << -1 << endl;
        else
        {
            if(word.size() % 2 == 0)
        }

    }
}
