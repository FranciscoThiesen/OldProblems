#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <functional>
#include <vector>
#include <unordered_map>
#include <utility>
#define mp make_pair
typedef long long ll;
typedef unsigned long long ull;

#define fi first
#define se second
using namespace std;

int main()
{
	int casosDeTeste;
	cin >> casosDeTeste;
	while(casosDeTeste--)
	{
		int s;
		scanf("%d", &s);
		unordered_map<ll, pair<ll, ll> > minmax;
		ll dist[100010];
		ll cost[100010];
		for (int i = 0; i < s; ++i)
			scanf("%lld %lld", &dist[i], &cost[i]);
		vector<ll> profit(s, 0);// lucro maximo ao comprar no dia s
		profit[s-1] = -cost[s-1];
		minmax[profit[s-1]] = mp(cost[s-1], dist[s-1]);// valor min e max, inicializado para o valor do ultimo dia...
		/*profit[s - 2] = max(profit[s - 1], max(profit[s - 1] + (minmax[profit[s - 1]].first - arr[s - 2] - t), profit[s - 1] + minmax[profit[s - 1]].second - arr[s - 2] - t));
		if (profit[s - 2] == profit[s - 1])
		{
			if (arr[s - 2] < minmax[profit[s - 1]].first)
				minmax[profit[s - 2]] = mp(arr[s - 2], minmax[profit[s - 2]].second);
			else if (arr[s - 2] > minmax[profit[s - 1]].second)
				minmax[profit[s - 2]] = mp(minmax[profit[s - 2]].first, arr[s - 2]);
		}
		else
			minmax[profit[s - 2]] = mp(arr[s - 2], arr[s - 2]);*/
		for (int i = s - 2; i >= 0; --i)
		{
			// comecando do penultimo elemento
			if (profit[i + 1] != 0) // se o lucro maximo possivel do dia seguinte eh != 0
			{
				profit[i] = max(profit[i + 1], max(profit[i + 1] + (minmax[profit[i + 1]].first - cost[i]) + (minmax[profit[i+1]].second - dist[i]) * dist[i],profit[i + 1] + (minmax[profit[i + 1]].second - dist[i])*dist[i] - cost[i]));
				//lucro de hoje eh o max(lucro do dia seguinte, lucro do dia seguinte + (menorValor - valorDoDia), lucro do dia seguinte + (maiorValor - valorDoDia - custo)
				/* 
				 * Esse max acima engloba 3 casos
				 * 1 - não é benéfico comprar nesse dia
				 * 2 - ao invez de ter comprado no dia seguinte, eu compro no dia de hoje, por isso nao preciso contar dnv a taxa
				 * 3 - vale a pena comprar hoje pagando a taxa para vender amanha
				*/

				if (profit[i] == profit[i + 1])
				{
					if (cost[i] < minmax[profit[i + 1]].first)
						minmax[profit[i]] = mp(cost[i], minmax[profit[i]].second);
					else if (dist[i] > minmax[profit[i + 1]].second)
						minmax[profit[i]] = mp(minmax[profit[i]].first, dist[i]);
				}
				else
					minmax[profit[i]] = mp(cost[i], dist[i]);
			}
			/*if (profit[i + 1] == 0)
			{
				profit[i] = max(profit[i + 1], max(profit[i + 1] + (minmax[profit[i + 1]].first - arr[i]-t), profit[i + 1] + minmax[profit[i + 1]].second - arr[i] - t));
				if (profit[i] == profit[i + 1])
				{
					if (arr[i] < minmax[profit[i + 1]].first)
						minmax[profit[i]] = mp(arr[i], minmax[profit[i]].second);
					else if (arr[i] > minmax[profit[i + 1]].second)
						minmax[profit[i]] = mp(minmax[profit[i]].first, arr[i]);
				}
				else
					minmax[profit[i]] = mp(arr[i], arr[i]);
			}*/
		}
		if(profit[0] <= 0)
		{
			printf("Perde %lld\n", profit[0]);
		}
		else
			printf("Ganha %lld\n", profit[0]);
	}
	return 0;
}
