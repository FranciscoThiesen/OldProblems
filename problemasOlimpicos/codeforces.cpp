#include <vector>
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
int main()
{
	int n;
	scanf("%d", &n);
	int maxSequence = 1;
	int currentSequence = 1;
	int nums[n];
	for(int i = 0; i < n; i++)
		scanf("%d",&nums[i]);
	int beginpos = 0;
	int currentMax = nums[0] + 1;
	int currentMin = nums[0] - 1;
	for(int i = 1; i < n; i++)
	{
		if(nums[i] == currentMin && nums[i] != nums[beginpos])
			currentMax = currentMin + 1;
		if(nums[i] == currentMax && nums[i] != nums[beginpos])
			currentMin = currentMax - 1;
		if(nums[i] >= currentMin && nums[i] <= currentMax)
		{
			currentSequence++;
			if(currentSequence >= maxSequence)
				maxSequence = currentSequence;
		}
		else
		{
			currentSequence = 1;
			beginpos++;
			currentMax = nums[beginpos] + 1;
			currentMin = nums[beginpos] - 1;
			i = beginpos;
		}
	}
	printf("%d\n", maxSequence);
	return 0;
}