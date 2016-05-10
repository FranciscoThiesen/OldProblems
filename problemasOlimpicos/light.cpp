#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>
#include <cassert>
#include <cstdio>
#include <queue>
#include <set>
#include <map>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <numeric>

#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)
#define abs(x) (x<0?(-x):x) // big bug here if "-x" is not surrounded by "()"

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;

int main()
{
    int num, length;
    scanf("%d %d",&num, &length);
    vi spots;
    forn(i,num)
    {
        int x;
        cin >> x;
        spots.pb(x);
    }
    sort(spots.begin(),spots.end());
    float dist = 0;
    float lDist = dist;
    for(int i = 1; i < num; i++)
    {
        dist = spots[i] - spots[i-1];
        if(dist > lDist)
            lDist = dist;
    }
    float alpha = max(abs(0-spots[0]), length - spots[num-1]);
    float k = 0;
    k += max(alpha,lDist/2.0);
    cout << k << endl;
    return 0;
}