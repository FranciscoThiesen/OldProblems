#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <utility>
#include <set>

using namespace std;
int main()
{
	int a;
	scanf("%d", &a);
	vector<int> nums(a);
	set<int> numz;
	long long int ans = 0;
	for(int i = 0; i < a; i++)
	{	
		int x;
		cin >> x;
		nums.push_back(x);
		if(numz.count(x) == 0)
		{
			ans += x;
			numz.insert(x);	
		}
		else
		{
			while(numz.count(x) != 0)
			{
				x--;
			}
			if(x >= 0)
			{
				ans += x;
				numz.insert(x);
			}
		}
	}

	cout << ans << endl;
	return 0;
}
