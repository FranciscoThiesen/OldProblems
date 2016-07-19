#include <cstdio>
#include <cstring>
#include <utility>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int s, r = 1;
    while(s + r != 0)
    {
        scanf("%d%d", &s, &r);
        if(s + r == 0)
            return 0;
        string pav;
        cin >> pav;
        vector<pair<int, int> > let;
        vector<pair<int, int> > let2;
        for(int x = 0; x < pav.size(); x++)
        {
            let.push_back(make_pair(pav[x] - '0', x));
        }
        sort(let.rbegin(),let.rend());
        for(int u = 0; u < s-r; u++)
            let2.push_back(make_pair(let[u].second, let[u].first));
        sort(let2.begin(), let2.end());
        for(int b = 0; b < s-r; b++)
            cout << let2[b].second;
        //cout << let[0].second << endl;
        cout << endl;
    }
    return 0;
}
