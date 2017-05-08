#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <set>
#include <iterator>
#include <limits>
#include <unordered_set>
#include <functional>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef unsigned long long ull;
typedef long long ll;


int main()
{
    ifstream in;
    ofstream out;
    in.open("pulp.in");
    out.open("pulp.out");
    int k;
    in >> k;
    set<pair<ull, ull> > solve;
    for(int i = 0; i < k; ++i)
    {
         ull x, y;
         in >> x >> y;
         solve.insert(mp(x,y));
    }
    ull ans = 0;
    while(!solve.empty())
    {
        auto w = *(solve.begin());
        solve.erase(solve.begin());
        if(solve.empty())
            ans += w.fi + w.se;
        else if(w.fi + w.se <= (*(solve.begin())).fi + (*(solve.begin())).se)
            ans += w.fi + w.se;
        else
            solve.insert(mp((*(solve.begin())).fi - w.fi, w.se - (*(solve.begin())).fi));
    }
    cout << ans << endl;
    out << ans << endl;
    return 0;
}
