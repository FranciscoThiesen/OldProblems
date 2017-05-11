#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;

#define ll long long
int main()
{
	bool mat[1002][1002] = {{false}};
	vector<long long> ans(1003, 0);
	long long valid = 0;
	for(int x = 1; x < 1002; ++x)
	{
		for(int y = 0; y < x; ++y)
		{
			if(!mat[x][y])
			{
				mat[x][y] = true;
				valid++;
				int inc = 2;
				while(x*inc < 1002 && y*inc < 1002)
				{
					mat[x*inc][y*inc] = true;
					inc++;
				}
			}

		}
		ans[x] = 1 + valid*2;
	}
	int t;
	cin >> t;
	for(int i = 0; i < t; ++i)
	{
		int x;
		cin >> x;
		cout << i+1 << " " << x << " " << ans[x] << endl;
	}
	return 0;
}
