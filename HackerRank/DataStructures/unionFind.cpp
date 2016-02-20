#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std; 

vector<int> size(100001,1);
int parent[100001];

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
    int n, q;
    scanf(" %d %d ", &n, &q);
    for(int i = 0; i < n; ++i)
        parent[i] = i;
    for(int j = 0; j < q; ++j)
    {
        char c;
        scanf("%c", &c);
        if(c == 'Q')
        {
            int d;
            scanf(" %d ", &d);
            printf("%d\n", size[find(d)]);
        }
        else
        {
            int e,r;
            scanf(" %d %d ", &e, &r);
            unite(e,r);
        }
    }
    return 0;
}
