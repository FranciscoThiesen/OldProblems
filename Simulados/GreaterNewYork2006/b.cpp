#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <functional>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <set>
#include <cstring>
#include <string>

using namespace std;

int main(void)
{
	int test;
	cin >> test;
	int t = 1;
	while(test--)
	{
		double x;
		string y;
		cin >> x >> y;
		double ans;
		if(y == "kg")
		{
			ans = x*(2.2046);
			printf("%d %.4lf lb\n", t, ans);
		}
		else if(y == "l")
		{
			ans = x*(0.2642);
			printf("%d %.4lf g\n", t, ans);
		}
		else if(y == "lb")
		{
			ans = x*(0.4536);
			printf("%d %.4lf kg\n", t, ans);
		}
		else
		{
			ans = x*(3.7854);
			printf("%d %.4lf l\n", t, ans);
		}
		t++;
	}
	return 0;
}