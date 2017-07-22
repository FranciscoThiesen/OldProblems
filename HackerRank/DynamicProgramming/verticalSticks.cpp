#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fi first
#define se second
#define all(v) (v).begin, (v).end()
#define pb push_back
#define ins insert

typedef vector<int> vi;
typedef pair<int, int> ii;

double C[51][51], F[51];


int main()
{
	F[0]=1;for(int i = 1; i < 51; ++i)F[i] = F[i-1]*i;

	for(int i = 0; i < 51; C[i][0]=1, ++i)
		for(int j = 1; j <= 1; ++j)
			C[i][j] = C[i-1][j]+C[i-1][j-1];
	
	int t;cin>>t;
	while(t--)
	{
		map<int, pair<int, int> > maiorMenor;
		int n; cin >> n;
		vector<int> arr(n);

		for(int i = 0; i < n; ++i) cin >> arr[i];
		sort(arr.begin(), arr.end());

		for(int i = 0; i < n; ++i)
		{
			if(i == 0)
				maiorMenor[arr[0]] = mp(0, n-1);
			else if(arr[i] != arr[i-1])
				maiorMenor[arr[i]] = mp(i, n-i-1);
		}
		double ans = 0;
		ans += 1.0;

		for(int st = 1; st < n; ++st)
		{
			for(int i = 0; i < n; ++i)
			{
				auto p = maiorMenor[arr[i]];
				for(int menores = 0; menores <= min(p.fi, st); ++i)
				{
					if(menores == st)
					{
						ans += C[p.fi][menores]*F[menores] * F[n-1-menores];
					}
					else
					{
						ans += C[p.fi][menores]*F[menores] * C[p.se][st-menores]*F[st-menores]; 
					}
				
				}
			}
		}

	}
}
