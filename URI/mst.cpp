#include <cstdio>
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
#define mp make_pair
#define ll long long int
vector<int> size(200001);
int parent[200001];

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
    int nodes = 1, edges = 1;
    while(nodes + edges != 0)
    {
        cin >> nodes >> edges;
        if(nodes + edges == 0)
            break;
        std::fill(size.begin(), size.end(), 1);
        for(int i =0; i < 200000; ++i)
            parent[i] = i;
        vector<pair<int, pair<int, int> > > EdgeList;
        unsigned long long total = 0;
        for(int i = 0; i < edges; ++i)
        {
            int a,b;
            ll c;
            cin >> a >> b >> c;
            total += c;
            pair<int,int> dup = mp(a,b);
            pair<ll, pair<int, int> > par = mp(c, dup);
            EdgeList.push_back(par);
        }
        sort(EdgeList.begin(), EdgeList.end());
        long long totalCost = 0;
        int edg = 0;
        int idx = 0;
        while(edg < nodes - 1)
        {
            if(find(EdgeList[idx].second.first) !=  find(EdgeList[idx].second.second))
            {
                //cout << uniao.findSet(EdgeList[idx].second.first) << " " << EdgeList[idx].second.second << endl;
                edg++;
                totalCost += EdgeList[idx].first;
                unite(EdgeList[idx].second.first, EdgeList[idx].second.second);
            }
            idx++;
        }
        cout << total - totalCost << endl; 
    }
    return 0;
}
