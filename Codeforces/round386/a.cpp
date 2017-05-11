/*input
2 3 2
*/
#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<pair<int, int> > vii;

int main()
{
	int a,b,c;
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> a >> b >> c;
	int nb = b/2;
	int nc = c/4;
	int qnt = min(a, min(nb, nc));
	cout << qnt* 7 << endl;
	return 0;
}
