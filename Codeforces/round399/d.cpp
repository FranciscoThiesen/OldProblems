/*input
2 100000 569
605 986
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
	int x, y, z;
	cin >> x >> y >> z;
	vi vec(x);
	forn(i, x)
		cin >> vec[i];
	sort(all(vec));
	if(y == 0)
	{
	 	cout << vec[x-1] << " " << vec[0];
	 	return 0;
	}

	vi auxI;
	vi auxII;
	vi auxIII;
	//for(auto& p : vec)
	//	cout << p << " ";
	//cout << endl;


	forn(i, 6)
	{
		forn(j, x)
		{
			if(!(j%2))
			{
				vec[j] = vec[j] ^ z;
			}
		}

		sort(all(vec));
		if(i == 0)
			auxI = vec;
		else if(i == 1)
			auxII = vec;
		else if(i == 2)
			auxIII = vec;

		//for(auto& p : vec)
		//	cout << p <<  " ";
		//cout << endl << endl;
	}
	if(z%2 == 1 && y == 1)
	{
		cout << auxI[x-1] << " " << auxI[0];
		return 0;
	}
	else if(z%2 == 1 && y%2 == 0)
	{
		cout << auxII[x-1] << " " << auxII[0];
	}
	else if(z%2 == 1 && y%2 == 1)
	{
		cout << auxIII[x-1] << " " << auxIII[0];
	}
	else if(z%2 == 0 && y%2 == 1)
	{
		cout << auxI[x-1] << " " << auxI[0];
	}
	else
	{
		cout << auxII[x-1] << " " << auxII[0];
	}

	//cout << vec[x-1] << " " << vec[0];
	return 0;
}
