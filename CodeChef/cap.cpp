#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fi first
#define se second
#define pb push_back

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		vector<pair<int, int> > popu(n);
		for(int i = 0; i < n; ++i)
		{
			int x;
			cin >> x;
			popu[i] = mp(x, i);
		}
		sort(popu.rbegin(), popu.rend());
		//ordenando por populacao

		//preenchendo uma tabela p dizer que o cara um equivale ao indice 3 apos ordenar o vetor
		vector<unordered_set<int> > adjList(n);
		for(int i = 0; i < n-1; ++i)
		{
			int s, t;
			cin >> s >> t;
			adjList[s-1].insert(t-1);
			adjList[t-1].insert(s-1);
		}

		for(int i = 0; i < n; ++i)
		{
			int ans = 0;
			for(int j = 0; j < n; ++j)
			{
				if(popu[j].se != i && adjList[i].find(popu[j].se) == adjList[i].end() )
				{
					ans = popu[j].se + 1;
					break;
				}
			}
			cout << ans << " ";
		}
		cout << endl;
	}
}