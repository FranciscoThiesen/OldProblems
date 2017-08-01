/*input
64
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


int main()
{
	int x;
	cin >> x;
	int row = 0;
	int col = 0;
	int dif = 1000*10000;
	for(int i = 1; i <= x; ++i)
	{
		if(x%i == 0)
		{
			if(abs(i - (x/i)) < dif)
			{
				dif = abs(i - (x/i));
				row = i;
				col = x/i;
			}
		}
	}
	cout << min(row, col) << " " << max(row, col) << endl;
	return 0;
}