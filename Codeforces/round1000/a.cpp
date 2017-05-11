/*input
5
*/

#include <bits/stdc++.h>

using namespace std;

char mat[501][501];
int main()
{
	int n, m;
	cin >> n >> m;
	for(int lin = 0; lin < n; ++lin)
	{
		for(int col = 0; col < m; ++col)
		{
			scanf("%c", &mat[lin][col]);
		}
	}
	char<int> accu;
	for(int i = 0; i < lin; ++i)
	{
		accu.pb(mat[i][0]);
	}
	for(int col = 1; col < m; ++i)
	{
		for(int lin = 0; lin < n; ++lin)
		{

		}
	}
	return 0;
}