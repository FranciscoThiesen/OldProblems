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

#define bit(x,i) (x &( 1 <<i))

char* toBin(int n)
{
	string a;
	for(int i = 4; i >= 0; --i)
	{	
		//cout << bit(t,i);
		if(bit(n,i))
		 	a += '1';
		else
		 	a += '0';
	}

	char* str = (char*)malloc(a.size() * sizeof(char));

	for(int i = 0; i < a.size(); i++)
	{
		str[i] = a[i];
	}


	return str;
}


int main()
{
	int N, R, C;
	string ronaldo;
	scanf("%d", &N);
	for (int z = 0; z < N; ++z)
	{
		char m[25][25];
		char str[100];
		char str2[500];
		memset(m, 0, sizeof(m));
		memset(str, 0, sizeof(str));
		memset(str2, 0, sizeof(str2));

		cin >> R >> C;
		getline(cin, ronaldo);
		for(int i = 1; i < ronaldo.size(); i++)
		{
			str[i-1] = ronaldo[i];
		}
		int i=0;
		while(str[i] != '\0')
		{
			if(str[i]==' ')
			{
				for (int k = 0; k < 5; ++k)
				{
					str2[k+5*i] = '0';
				}
				i++;
				continue;
			}
			char* temp = toBin(str[i]-'A'+1);
			for(int k=0; k<5; k++)
			{
				str2[k+5*i] = temp[k];
			}
			i++;
		}
		int len = strlen(str2); 
		while( len < R*C )
		{
			str2[len] = '0';
			len++;
		}
		str2[len] = '\0';

		int k=0, j=0, dir=3, up=0, left=-1, right=0, down=-1;
		i=0;
		while(k<len)
		{
			m[i][j] = str2[k]; k++;
			
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
		printf("%d ", z+1);
		for (int i = 0; i < R; ++i)
		{
			for (int j = 0; j < C; ++j)
			{
				printf("%c", m[i][j]);
			}
		}
		printf("\n");
	}
	
}