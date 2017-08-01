// https://www.codechef.com/JAN17/problems/TOURISTS
#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
#define mp make_pair
#define fi first
#define se second
 
bool cc(int n, vector<vector<int> >& adjList)
{
    vector<bool> visited(n, false);
    visited[0] = true;
    queue<int> q;
    q.push(0);
    while(!q.empty())
    {
        int t = q.front();
        q.pop();
        if(adjList[t].size()%2 != 0)
            return false;
        for(auto& v : adjList[t])
        {
            if(!visited[v])
            {
                q.push(v);
                visited[v] = true;
            }
        }
    }
    for(int i = 0; i < n; ++i)
        if(!visited[i])
            return false;
    return true;
}
 
int main()
{
    int n, e;
    scanf("%d %d", &n, &e);
    vector<vector<int> > adjList(n);
    vector<unordered_map<int, int> > edgeList(n);
    for(int i = 0; i < e; ++i)
    {
    	int x, y;
        scanf("%d %d", &x, &y);
    	x--;
        y--;
 
        adjList[x].pb(y);
 
    	adjList[y].pb(x);
      
        edgeList[x].insert(mp(y,i));
 
    }
    if(!cc(n, adjList) || e < n)
    { 
        printf("NO\n");
        return 0;
    }
    else
    {
        stack<int> aux;
        int current = n-1;
        vector<int> circuit;
        while(circuit.size() < e+1)
        {
            if(!adjList[current].empty())
            {
                aux.push(current);
                int nxt = *(adjList[current].begin());
                adjList[current].erase(adjList[current].begin());
                adjList[nxt].erase(find(adjList[nxt].begin(), adjList[nxt].end(), current));
                current = nxt;
            }
            else
            {
                if(aux.empty())
                {
                    circuit.pb(current);
                    break;
                }
                else
                {
                    circuit.pb(current);
                    current = aux.top();
                    aux.pop();
                }
            }
        }
        if(circuit.size() < e+1)
        {
            printf("NO\n");
            return 0;
        }
        map<int, pair<int, int> > printEdges;
        reverse(circuit.begin(), circuit.end());
        for(int i = 0; i < circuit.size() - 1; ++i)
        {
            int orig = circuit[i];
            int dest = circuit[i+1];
            int id;
            if(edgeList[orig].find(dest) != edgeList[orig].end())
                id = edgeList[orig][dest];
            else
                id = edgeList[dest][orig];
            printEdges.insert(mp(id, mp(orig, dest)));
        }
        printf("YES\n");
        for(auto& p : printEdges)
        {
           printf("%d %d\n", p.se.fi + 1, p.se.se + 1); 
        }
    }
    return 0;
}  