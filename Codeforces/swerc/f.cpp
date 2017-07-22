#include <stdio.h>
#include <vector>

using namespace std;

int times[100010];
int lvs[100010];
vector<vector<int> > graph(100001);
long long resp[100010] = {0};

void dfs(int v0, int v)
{
    for(unsigned int i =0; i<graph[v].size(); i++)
    {
        int vn = graph[v][i];
        if(lvs[vn]<lvs[v0])
        {
            resp[v0] = resp[v0] + times[vn];
        }
        dfs(v0, vn);
    }
}

int main()
{
    int e;
    scanf("%d", &e);
    for(int i =0; i<e; i++)
    {
        int boss, tr, time;
        scanf("%d %d %d", &boss, &tr, &time);
        if(boss>0)
            graph[boss-1].push_back(i);
        lvs[i]=tr;
        times[i]=time;
    }
    for(int i=0; i<e; i++)
    {
        dfs(i, i);
    }


    for(int i =0; i<e; i++)
    {
        printf("%lld\n", resp[i]);
    }
    return 0;
}

