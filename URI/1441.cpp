#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
unsigned long long maxCollatz(ull n)
{
	ull init = n;
	ull mx = 0;
	while(init > 1)
	{
		if(init%2)
			init/=2;
		else
		{
			init *= 3;
			init++;
		}
		if(init > mx)
			mx = init;
	}
	return mx;
}

int main()
{
	ull n;
	ios::sync_with_stdio(false);
	while(cin >> n)
	{
		if(!n)
			return 0;
		else
			cout << maxCollatz(n) << endl;
	}
	return 0;
}