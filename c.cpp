#include <algorithm>
#include <vector>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
#include <stdio.h>
#include <queue>



using namespace std;


typedef struct
{
	int v;
	int c;
}Edge;


bool operator < (const Edge &lhs, const Edge &rhs)
{ return rhs.c < lhs.c; }


vector<Edge> graph[510];
int custo[510];
bool visitados[510];


void dfs(int v, int chamou)
{

	if(visitados[v])
	{
		Edge e1 = {v,0}, e2 = {chamou, 0};
		graph[v].push_back(e2);
		graph[chamou].push_back(e1);
		return;
	}

	visitados[v] = true;

	for (int i = 0; i < graph[v].size(); ++i)
		dfs(graph[v][i].v, v);
}

int main()
{
	int N,E,K;
	while(scanf("%d %d", &N, &E), N!=0 && E!=0)
	{
		for (int i = 0; i < N; ++i)
		{
			graph[i].clear();
		}

		for (int i = 0; i < E; ++i)
		{
			int v1, v2, c;
			scanf("%d %d %d", &v1, &v2, &c);
			Edge e;
			e.v = v2-1;
			e.c = c;
			graph[v1-1].push_back(e);
		}

		for (int i = 0; i < N; ++i)
			visitados[i] = false;

		for (int i = 0; i < N; ++i)
		{
			printf("%d:\n", i);
			for (int j = 0; j < graph[i].size(); ++j)
			{
				printf(" %d\n", graph[i][j].v);
			}
			printf("\n");
		}

		//dfs(0, -1);


		// for (int i = 0; i < N; ++i)
		// {
		// 	printf("%d:\n", i);
		// 	for (int j = 0; j < graph[i].size(); ++j)
		// 	{
		// 		printf(" %d\n", graph[i][j].v);
		// 	}
		// 	printf("\n");
		// }



		scanf("%d", &K);
		for (int i = 0; i < K; ++i)
		{
			int a,b;
			scanf("%d %d", &a, &b);
			
			for (int j = 0; j < N; ++j)
			{
				custo[j] = INT_MAX;
				visitados[j] = false;
			}

			Edge root = {0, 0};

			priority_queue<Edge> priorityTree;

			priorityTree.push(root);

			while(!priorityTree.empty())
			{
				Edge e = priorityTree.top();
				priorityTree.pop();
				
				// if(e.v==b-1)
				// 	break;

				if(visitados[e.v]) continue;

				custo[e.v] = e.c;
				visitados[e.v] = true;
				for (int j = 0; j < graph[e.v].size(); ++j)
				{
					Edge bh;
					bh.v = graph[e.v][j].v;
					bh.c = bh.c + graph[e.v][j].c;
					priorityTree.push(bh);
				}
			}

			printf("------------\n");
			for (int i = 0; i < N; ++i)
			{
				printf("%d\n", custo[i]);
			}
			printf("------------\n");


			if(custo[b-1]==INT_MAX)
				printf("Nao e possivel entregar a carta\n");
			else
				printf("%d\n", custo[b-1]);
		}
		printf("\n");
	}
}


