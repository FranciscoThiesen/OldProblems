#include <bits/stdc++.h>

using namespace std; 

#define fi first
#define se second
#define mp make_pair
#define pb push_back

typedef unsigned long long ull;
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

void init(int n)
{
    for(int i = 0; i < n; ++i)
    {
        parent[i] = i;
        size[i] = 1;
    }
}

ull f(int s)
{
    ull fi = (s * (s + 1) * (2*s + 1))/6;
    ull se = (s*(s+1))/2;
    return fi - se;
}

int main()
{
    int t;
    ios::sync_with_stdio(0);
    cin >> t;
    while(t--)
    {
        multimap<int, int> components; // <father, size>
        ull cur=0;
        int n, q;
        unsigned long long ans = 0;
        cin >> n >> q;
        init(n);
        for(int j = 0; j < q; ++j)
        {
            int e,r;
            cin >> e >> r;
            r--;
            e--;
            int k = find(e);
            int l = find(r);
            if(k != l)
            {
                unite(l,k);
                int father = find(e);
                int mx = size[father];
            }
        }
        for(int i = 0; i < n; ++i)
        {
            if(parent[i]==i && size[i] !=1)
                components.insert(mp(size[i], i));
        }
        int totArestas = 0;
        //cout << components.size() << endl;
        for(auto it = components.rbegin(); it != components.rend(); ++it)
        {
            //cout <<it->first << " " << it->second << endl;
            ans += (it->first-1)*cur;
            totArestas += it->first - 1;
            ans+= f(it->first);
            cur += it->first * (it->first - 1);
        }
        int arestasInuteis = q - totArestas;
        ans += (cur*arestasInuteis);
        cout << ans << endl;
    }
    return 0;
}