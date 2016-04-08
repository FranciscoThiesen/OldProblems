#include <cstdio>
#include <functional>
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <priority_queue>

using namespace std;

vector<vector<pair<int, int> > > AdjList(5001);
vector<int> Dist(5001);

int main()
{
    int nodes, edges;
    cin >> nodes >> edges;
    for(int i = 0; i < edges; i++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        AdjList[a].push_back(make_pair(c,b));
        AdjList[b].push_back(make_pair(c,a));
    }
    //Dijkstra
    Dist[0] = 0;
    priority_queue<ii, vii, greater<ii> > q;
    q.push(make_pair(0,0));
    while(!q.empty())
    {
        ii a = q.top();
        int u = a.second();
        int d = a.first();
        if(d > Dist[u])
                continue;
        q.pop();
        for(int j = 0; j < AdjList[d];j++)
        {
            ii v = AdjList[d][j];
            if(Dist[u] + v.first < Dist[v.second])
            {
                Dist[v.second] = Dist[u] + v.first;
                q.push_back(make_pair(Dist[v.second], v.second))
            }
        }
    }

}
