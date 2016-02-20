#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#define INF 1000000000
using namespace std;
int main()
{
	int nodes, edges;
	scanf("%d%d",&nodes, &edges);
	int dist[nodes][nodes];
	for(int i = 0; i < nodes; i++)
	{
		for(int j = 0; j < nodes; j++)
		{
			if(i == j)
				dist[i][j] = 0;
			else
				dist[i][j] = INF;
		}
	}
	for(int e = 0; e < edges; e++)
	{
		int a, b, d;
		cin >> a >> b >> d;
		dist[a-1][b-1] = d;
	}
	for(int z = 0; z < nodes; z++)
	{
		for(int x = 0; x < nodes; x++)
		{
			for(int y = 0; y < nodes; y++)
			{	
				dist[x][y] = min(dist[x][y],dist[x][z] + dist[z][y]);
			}
		}
	}
	int q;
	scanf("%d", &q);
	for(int w = 0; w < q; w++)
	{
		int r, i;
		cin >> r >> i;
		if(dist[r-1][i-1] == INF)
			cout << "-1" << endl;
		else
			cout << dist[r-1][i-1] << endl;
	}
	return 0;
}
