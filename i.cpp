#include <bits/stdc++.h>
#define INT 1000*1000*1000
using namespace std;

int ways(int peso, vector<bool> disponivel, vector<int> valores, int menor, int segundoMenor int minIndisponivel)
{
	int resp = 0;
	bool algm = false;
	for(int i = 0; i < disponivel.size(); ++i)
	{
		if(disponivel[i])
		{
			algm = true;
			disponivel[i] = false;
			if(valores[i] == menor)
			{
				menor = segundoMenor;
				segundoMenor = INF;
				for(int j = i+1; j < disponivel.size(); ++j)
				{
					if(disponivel[j])
					{
						segundoMenor = valores[j];
						break;
					}
				}
			}
			if(valores[i] == segundoMenor)
			{
				segundoMenor == INF;
				for(int j = i + 1; j < disponivel.size(); ++j)
				{
					if(disponivel[j])
					{
						segundoMenor = valores[j];
						break;
					}
				}
			}
			if(peso - valores[i] < menor)
			{
				resp++;
			}
			else
			{
				resp += ways(peso - valores[i], disponivel, valores, menor, segundoMenor, minIndisponivel);
				
			}
		}
	}
	if(!algm)
	{
		if(peso < minIndisponivel)
			resp++;
	}
	return resp;
}



int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	for(int i = 0; i < t; ++i)
	{
		int n, d;
		cin >> n >> d;
		vector<bool> disp(n, true);
		int minIndisp = INF;
		vector<int> vals(n);
		for(int i = 0; i < n; ++i)
			cin >> vals[i];
		sort(vals.begin(), vals.end());
		int menor = 
	}

}
