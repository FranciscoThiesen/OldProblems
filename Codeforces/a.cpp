#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int main()
{

	int n;
	scanf("%d", &n);
	vector<int> nums;
	int minPos;
	int maxPos;
	for(int i = 0; i < n; ++i)
	{
		int a;
		scanf("%d", &a);
		if(a == 1)
			minPos = i;
		else if( a == n)
			maxPos = i;
		nums.push_back(a);
	}
	int dist = abs(maxPos-minPos);
	dist = max(dist, minPos - 0);
	dist = max(dist, maxPos - 0);
	dist = max(dist, max(abs(n-1-minPos), abs(n-1-maxPos)));
	int minDistBeg = minPos;
	int minDistEnd = n-1-minPos;
	int maxDistBeg = maxPos;
	int maxDistEnd = n-1-maxPos;
	if(n == 3)
	{
		if(abs(maxPos-minPos) == 2)
			dist = 1;
	}
	else if(n == 4)
	{
		if(abs(maxPos-minPos) == 3)
			dist = 2;
	}
	cout << dist << endl;
	return 0;
}