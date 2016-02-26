#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
using namespace std;
int main()
{
    int t;
    scanf("%d", &t);
    int gem[26];
    int total = 0;
    memset(gem, 0, sizeof gem);
    for(int i = 0; i < t; ++i)
    {
        string word;
        cin >> word;
        for(int j = 0; j < word.size(); ++j)
            if(gem[word[j]-'a'] < i+1)
                gem[word[j] - 'a']++;
    }
    for(int k = 0; k < 26;k++)
    {
        cout << k << " " << gem[k] <<  endl;
        if(gem[k] >= t)
        {
            total++;
        }
    }
    cout << total << endl;

}
