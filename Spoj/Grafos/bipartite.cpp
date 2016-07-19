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
#define MAXN 610
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
                    cout << v << "  " << atual[v] << endl;
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
            for(int i = 0; i <= MAXN; ++i)
            {
                sum+= residualCapacity[source][i];
            }

            return sum;
        }
    }
}

int main()
{
    int n = 1;
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(int i = 0; i < n;++i)
        {
            string s;
            cin >> s;
            capacity[0][(2*i)+1] = 1;//ligando todas as sources a supersource
            graph[0].push_back((2*i)+1);
            for(int j = 0; j < n;++j)
            {
                if(s[j] == '1')
                {
                    graph[(2*i)+1].push_back(2+(2*j));
                    capacity[(2*i)+1][2+(2*j)] = 1;
                }
            }
        }
        for(int i = 1; i <= n*2; ++i)
        {
            if((i+1)%2 == 0)
            {
                capacity[(i+1)][(2*n)+1] = 1;//ligando sinks para supersink
                graph[(i+1)].push_back((2*n)+1);
            }
        }
        if(maxFlow(0,((2*n)+1))%2 == 0)
            cout << "Even" << endl;
        else
            cout << "Odd" << endl;
        memset(capacity, 0, sizeof(capacity));
        vector<vector<int> > graph(MAXN);
    }
    return 0;
}
