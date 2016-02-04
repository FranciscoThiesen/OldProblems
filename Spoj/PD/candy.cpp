#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

int arr[100001][100001];

int main()
{
	int row, column = 1;
	while(row + column != 0)
	{
		unsigned long long tot = 0;
		scanf("%d%d", &row, &column);
		if(row + column == 0)
			return 0;
		for(int i = 0; i < row; i++)
			for(int j = 0; j < column; j++)
				scanf("%d", &arr[j][i]);
		int max[row];
		memset(max, 0, sizeof max);
		for(int v = 0; v < row; v++)
		{
			for(int f = 0; f < column; f++)
			{
				if(column == 1)
				{
					max[v] = arr[f][v];
					break;
				}
				if(f == 0)
				{
					if(arr[f][v] >= arr[f+1][v])
					{
						max[v] += arr[f][v];
						arr[f][v] = 0;
						arr[f+1][v] = 0;
					}
					else
						arr[f][v] = 0;
				}
				else if(f == column-1)
				{
					if(arr[f][v] > arr[f-1][v])
					{
						max[v] += arr[f][v];
						arr[f-1][v] = 0;
						arr[f][v] = 0;
					}
					max[v] += arr[f][v];
					max[v] += arr[0][v];
	 			}
	 			else
	 			{
	 				if(arr[f][v] >= arr[f-1][v] + arr[f+1][v])
	 				{
	 					arr[f+1][v] = 0;
	 					arr[f-1][v] = 0;
	 					max[v] += arr[f][v];
	 				}
	 			}
			}
		}
		if(row == 1)
		{
			cout << max[0] << endl;
			continue;
		}
		// for(int q = 0; q < row; q++)
		// 	cout << max[q] << endl;
		for(int e = 0; e < row; e++)
		{
			if(row == 1)
			{
				tot += max[e];
				break;
			}
			if(e == 0)
			{
				if(max[e] >= max[e+1])
				{
					tot += max[e];
					max[0] = 0;
					max[e+1] = 0;
				}

			}
			else if(e == row-1)
			{
				if(max[e] > max[e-1])
				{
					tot += max[e];
					max[e-1] = 0;
				}
				tot += max[0];
			}
			else
			{
				if(max[e] >= max[e-1] + max[e+1])
				{
					max[e+1] = 0;
					max[e-1] = 0;
					tot += max[e];
				}
			}
		}
		// for(int d = 0; d < row;d++);
		cout << tot << endl;
	}
	return 0;
}