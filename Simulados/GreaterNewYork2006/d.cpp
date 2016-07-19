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
#include <istream>
#include <sstream>
using namespace std;

int strToInt(char* str)
{
	int sum = 0;
	for (int i = 0; i < 5; ++i)
	{
		if(str[i]=='1')
		{
			sum += pow(2, 4-i);
		}
	}
	return sum;
}


int main()
{
	int N, R, C;
	string ronaldo;
	scanf("%d", &N);
	for (int z = 0; z < N; ++z)
	{
		char solve[500];
		char m[25][25];
		char str[500];
		memset(m, 0, sizeof(m));
		memset(str, 0, sizeof(str));
		memset(solve, 0, sizeof(solve));
		cin >> R >> C;
		getline(cin, ronaldo);
		for(int i = 1; i < ronaldo.size(); i++)
		{
			str[i-1] = ronaldo[i];
		}

		for(int i =0; i<R; i++)
		{
			for(int j=0; j<C; j++)
			{
				m[i][j] = str[C*i+j];
			}
		}


		// for (int i = 0; i < R; ++i)
		// {
		// 	for (int j = 0; j < C; ++j)
		// 	{
		// 		printf("%c ", m[i][j]);
		// 	}
		// 	printf("\n");
		// }

		printf("%d ", z+1);
		int k=0, c=0, i=0, j=0, dir=3, up=0, left=-1, right=0, down=-1, count=0;
		char help[5];
		while(k<R*C)
		{
			help[c] = m[i][j]; k++;
			c++;
			if(c==5)
			{
				c=0;
				int pos = strToInt(help);
				if (pos==0)
				{
					solve[count] = ' ';
				}
				else
				{
					solve[count] = pos + 'A' - 1;
				}
				count++;
			}

			if(dir==0)
			{
				if(i+1==R-down)
				{
					dir = 1;
					left++;
				}
			}
			else if(dir==1)
			{
				if(j==left)
				{
					dir = 2;
					up++;

				}
			}
			else if(dir==2)
			{
				if(i==up)
				{
					dir = 3;
					right++;
				}
			}
			else if(dir==3)
			{
				if(j+1==C-right)
				{
					dir = 0;
					down++;
				}
			}


			if(dir==0)
			{
				i++;
				
			}
			else if(dir==1)
			{
				j--;
				
			}
			else if(dir==2)
			{
				i--;
				
			}
			else if(dir==3)
			{
				j++;
			}
		}
		while(solve[count-1]==' ')
		{
			count--;
		}
		solve[count]='\0';
		printf("%s", solve);
		printf("\n");
	}

}