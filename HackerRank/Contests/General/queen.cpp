#include <cstdio>
#include <vector>
#include <utility>
#include <map>
#include <string>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <limits>
#include <tuple>

using namespace std;

#define mt make_tuple
int main()
{
	int n, k, r c;
	cin >> n >> k >> r >> c;
	
	//left 1
	//right 2
	//up 3
	//down 4
 	//lowerLeftDiag 5
	//lowerRightDiag 6
	//upperleftDiag 7
	//upperRightDiag 8
	tuple<int, int, int> left;
	tuple<int, int, int> right;
	tuple<int, int, int> up;
	tuple<int, int, int> down;
	tuple<int, int, int> lowerLeftDiag;
	tuple<int, int, int> lowerRightDiag;
	tuple<int, int, int> upperLeftDiag;
	tuple<int, int, int> upperRightDiag;
	tuple<int, int, int> right;
	int inf = numeric_limits<int>::max();
	left = mt(0, 0, numeric_limits<int>::max());
	right = mt(0, 0, numeric_limits<int>::max());
	up = mt(0, 0, numeric_limits<int>::max());
	down = mt(0, 0, numeric_limits<int>::max());
 	lowerLeftDiag = mt(0, 0, numeric_limits<int>::max());
	lowerRightDiag = mt(0, 0, numeric_limits<int>::max());
	upperleftDiag = mt(0, 0, numeric_limits<int>::max());
	upperRightDiag = mt(0, 0, numeric_limits<int>::max());
	for(int i = 0; i < k; ++i)
	{
		int x, y;
		cin >> x >> y;
		if(x == r)
		{
			if(y > c)
			{
				if(get<2>(right) > y-c)
				{
					get<0>(right) = x;
					get<1>(right) = y;
					get<2>(right) = y-c;
				}
			}
			if(y < c)
			{
				if(get<2>(left) > y-c)
				{
					get<0>(left) = x;
					get<1>(left) = y;
					get<2>(left) = c-y;
				}
			}
		}
		else if(y == c)
		{
			if(r > x)
			{
				if(get<2>(down) > x-r)
				{
					get<0>(down) = x;
					get<1>(down) = y;
					get<2>(down) = r-x;
				}
			}
			if(x > r)
			{
				if(get<2>(up) > r-x)
				{
					get<0>(up) = x;
					get<1>(up) = y;
					get<2>(up) = x-r;
				}
			}
		}
		else if(abs(x-c) == abs(y-d))
		{
			if(x > r && y > c)//lowerRightDiag
			{
				if(get<2>(upperRightDiag) > x-r)
				{
					get<0>(upperRightDiag) = x;
					get<1>(upperRightDiag) = y;
					get<2>(upperRightDiag) = x-r;
				}
			}
			if(x > r && y < c)//lowerLeftDiag
			{
				if(get<2>(upperLeftDiag) > x-r)
				{
					get<0>(upperLeftDiag) = x;
					get<1>(upperLeftDiag) = y;
					get<2>(upperLeftDiag) = x-r;
				}
			}
			if(x < r && y < c)//upperLeftDiag
			{
				if(get<2>(lowerLeftDiag) > r-x)
				{
					get<0>(lowerLeftDiag) = x;
					get<1>(lowerLeftDiag) = y;
					get<2>(lowerLeftDiag) = r-x;
				}
			}
			if(x < r && y < c)//upperRightDiag
			{
				if(get<2>(lowerRightDiag) > r-x)
				{
					get<0>(lowerRightDiag) = x;
					get<1>(lowerRightDiag) = y;
					get<2>(lowerRightDiag) = r-x;
				}
			}
		}
	}
	unsigned long long ans = 0;
	//calculating number of cells under attack
	if(get<2>(left) != inf)
	{
		ans+= (c-1) - (c-(get<2>(left));
	}
	else
		ans += (c-1);
	if(get<2>(right) != inf)
	{
		ans+= get<2>(right)-1;
	}
	else
		ans += n - c;


	if(get<2>(up) != inf)
	{
		ans += (n - r) - (n - (r+get<2>(up) + 1);
	}
	else
		ans += n-r;

	if(get<2>(down) != inf)
	{
		ans += (r-1)
	}

}