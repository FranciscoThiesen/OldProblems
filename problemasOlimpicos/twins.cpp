#include <cstdio>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	vector<int> v;
	int total = 0.0;
	for(int i = 0; i < n; i++)
	{
		int x;
		scanf("%d", &x);
		v.push_back(x);
		total += x;
	}
	sort(v.begin(), v.end());
	int coins = 0;
	int value = 0;
	for(int j = n - 1; j >= 0; j--)
	{
		value += v[j];
		coins++;
		if( value > ceil(total/2))
		{
			break;
		}
	}
	printf("%d\n",coins);
	return 0;
}