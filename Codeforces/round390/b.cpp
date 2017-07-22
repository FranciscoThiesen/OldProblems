/*input
8
9 -12 3 4 -4 -10 7 3
*/
#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

#define pb push_back
#define mp make_pair

int main()
{
	int n;
	cin >> n;
	vector<int> nums(n);
	int sum = 0;
	for(int i = 0; i < n; ++i)
	{
		cin >> nums[i];
		sum += nums[i];
	}
	if(sum != 0)
	{
		printf("YES\n1\n%d %d\n", 1, n);
		return 0;
	}
	else if(sum == 0)
	{
		int accu = 0;
		for(int i = 0; i < n; ++i)
		{
			accu += nums[i];
			if(accu != 0)
			{
				printf("YES\n2\n%d %d\n%d %d\n", 1, i+1, i+2, n);
				return 0;
			}
		}
	}
	cout << "NO" << endl;
	return 0;
}