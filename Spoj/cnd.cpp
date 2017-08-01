#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>

using namespace std;
int vec[10010];
int main()
{
	int a = 1;
	while(a != -1)
	{
		scanf("%d", &a);
		if(a == -1)
			return 0;
		int total = 0;
		int moves = 0;
		for(int i = 0; i < a; i++)
		{
			scanf("%d", &vec[i]);
			total += vec[i];
		}
		int avg = total/a;
		if(total%a != 0)
			cout << -1 << endl;
		else
		{
			for(int j = 0; j < a; j++)
			{
				if(vec[j] > avg)
					moves += vec[j] - avg;
			}
			cout << moves << endl;
		}

	}
	return 0;
}