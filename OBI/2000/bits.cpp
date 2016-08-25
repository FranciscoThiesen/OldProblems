#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	int test = 1;
	while(cin >> n)
	{
		if(n)
		{
			int n50 = 0;
			int n10 = 0;
			int n5 = 0;
			int n1 = 0;
			n50 += n/50;
			n %= 50;
			n10 += n/10;
			n %= 10;
			n5 += n/5;
			n %= 5;
			n1 += n/1;
			n %= 1;
			printf("Teste %d\n%d %d %d %d\n\n", test, n50, n10, n5, n1);
			test++;
		}
	}
	return 0;
}