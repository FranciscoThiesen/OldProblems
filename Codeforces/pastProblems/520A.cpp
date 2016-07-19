#include <cstdio>
#include <set>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
int main()
{
    int n;
    cin >> n;
    string word; 
    cin >> word;
    set<char> letrax;
    if(word.size() < 23)
    {
        printf("NO\n");
        return 0;
    }
    for(int i = 0; i < word.size(); i++)
    {
        if(word[i] >= 'A' && word[i] <= 'Z')
            letrax.insert(word[i] + 32);
        else
            letrax.insert(word[i]);
    }
    if(letrax.size() >= 26)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}
