// https://www.codechef.com/ZCOPRAC/problems/ZCO12001
#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
	int n,x;
	cin >> n;
	int mxLvl = -1;
	int openMxLvl = -1;
	
	int mxSize = -1;
	int startMxSize = -1;
	int seqSize = 0;
	int open = 0;
	int curStart = 0;
	for(int i = 0; i < n; ++i)
	{
		cin >> x;
		if(x == 1)
		{
			if(open == 0)
			{
				open = 1;
				curStart = i;
				seqSize = 1;
			}
			else
			{
				open++;
				seqSize++;
			}
			if(seqSize > mxSize)
			{
				mxSize = seqSize;
				startMxSize = curStart;
			}
			if(open > mxLvl)
			{
				mxLvl = open;
				openMxLvl = i;
			}
		}
		else if(x == 2)
		{
			open--;
			seqSize++;
			if(seqSize > mxSize)
			{
				mxSize = seqSize;
				startMxSize = curStart;
			}
		}
		//printf("open = %d\n mxLvl = %d\nopenMxLvl = %d\n i = %d\n\n",mxLvl, open, openMxLvl, i);
	}
	cout << mxLvl << " " << openMxLvl+1 << " " << mxSize << " " << startMxSize+1 << endl;
	return 0;
} 