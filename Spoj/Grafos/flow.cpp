#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>
#include <iostream>
#include <utility>
#include <functional>
#include <cstring>
#include <string>
#define MAXN 1001
#define INF 1000000000
using namespace std;

vector<vector<int> > graph(MAXN);
int capacity[MAXN][MAXN] = {{0}};


long long maxFlow(int source, int sink)
{
    int residualCapacity[MAXN][MAXN] = {{0}};
    while(true)
    {
        int prev[MAXN];
        memset(prev, -1, sizeof(prev));
        int atual[MAXN] = {0};
        prev[source] = source;
        atual[source] = INF;
        queue<int> q;
        q.push(source);
        while(!q.empty())
        {
            int u = q.front();
            q.pop();
            for(int i = 0; i < graph[u].size(); ++i)
            {
                int v = graph[u][i];
                if(capacity[u][v] - residualCapacity[u][v] > 0 && prev[v] == -1)
                {
                    prev[v] = u;
                    atual[v] = min(atual[u], capacity[u][v] - residualCapacity[u][v]);
                    if(v != sink)
                        q.push(v);
                    else
                    {
                        while(prev[v] != v)
                        {
                            u = prev[v];
                            residualCapacity[u][v] += atual[sink];
                            //residualCapacity[v][u] -= atual[sink];
                            v = u;
                        }
                        goto end;
                    }
                }    
            }
        }
        end:;
        if(prev[sink] == -1)
        {
            long long sum = 0;
            for(int i = 0; i < MAXN; ++i)
            {
                sum+= residualCapacity[source][i];
            }

            return sum;
        }
    }
}

int main()
{
    int n = 1, s, d, e;
    int t = 1;
    while(n != 0)
    {
        cin >> n;
        if(n == 0)
            break;
        else
            cin >> s >> d >> e;
        for(int i = 0; i < e;++i)
        {
            int u, v, c;
            scanf("%d %d %d", &u, &v, &c);
            graph[u-1].push_back(v-1);
            graph[v-1].push_back(u-1);
            capacity[u-1][v-1] += c;
            capacity[v-1][u-1] += c;
        }
        cout << "Network " << t << endl;
        cout << "The bandwidth is ";
        cout << maxFlow(s-1, d-1) << "." <<  endl << endl;
        memset(capacity, 0, sizeof(capacity));
        vector<vector<int> > graph(MAXN);
        t++;
    }
    return 0;
}
