/*input
4 2
3759
6 3
123123
7 4
1000000
7 3
1001234
6 2
103759
0 0
*/

#include <vector>
#include <utility>
#include <iostream>
#include <cmath>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstdlib>
#include <stack>
#include <deque>
#include <queue>
#define ins insert
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
    int n = 1, d = 1;
    while(n + d != 0)
    {
    	cin >> n >> d;
        if(n+d == 0)
        {
            return 0;
        }
        string s;
        cin >> s;
        multimap<int, int> digs;
        for(int i = 0; i < n; ++i)
        {
        	digs.ins(mp(s[i]-'0', i));
        }
        map<int, int> printable;
        for(auto it = digs.begin(); it != digs.end();++it)
        {
        	if(d > 0)
                d--;
            else
                printable.ins(mp(it->second, it->first));
            
        }
        for(auto& p : printable)
        	cout << p.se;
        cout << endl;
    }
    return 0;
}
