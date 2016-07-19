#include <cstring>
#include <string>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;

int main()
{
    int lect, w;
    scanf("%d%d", &lect, &w);
    unordered_map<string, string> d;
    for(int i = 0; i < w; ++i)
    {
        string a,b;
        cin >> a >> b;
        if(a.size() <= b.size())
        {
            d.insert(make_pair(a,a));
        }
        else
            d.insert(make_pair(a,b));
    }
    for(int j = 0; j < lect; ++j)
    {
        string word;
        cin >> word;
        auto it = d.find(word);
        cout << it->second << " ";
    }
    return 0;
}
