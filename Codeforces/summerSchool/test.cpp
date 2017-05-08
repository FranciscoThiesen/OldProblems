#include <vector>
#include <algorithm>
#include <cstdio>
#include <utility>
#include <numeric>
#include <iostream>
#include <iterator>
#include <map>

using namespace std;
#define pb push_back
int main()
{
	map<int, vector<pair<int, int> > > n;
	for(int i = 0; i < 10; ++i)
	{
		for(int j = 0; j < 10; ++j)
			n[i].pb(make_pair(j, -1));

	}
	auto it = upper_bound(n[2].begin(), n[2].end(), make_pair(5, -1));
	
	cout << (*it).first << endl;
	return 0;
}