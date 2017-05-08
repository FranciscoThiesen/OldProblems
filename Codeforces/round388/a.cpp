/*input
6
*/

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cmath>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <string>

using namespace std;


#define gcd __gcd
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define IOS ios::sync_with_stdio(0);

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;


int main()
{
	int n;
	cin >> n;
	if(n%2 == 0)
	{
		cout << n/2 << endl;
		for(int i = 0; i < n/2; ++i)
			cout << 2 << " ";
		cout << endl;
	}
	else
	{
		n -= 3;
		int tot = 1;
		if(n != 0)
		{
			tot += n/2;
			cout << 1 + n/2 << endl;
			cout << "3" << " ";
			for(int i = 0; i < n/2; ++i)
				cout << 2 << " ";
			cout << endl;

		}
		else
		{
			cout << 1 << endl;
			cout << 3 << endl;
		}
	}
	return 0;
}