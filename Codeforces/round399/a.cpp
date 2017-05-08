/*input
3
1 2 5
*/
#include <cmath>
#include <climits>
#include <queue>
#include <vector>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iomanip>   
#include <iostream>  
#include <sstream>  // istringstream buffer(myString);
#include <stack>
#include <algorithm>
#include <cstring>
#include <cassert>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <functional>
#include <deque>
#include <tuple>

using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define mt make_tuple
#define all(v) (v).begin(), (v).end()

#define forn(i, v) for(int (i) = 0; (i) < (v); ++(i))

typedef vector<int> vi;
typedef pair<int, int> ii;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vi vec(n);
	if(n <= 2)
	{
		cout << 0 << endl;
		return 0;
	}
	forn(i, n)
		cin >> vec[i];
	int ans = 0;
	sort(all(vec));
	int mi = vec[0];
	int ma = vec[n-1];
	forn(i, n)
	{
		if(vec[i] > mi && vec[i] < ma)
		{
			ans++;
		}
	}
	cout << ans << endl;
}