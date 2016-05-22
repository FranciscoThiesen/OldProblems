#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <cstring>
#include <set>
using namespace std;

int main()
{
    int fa, wor, troc;
    cin >> fa >> wor >> troc;
    string word, fav;
    cin >> fav >> word;
    vector<int> freq(26,0);
    set<char> favset;
    for(int i = 0; i < word.size(); ++i)
    {
        freq[word[i]-'a']++;
    }
    int maxF = 0;
    int bestT = -1;
    for(int i = 0; i < fav.size(); ++i)
    {
        maxF += freq[fav[i] - 'a'];
        cout << fav[i] << endl;
        cout << maxF << endl;
        favset.insert(fav[i]);
    }
    int cur = maxF;
    vector<pair<char, char> >trocas;
    for(int j = 0; j < troc; ++j)
    {
        char a,b;
        cin >> a >> b;
        trocas.push_back(make_pair(a,b));
        freq[b] += freq[a];
        if(favset.find(a) != favset.end() && favset.find(b) == favset.end())
        {
            cur-= freq[a];   
        }
        if(favset.find(b) != favset.end() && favset.find(a) == favset.end())
        {
            cur+= freq[a];
        }
        freq[a] = 0;
        if(cur > maxF)
        {
            maxF = cur;
            bestT = j;
        }
    }
    for(int i = 0; i <= 4; ++i)
    {
        for(int j = 0; j < word.size(); ++j)
        {
            if(word[j] == trocas[i].second)
                word[j] = trocas[i].first;
        }
    }
    cout << maxF << endl << word << endl;
}
