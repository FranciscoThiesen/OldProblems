/*input
4
AA??
*/

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cmath>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <string>

using namespace std;


#define gcd __gcd
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define IOS ios::sync_with_stdio(0);

typedef long long ll;
typedef unsigned long long ull;


int main()
{
	int x;
	IOS
	cin >> x;
	string s;
	cin >> s;
	int a = 0, g = 0, c = 0, t = 0;
	int unmarked = 0;
	vector<int> pos;
	for(int i = 0; i < s.size(); ++i)
	{
		if(s[i] == '?')
		{
			unmarked++;
			pos.pb(i);
		}
		else if(s[i] == 'A')
			a++;
		else if(s[i] == 'C')
			c++;
		else if(s[i] == 'G')
			g++;
		else if(s[i] == 'T')
			t++;
	}
	int mx = max(a, max(c, max(g,t)));
	int misA = mx - a;
	int misC = mx - c;
	int misG = mx - g;
	int misT = mx - t;
	string rep;
	for(int i = 0; i < misA;++i)
		rep += 'A';
	for(int i = 0; i < misC;++i)
		rep += 'C';
	for(int i = 0; i < misG;++i)
		rep += 'G';
	for(int i = 0; i < misT;++i)
		rep += 'T';
	if(unmarked < misA + misC + misG + misT)
	{
		cout << "===" << endl;
		return 0;
	}
	else
	{
		unmarked -= misA + misC + misG + misT;
		if(unmarked == 0)
		{
			for(int i = 0; i < rep.size(); ++i)
			{
				s[pos[i]] = rep[i];
			}
			cout << s << endl;
		}
		else if(unmarked%4 == 0)
		{
			int add = unmarked/4;
			for(int i = 0; i < add; ++i)
				rep += "ACTG";
			for(int i = 0; i < rep.size(); ++i)
			{
				s[pos[i]] = rep[i];
			}
			cout << s << endl;
		}
		else
		{
			cout << "===" << endl;
		}

	}
	return 0;
}