/*input
6 2
10 15 // new1
12 17 // 1
16 18 
18 13 // new2
30 10 // 2
32 1
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>
#include <cmath>
#include <algorithm>

using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(v) (v).begin(), (v).end()
#define fr(i,a,b) for(int (i) = (a); (i)<(b); ++i)
#define fu(i, n) fr(i, 0, n)


typedef vector<int> vi;
typedef pair<int, int> ii;

constexpr int maxn = 5010;

ii dp[maxn][maxn];

vi h(maxn, 0);
vi w(maxn, 0);

int n, k;

void initialize()
{
    fu(i, k)
    {
        fu(j, n)
        {
            if(i == 0 && j == 0)
                dp[i][j] = mp(0, w[0]);
            else if(i == 0)
                dp[i][j] = mp(dp[i][j-1].fi + dp[i][j-1].se * (h[j-1] - h[j]), dp[i][j-1].se + w[j] );
            else dp[i][j] = mp(-1,-1);//flag
        }
    }
}

ii recursiveCall(int i, int j)
{
    if(dp[i][j].fi != -1 && dp[i][j].se != -1)
        return dp[i][j];
    //if(j == i+1)
      //  return dp[i][j] = mp(0, w[j]);

    ii noNewCut = recursiveCall(i, j-1);
    if(i == 0)return dp[i][j] = mp(noNewCut.fi + noNewCut.se * (h[j-1] - h[j]), noNewCut.se + w[j]);
    ii newCut = recursiveCall(i-1, j-1);
    int oneMoreCutCost = newCut.fi;
    int noMoreCutCost = noNewCut.fi + (noNewCut.se * (h[j-1]-h[j]) );

    if(noMoreCutCost < oneMoreCutCost)
        return dp[i][j] = mp(noMoreCutCost, noNewCut.se + w[j]);
    return dp[i][j] = mp(oneMoreCutCost, w[j]);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    fu(i, n) cin >> h[n-i-1] >> w[n-i-1];
    initialize();
    cout << recursiveCall(k-1, n-1).fi << endl;

    fu(i, k)
    {
        fu(j, n)
        {
            printf("(%d,%d)   ", dp[i][j].fi , dp[i][j].se);
        }
        puts("\n");
    }
    cout << endl << endl;
    return 0;
    
}
