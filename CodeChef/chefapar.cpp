// https://www.codechef.com/FEB17/problems/CHEFAPAR
#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(v) (v).begin(), (v).end()
 
typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> ii;
 
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n;
		scanf("%d", &n);
		vi vec(n);
		int resp = 0;
		for(int i = 0; i < n; ++i)
		{
			cin >> vec[i];
		}
		int firstZero = -1;
		int countOne = 0;
		for(int i = 0; i < n; ++i)
		{
			if(vec[i] == 0 && firstZero == -1)
			{
				firstZero = i;
				resp += 100*(n-i);
			}
			else if(vec[i] == 1)
				countOne++;
		}
		resp += (n-countOne)*1000;
		printf("%d\n", resp);
	}
	return 0;
} 