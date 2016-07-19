#include <cstdio>
#include <vector>
#include <cmath>
#include <stack>
#include <queue>
#include <utility>
#include <functional>
#include <algorithm>
#include <iostream>
#define MAXN 1000
using namespace std;

int level[MAXN];
int cap[MAXN][MAXN] = {{0}};
int flow[MAXN][MAXN] = {{0}};
int path[MAXN];
int visit[MAXN] = {0};

vector<vector<int> > adjList(MAXN);

bool buildLevelGraph(int source, int sink)
{
    queue<int> fila;
    memset(level, 0, sizeof(level));
    fila.push(source);
    level[source] = 1;
    while(!fila.empty())
    {
        int u = fila.front();
        fila.pop();
        for(int i = 0; i < adjList[u].size(); ++i)
        {
            int prox = adjList[u][i];
            if((cap[u][prox] - flow[u][prox] > 0 || flow[prox][u] > 0) && level[prox] == 0)
            {
                fila.push(prox);
                level[prox] = level[u] + 1;
            }
        }
    }
    return level[sink] != 0;
}

long long constructBlockingFlow(int source, int sink)
{
    int ret = 0;
    stack<int> pilha;
    memset(visit, 0, sizeof(visit));
    pilha.push(source);
    while(!pilha.empty())
    {
        int u = pilha.top();
        if( u != sink )// ate chegar no ralo
        {    
            for(int i = 0; i < adjList[u].size() && pilha.top() != u;++i)
            {
                int prox = adjList[u][i];
                if(visit[prox] || level[prox] != level[prox]+1)
                    continue;
                if(cap[u][prox] - flow[u][prox] > 0)
                {
                    pilha.push(prox);
                    path[prox] = u;
                }
                else if( flow[u][prox] > 0)
                {
                    pilha.push(prox);
                    path[prox] = -u;
                }
            }
            if(pilha.top() == u)
            {
                pilha.pop();
                visit[u] = 1;
            }
        }
        else//se chegou no ralo tem que remontar o caminho p achar o min
        {
            int F = 1e9, gargalo;
            for(int cur = sink; cur != source; cur = abs(path[cur]))
            {
                if(path[cur] > 0)
                {
                    F = min(F, cap[path[cur]][cur] - flow[path[cur]][cur]);//aresta entre um elemento e o anterior
                }
                else
                {
                   F=min(F, flow[cur][-path[cur]]); 
                }
            }
            for(int cur = sink; cur != source; cur = abs(path[cur]))
            {
                if(path[cur] > 0)
                {
                    flow[path[cur]][cur] += F;
                    if(cap[path[cur]][cur] - flow[path[cur]][cur] == 0)
                        gargalo = path[cur];
                }
                else
                {
                    flow[cur][-path[cur]] -= F;
                    if(flow[cur][-path[cur]] == 0)
                        gargalo = -path[cur];
                }
            }
            while(!pilha.empty() && pilha.top() != gargalo)
                pilha.pop();
            ret += F;
        }
    }
    return ret;
}

long long Dinic(int source, int sink)
{
    int ret = 0;
    cout << "bu";
    while(buildLevelGraph(source, sink))
    {   
        cout << "ce";
        ret+= constructBlockingFlow(source,sink);
    }
    cout << "ta" << endl;
    return ret;
}

int main()
{
    int n, e;
    scanf("%d %d", &n, &e);
    for(int i = 0; i < e; ++i)
    {
        int u, v, c;
        scanf("%d %d %d", &u, &v, &c);
        adjList[u-1].push_back(v-1);
        adjList[v-1].push_back(u-1);
        cap[u-1][v-1] += c;
        cap[v-1][u-1] += c;
    }
    cout << Dinic(0, n-1) << endl;
}
