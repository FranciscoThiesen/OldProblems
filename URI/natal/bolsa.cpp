#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <functional>
#include <vector>
#include <unordered_map>
#include <utility>
#define mp make_pair


using namespace std;

int main()
{
	int s, t;
	scanf("%d %d", &s, &t);
	unordered_map<int, pair<int, int> > minmax;
	int arr[200010];
	for (int i = 0; i < s; ++i)
		scanf("%d", &arr[i]);
	vector<int> profit(s, 0);// lucro maximo ao comprar no dia s
	minmax[0] = mp(arr[s - 1], arr[s - 1]);// valor min e max, inicializado para o valor do ultimo dia...
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
			profit[i] = max(profit[i + 1], max(profit[i + 1] + (minmax[profit[i + 1]].first - arr[i]), profit[i + 1] + minmax[profit[i + 1]].second - arr[i] - t));
			//lucro de hoje eh o max(lucro do dia seguinte, lucro do dia seguinte + (menorValor - valorDoDia), lucro do dia seguinte + (maiorValor - valorDoDia - custo)
			/* 
			 * Esse max acima engloba 3 casos
			 * 1 - não é benéfico comprar nesse dia
			 * 2 - ao invez de ter comprado no dia seguinte, eu compro no dia de hoje, por isso nao preciso contar dnv a taxa
			 * 3 - vale a pena comprar hoje pagando a taxa para vender amanha
			*/

			if (profit[i] == profit[i + 1])
			{
				if (arr[i] < minmax[profit[i + 1]].first)
					minmax[profit[i]] = mp(arr[i], minmax[profit[i]].second);
				else if (arr[i] > minmax[profit[i + 1]].second)
					minmax[profit[i]] = mp(minmax[profit[i]].first, arr[i]);
			}
			else
				minmax[profit[i]] = mp(arr[i], arr[i]);
		}
		if (profit[i + 1] == 0)
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
		}
	}
	cout << profit[0] << endl;
	return 0;
}
