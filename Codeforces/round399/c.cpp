/*input
10 3 10
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

#define IOS ios_base::sync_with_stdio(0) //to synchronize the input of cin and scanf
#define INF 1001001001

#define mt make_tuple
#define mp make_pair
#define fi first
#define se second
#define pb push_back

//for vectors
typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii; 
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef unsigned short us;

const double PI = 3.1415926535897932384626;
const double inf = 1.0/0.0;

vector<ull> aux;

vector<ull> generateSeq(ull n)
{
	vector<ull> ans;
	vector<ull> s;
	ull mid = n%2;

	if(n <= 1)
	{
		s.pb(n);
		return s;
	}
	else
	{
		aux = generateSeq((ull)floor(n/2.0));
		ans = aux;
		ans.pb(mid);
		for(auto& p : aux)
			ans.pb(p); 
	}
	return ans;
}
int main()
{
	IOS;
	ull a, b, c;
	cin >> a >> b >> c;
	vector<ull> seq = generateSeq(a);
	b--;
	c--;
	int ans = 0;
	for(int i = b; i <= c; ++i)
	{
		if(seq[i] == 1)
			ans++;
	}
	cout << ans << endl;
	return 0;
}