#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;
int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	vector<int> puzzles(m);
	for(int i = 0; i < m; ++i)
	{
		scanf("%d", &puzzles[i]);
	}
	sort(puzzles.begin(), puzzles.end());
	int min_dif = 1000;
	if( n == m)
	{
		printf("%d\n", puzzles[m - 1] - puzzles[0]);
		return 0;
	}
	for(int j = 0; j <= m - n; j++)
	{
		if(puzzles[j + n - 1] - puzzles[j] < min_dif)
			min_dif = puzzles[j + n - 1] - puzzles[j];

	}
	printf("%d\n", min_dif);
	return 0;
}