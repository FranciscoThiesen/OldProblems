#include <cstdio>
#include <string.h>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
char mat[21][101];

int main()
{
	int a = 1;
	while(a != 0)
	{
		scanf("%d", &a);
		string ans;
		string p;
		if(a == 0)
			return 0;
		else
		{
			cin >> p;
		}
		int siz = (int)p.size()/a;
		for(int i = 0; i < siz;i++)
		{
			if(i%2 == 0)
			{
				for(int y = i*a; y < i*a + a; y++)
				{
					mat[y-(i*a)][i] = p[y];
					//ans += p[y];
				}
			}
			else
			{
				//string a;
				for(int x = i*a + a-1; x >= i*a;x--)
				{
					mat[(i*a+a-1)-x][i] = p[x];
					//ans += p[x];
				}
			}
		}
		for(int f = 0; f < a; f++)
			for(int g = 0; g < siz; g++)
				ans += mat[f][g];

		// for(int f = 0; f < siz; f++)
		// {
		// 	for(int g = 0; g < a; g++)
		// 	{
		// 		cout << mat[g][f];
		// 	}	
		// 	cout << endl;
		// }
		cout << ans << endl;
	}
	return 0;
}