#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;
int arr[100001];
int aux[100001];
int max1[100001];
int maux1[100001];
unsigned long long int total = 0;

int main()
{
	int r, c = 1;
	while(r + c > 0)
	{
		scanf("%d%d", &r, &c);
		if(c + r == 0)
			return 0;
		for(int i = 0; i < r; i++)
		{
			max1[i] = 0;
			for(int j = 0; j < c; j++)
			{
				scanf("%d", &arr[j]);
				if(j == 0)
					aux[j] = arr[j];
				else if(j == 1)
					aux[j] = max(arr[j], arr[j-1]);
				else
					aux[j] = max(aux[j-2] + arr[j], aux[j-1]);
				if(aux[j] > max1[i])
					max1[i] = aux[j];

			}
		}
		total = 0;
		for(int u = 0; u < r; u++)
		{
			if(u == 0)
				maux1[u] = max1[u];
			if(u == 1)
				maux1[u] = max(max1[u], max1[u-1]);
			else
				maux1[u] = max(maux1[u-2] + max1[u], maux1[u-1]);
			if(maux1[u] > total)
				total = maux1[u];
		}
		cout << total << endl;
	}
	return 0;
}