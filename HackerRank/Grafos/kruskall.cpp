#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std; 

vector<int> size(100001,1);
int parent[3001];

int find(int x)
{
    int root = x;
    while(root != parent[root])
    {
        root = parent[root];     
    }
    return root;
}

void unite(int a, int b)
{
    int x = find(a);
    int y = find(b);
    if(x ==  y)
        return;
    if(size[x] > size[y])
    {
        parent[y] = parent[x];
        size[x] += size[y];
    }
    else
    {
        parent[x] = parent[y];
        size[y] += size[x];
    }
    return;
}
int main()
{
    for(int p = 0; p < 3000; p++)
        parent[p] = p;
    int nodes, edges;
    vector<pair<int,pair<int,int> > >arestas;
    scanf(" %d %d ", &nodes, &edges);
    int sum = 0;
    for(int i = 0; i < edges; ++i)
    {
        int a,b,c;
        cin >> a;
        cin >> b;
        cin >> c;
        arestas.push_back(make_pair(c, make_pair(a,b)));
    }
    sort(arestas.begin(), arestas.end());
    for(int j = 0; j < edges; j++)
    {
        if(find(arestas[j].second.second) != find(arestas[j].second.first))
        {
            sum += arestas[j].first;
            unite(arestas[j].second.second, arestas[j].second.first);
        }
    }
    cout << sum << endl;
    return 0;
}
