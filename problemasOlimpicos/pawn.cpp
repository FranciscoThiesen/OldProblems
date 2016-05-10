#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;
int main()
{
	char table[8][8];
	int b[8] = {0,0,0,0,0,0,0,0};
	int w[8] = {10,10,10,10,10,10,10,10};
	int bmin[8] = {10,10,10,10,10,10,10,10};
	int wmin[8] = {0,0,0,0,0,0,0,0};
	int whitemoves = 1000;
	int blackmoves = 1000;
	for(int i = 0; i < 8;i++)
		for(int j = 0; j < 8; j++)
		{
			cin >> table[i][j];
		}	
	for(int j = 0; j < 8;j++)
		for(int i = 0; i < 8; i++)
		{
			if(table[i][j] == 'B')
				if( j > b[j])
					b[j] = j;
			if(table[i][j] == 'B')
				if( j < bmin[j])
					bmin[j] = j;
			if(table[i][j] == 'W')
				if( j > wmin[j])
					wmin[j] = j;
			if(table[i][j] == 'W')
				if( j < w[j])
					w[j] = j;

		}
	for(int x = 0; x < 8; x++)
	{
		if(b[x] > 0 && b[x] > wmin[x])
			if( 8 - b[x] < blackmoves)
				blackmoves = 8 - b[x];
		if(w[x] < 10 && w[x] < bmin[x])
			if( w[x] < whitemoves)
				whitemoves = w[x];
	}
	if(whitemoves <= blackmoves)
	{
		printf("A %d %d\n", whitemoves, blackmoves);
		return 0;
	}
	else
		printf("B %d %d\n", whitemoves, blackmoves);
	
	return 0;
}