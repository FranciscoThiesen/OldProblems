#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define vi vector<int>
#define ii pair<int, int>
#define vvii vector<vector<ii> >
#define vvi vector<vi>

int conta_raiz(vvii& v)
{
	int sz = 1;
	int no = 0;
	loop:
	while(v[no].size() != 0)
	{
		for(int i = 0; i < v[no].size(); ++i)
		{
			if(v[no][i].second == 0)
			{
				sz++;
				no = v[no][i].first;
				goto loop;
			}
		}
		break;
	}
	return sz;
}

//alpha[root] = 1
void dfs(vvii& adjList, vi& alpha, int root)
{
	for(int i = 0; i < adjList[root].size(); ++i)
	{
		if(adjList[root][i].second == 0)
			alpha[adjList[root][i].first] = alpha[root] + 1;
		else
			alpha[adjList[root][i].first] = 1;
		dfs(adjList, alpha, adjList[root][i].first);
	}
}

int main()
{
	int ne, nd;
	scanf("%d", &ne);
	vvii adjListLeft(ne);
	for(int i = 0; i < ne; ++i)
	{
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		if(y!=0)
			adjListLeft[x-1].pb(mp(y-1, 1));
		if(z!=0)
			adjListLeft[x-1].pb(mp(z-1, 0));
	}

	scanf("%d", &nd);
	vvii adjListRight(nd);
	for(int i = 0; i < nd; ++i)
	{
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		if(y != 0)
			adjListRight[x-1].pb(mp(y-1, 0));
		if(z != 0)
			adjListRight[x-1].pb(mp(z-1, 1));
	}

	int maxSeqCentralComecandoDaRaizEsquerda = conta_raiz(adjListLeft);
	int maxSeqCentralComecandoDaRaizDireita = conta_raiz(adjListRight);

	vi alphaLeft(ne, 0);
	alphaLeft[0] = 1;
	dfs(adjListLeft, alphaLeft, 0);

	vi alphaRight(nd, 0);
	alphaRight[0] = 1;
	dfs(adjListRight, alphaRight, 0);

	int maxSeqCentralComecandoDeQlqrVerticeEsq = 0;
	int maxSeqCentralComecandoDeQlqrVerticeDir = 0;

	for(auto& p : alphaLeft)
		if(p > maxSeqCentralComecandoDeQlqrVerticeEsq)
			maxSeqCentralComecandoDeQlqrVerticeEsq = p;

	for(auto& p : alphaRight)
		if(p > maxSeqCentralComecandoDeQlqrVerticeDir)
			maxSeqCentralComecandoDeQlqrVerticeDir = p;		
	
	int maxCollision = max(min(maxSeqCentralComecandoDaRaizEsquerda, maxSeqCentralComecandoDeQlqrVerticeDir), min(
		maxSeqCentralComecandoDaRaizDireita, maxSeqCentralComecandoDeQlqrVerticeEsq));

	cout << ne + nd - maxCollision << endl;
	return 0;
}