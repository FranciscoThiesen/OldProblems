#include <cstdio>
#include <cmath>
#include <vector>
#include <utility>
#include <queue>
#include <functional>
#include <climits>
#include <iostream>

using namespace std;

const int INF = 0x3F3F3F3F; const int NEGINF = 0xC0C0C0C0; const int NULO = -1;
const double EPS = 1e-10;
inline int cmp(double x, double y = 0, double tol = EPS) { return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

struct circle
{
    int x;
    int y;
    int r;
};
typedef struct circle Circle;

Circle v[110];


double dist(Circle c1, Circle c2)
{
    return sqrt( (c1.x-c2.x) * (c1.x-c2.x) + (c1.y - c2.y) * (c1.y - c2.y));
}

double graph[110][110];  

int main()
{
    int N;
    while(scanf("%d", &N), N!=0)
    {
        for(int i=0; i<N; i++)
        {
            scanf("%d %d %d", &(v[i].x), &(v[i].y), &(v[i].r));
        }


        for(int i =0; i<N; i++)
        {
            for(int j=0; j<N; j++)
            {
                graph[i][j] = 1000000000;
            }
        }
        for(int i=0; i<N; i++)
        {
            for(int j=0; j<N; j++)
            {
                double c = dist(v[j], v[i]);
                if( cmp(c, v[j].r) <= 0)
                    graph[j][i] = c;
                else if(cmp(c, v[i].r) <= 0)
                    graph[i][j] = c;
            }
        }
        for(int z = 0; z < N; ++z)
        {
            for(int x = 0; x < N; ++x)
            {
                for(int y = 0; y < N; ++y)
                {
                    graph[x][y] = min(graph[x][y], graph[x][z] + graph[z][y]);
                }
            }
        }

        int qry;
        cin >> qry;
        for(int i = 0; i < qry; ++i)
        {
            int r, t;
            scanf("%d %d", &r, &t);
            if( (int) graph[r-1][t-1] == 1000000000)
                printf("-1\n");
            else
                printf("%d\n", (int) graph[r-1][t-1]);
        }
    }
    return 0;
}
