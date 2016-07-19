#include <cstdio>
#include <iostream>
#include <cmath>
#include <vector>
#include <utility>
#include <string>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	vector<vector<string> > pal(100);
	for(int i = 0; i < n; ++i)
	{
		int a;
		string s;
		cin >> a >> s;
		pal[a].push_back(s);
	}
	for(int i = 0; i < 100; ++i)
	{
		for(int j = 0; j < pal[i].size(); ++j)
		{
			cout << i << " "  << endl;
		}
	}
	return 0;
}

