#include <cstdio>
#include <algorithm>
#include <string>
#include <cmath>
#include <iostream>
#include <utility>
#include <functional>
#include <vector>
using namespace std;

int main()
{
    string w;
    cin >> w;
    vector<pair<int, int> > Ba;
    vector<pair<int, int> > Ab;
    for(int i = 0; i < w.size(); ++i)
    {
        if(w[i] == 'A' && w[i+1] == 'B')
            Ab.push_back(make_pair(i, i+1));
        else if(w[i] == 'B' && w[i+1] == 'A')
            Ba.push_back(make_pair(i, i+1));
    }
    bool pos = false;
    for(auto& p : Ab)
    {
        for(auto& t : Ba)
        {
            if(p.first != t.second && p.second != t.first)
            {
                pos = true;
                cout << "YES" << endl;
                return 0;
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}
