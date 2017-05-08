#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <utility>
#define pb push_back
#define mp make_pair
#define se second
#define fi first
using namespace std;

vector<pair<int, int> > ini;
vector<pair<int, int> > fim;
int fotos[1000010];

int bb(pair<int, int> v)
{
	int a = 0, b = ini.size();
	int meio;
	while(a<=b)
	{
		meio = (a+b)/2;
		if(ini[meio].fi == v.fi)
		{
			if(ini[meio].se == v.se)
				return meio;
			else if(ini[meio].se < v.se)
				a = meio + 1;
			else
				b = meio - 1;
		}
		else if(ini[meio].fi < v.fi)
			a = meio + 1;
		else
			b = meio - 1;

	}

	if(meio >= ini.size())
		return ini.size() - 1;
	if(ini[meio + 1].fi == v.fi)
		return meio + 1;
	if(ini[meio].fi > v.fi)
		return meio-1;
	return meio;
}

int main()
{
	int N;
	while(scanf("%d", &N) != EOF)
	{
		ini.clear();
		fim.clear();
		int foto = 0;
		memset(fotos, 0, sizeof(fotos));
		
		for(int i = 0; i < N; i++)
		{
			int a, b;
			cin >> a >> b;
			ini.pb(mp(a, b));
			fim.pb(mp(b, a));
		}

		sort(ini.begin(), ini.end());
		sort(fim.begin(), fim.end());

		// int sizeF = fim.size();
		// for (int i = 1; i < sizeF; ++i)
		// {
		// 	if(fim[i] == fim[i-1])
		// 	{
		// 		fim.erase(fim.begin()+i);
		// 		sizeF--;
		// 		i--;
		// 	}
		// }

		// int sizeI = ini.size();
		// for (int i = 1; i < sizeI; ++i)
		// {
		// 	if(ini[i] == ini[i-1])
		// 	{
		// 		ini.erase(ini.begin()+i);
		// 		sizeI--;
		// 		i--;
		// 	}
		// }

		//cout << bb(mp(5, 13)) << endl;

		for (int i = 0; i < fim.size(); ++i)
		{
			int posI = bb(mp(fim[i].se, fim[i].fi));

			if(!fotos[posI])
			{
				posI = bb(fim[i]);
				for(int j = posI; fotos[j] == 0 || j >= 0; j--)
				{
					fotos[j] = 1;
				}
				foto++;
			}
		}
		// for(int i = 0; i < (int)v.size(); i++)
		// {
		// 	cout << v[i].fi << " " << v[i].se << endl; 
		// }

		// int foto = 0;

		// for(int i = 1; i < (int)v.size(); i++)
		// {
		// 	if(v[i].se == 1 && v[i - 1].se == 0)
		// 		foto++;
		// }

		cout << foto << endl;
	}
	return 0;
}