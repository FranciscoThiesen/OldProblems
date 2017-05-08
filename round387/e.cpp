/*input
64
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

vector<vector<string> > lvls(1000000);
vector<pair<string, int > > tree;

void readDesc(int lvl, int n, int treePos)
{
	if(n == 0)
		return;
	for(int j = 0; j < n; ++j)
	{
		for(int i = treePos + 1; i < tree.size(); ++i)
		{

		}
	}
	for(int i = treePos + 1; i < tree.size(); ++i)
	{
	}
}
int main()
{
	string k;
	cin >> k;
	for(int i = 0; i < k.size(); ++i)
	{
		string word;
		string num;
		bool w = true;
		if(w)
		{
			if(k[i] != ',')
				word += k[i];
			else
				w = false;
		}
		else if(!w)
		{
			if(k[i] != ',')
				num += k[i];
			else
			{	
				w = true;
				tree.pb(mp(word, stoi(num)));
			}
		}
	}

	//lvls[0].pb(tree[0].first);
	for(int i = 0; i < tree.size(); ++i)
	{
	}

}