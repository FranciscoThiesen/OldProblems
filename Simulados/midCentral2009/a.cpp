#include <stdio.h>
#include <iostream>
#include <queue>
#include <algorithm>
#include <utility>
#include <vector>
#include <functional>
#include <map>
#define fi first
#define se second
#define pb push_back
#define mk make_pair
#define mp make_pair
#define TRACE 1
using namespace std;

map<int, vector<pair<int, int> > > graph;
vector<pair<int, int> > coisas;
int w,s,p;


int calcCusto(int pos, int fim)
{

	int result = 0;
	int oldPos = pos;
	for (int i = 0; i < p; ++i)
	{
		if((coisas[i].fi-pos)%s==0)
		{
			pos = coisas[i].fi - 1;
			for (int j = 0; j < p; ++j)
			{
				if(coisas[j].fi==pos)
				{
					pos--;
					j=0;
				}
			}
		}
		else
		{
			pos = coisas[i].fi;
			for (int j = 0; j < p; ++j)
			{
				if(coisas[j].fi==pos)
				{
					pos--;
					j=0;
				}
			}
		}
		if(pos == oldPos)
			return -1;
		result += ((coisas[i].fi-pos)/s);
	}
	return result+1;
}

int main()
{
	ios::sync_with_stdio(false);

	while(scanf("%d %d %d", &w, &s, &p), w!=0)
	{
		for (int i = 0; i < p; ++i)
		{
			int a,b;
			cin >>  a >> b;
			pair<int, int> k = mp(0, b);
			graph[a].pb(k);
			coisas.pb(mp(a, b));
		}

		for (int i = 0; i < p; ++i)
		{
			int ini = coisas[i].fi;
			int fim = coisas[i].se;

			for (int j = 0; j < p; ++j)
			{
				if(i!=j)
				{
					if(coisas[i].se < coisas[j].fi)
					{
						graph[coisas[i].se].pb(mk(calcCusto(coisas[i].se, coisas[j].fi), coisas[j].fi));
					}

					if(coisas[i].se < coisas[j].se)
					{
						graph[coisas[i].se].pb(mk(calcCusto(coisas[i].se, coisas[j].se), coisas[j].se));
					}
				}
			}

			graph[0].pb(mk(calcCusto(0, ini), ini));
			graph[0].pb(mk(calcCusto(0, fim), fim));
		}

		map<int, int> visitados;
		map<int, int> custos;
		
		for(int i = 0; i<p; i++)
		{
			visitados[coisas[i].fi] = 0;
			custos[coisas[i].fi] = -1;
			visitados[coisas[i].se] = 0;
			custos[coisas[i].se] = -1;
		}

		custos[0] = -1;
		visitados[0] = 0;
		custos[w] = -1;
		visitados[w] = -1;

		priority_queue< pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
		pq.push(make_pair(0,0));
		while(!pq.empty())
		{
			pair<int, int> v = pq.top();
			pq.pop();
			if(visitados[v.se])continue;
			visitados[v.se] = 1;
			custos[v.se] = v.fi;

			for (int i = 0; i < graph[v.se].size(); ++i)
			{
				pair<int, int> s;
				s.fi = v.fi + graph[v.se][i].fi;
				s.se = graph[v.se][i].se;
				pq.push(s);
			}
		}
		#if TRACE
		for(auto& p : custos)
		{
			cout << p.se <<endl;
		}

		for (int i = 0; i < graph[0].size(); ++i)
		{
			cout<< "Graph fi: " << graph[0][i].fi << "   Graph se: " << graph[0][i].se<< endl;

		}

		cout<<calcCusto(0, 20)<<endl;
		#endif
	}
}
