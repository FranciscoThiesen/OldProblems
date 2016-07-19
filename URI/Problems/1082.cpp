#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <utility>
#include <cmath>
#include <string>
#include <queue>
using namespace std;
vector<vector<int> > AdjList(26);
vector<bool> visited (26);
vector<vector<int> > ConnectedComponents;

void bfs(int root)
{
    queue<int> q;
    vector<int> components;
    q.push(root);
    components.push_back(root);
    visited[root] = true;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int i = 0; i < AdjList[u].size(); ++i)
        {
            if(visited[AdjList[u][i]] == false)
            {
                visited[AdjList[u][i]] = true;
                components.push_back(AdjList[u][i]);
                q.push(AdjList[u][i]);
            }
        }
    }
    ConnectedComponents.push_back(components);
}


int main()
{
    int t;
    scanf("%d", &t);
    int test = 1;
    while(t--)
    {
        int n, e;
        cin >>n >> e;
        for(int y = 0; y < e; ++y)
        {
            char q,w;
            cin >> q >> w;
            AdjList[(int)q-'a'].push_back((int)w-'a');
            AdjList[(int)w-'a'].push_back((int)q-'a');
        }
        for(int j = 0; j < n; ++j)
        {
            if(visited[j] == false)
                bfs(j);
        }
        printf("Case #%d:\n", test);
        test++;
        for(int k = 0; k < ConnectedComponents.size();k++)
        {
            sort(ConnectedComponents[k].begin(), ConnectedComponents[k].end());
            for(int v = 0; v < ConnectedComponents[k].size(); ++v)
                cout << (char) ('a' + ConnectedComponents[k][v]) << ",";
            cout << endl;
        }
        cout << ConnectedComponents.size() << " connected components" << endl << endl;
        fill(visited.begin(), visited.end(), false);
        for(int i = 0; i < 26;++i)
        {
            AdjList[i].clear();
        }
        for(auto& p : ConnectedComponents)
            p.clear();
        ConnectedComponents.clear();
    }
    return 0;
}
