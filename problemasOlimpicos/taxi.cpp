#include <cstdio>
#include <math.h>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
int main()
{
	int n;
	scanf("%d", &n);
	int taxi = 0;
	vector<int> kids(n);
	for( int i = 0; i < n; i++)
	{
		scanf("%d", &kids[i]);
	}
	sort(kids.end(), kids.begin());
	kids.push_back(-1);
	cout << kids[0] << kids[n-1] << endl;
	// for( int i = 0; i < n; i++)
	// {
	// 	if(kids[i] == -1)
	// 	{
	// 		printf("%d\n", taxi);
	// 		return 0;
	// 	}
	// 	if(kids[i] == 4)
	// 	{
	// 		taxi++;
	// 		kids[i] = 0;
	// 		if(kids[i + 1] == -1)
	// 		{
	// 			printf("%d\n", taxi);
	// 			return 0;
	// 		}
	// 	}
	// 	if(kids[i] == 3)
	// 	{
	// 		if(kids[i + 1] == -1)
	// 		{
	// 			taxi++;
	// 			printf("%d\n", taxi);
	// 			return 0;
	// 		}
	// 		for(int j = i + 1; j < n; j++)
	// 		{
	// 			if(kids[j] == 1)
	// 			{
	// 				kids[i] = 0;
	// 				kids[j] = 0;
	// 				taxi++;
	// 			}
	// 		}
	// 	}
	// 	if(kids[i] == 2)
	// 	{
	// 		if(kids[i + 1] == -1)
	// 		{
	// 			taxi++;
	// 			printf("%d\n", taxi);
	// 			return 0;
	// 		}
	// 		for(int k = i + 1; k < n; k++)
	// 		{
	// 			if(kids[k] == 1)
	// 			{
	// 				if(kids[k+1] == 1)
	// 				{
	// 					kids[i] = 0;
	// 					kids[k] = 0;
	// 					kids[k + 1] = 0;
	// 					taxi++;
	// 					printf("%d\n", taxi);
	// 					return 0;
	// 				}
	// 				else
	// 				{
	// 					taxi++;
	// 					printf("%d\n", taxi);
	// 					return 0;
	// 				}
	// 			}
	// 			if(kids[k] == 2)
	// 			{
	// 				kids[k] = 0;
	// 				kids[i] = 0;
	// 				taxi++;
	// 				break;
	// 			}

	// 		}
	// 	}
	// 	if(kids[i] == 1)
	// 	{
	// 		if(kids[i + 1] == -1)
	// 		{
	// 			taxi++;
	// 			printf("%d\n", taxi);
	// 			return 0;
	// 		}
	// 		if(kids[i+3] == 1)
	// 		{
	// 			taxi++;
	// 			i = i + 3;
	// 		}
	// 	}
	// }
	return 0;
}