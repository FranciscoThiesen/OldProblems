#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair

vector<bool> visited(1001, false);

int adjMat[1001][1001] = {{0}};

bool less_vectors(const vector<int>& a, const vector<int>& b)
{
	return a.size() < b.size();
}

vector<int> dfs(int root, vector<int>& cc, int n)
{
	cc.pb(root);
	visited[root] = true;
	for(int i = 1; i <=n; ++i)
	{
		if(!visited[i] && adjMat[root][i] == 1)
		{	
			dfs(i, cc, n);
		}
	}
	return cc;
}

int main()
{
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	unordered_set<int> special(k);
	for(int i = 0; i < k; ++i)
	{
		int x;
		scanf("%d", &x);
		special.insert(x);
	}

	for(int i = 0; i < m; ++i)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		adjMat[a][b] = 1;
		adjMat[b][a] = 1;
	}

	vector<vector<int> > ccRegular;
	vector<int> sizesreg;
	int mxSpecial = -1;

	vector<int> tmp;
	for(int i = 1; i <= n; ++i)
	{
		if(!visited[i])
		{
			dfs(i, tmp, n);
			bool s = false;
			for(auto& p : tmp)
			{
				if(special.find(p) != special.end())
				{
					if((int)tmp.size() > mxSpecial)
						mxSpecial = (int)tmp.size();
					s = true;
					break;
				}
			}
			if(!s)
			{	
				ccRegular.pb(tmp);
				sizesreg.pb(tmp.size());
			}
			tmp.clear();
		}
	}

	sort(ccRegular.rbegin(), ccRegular.rend(), less_vectors);
	int ans = 0;
	int totSizeRegular = 0;
	int sz = sizesreg.size();

	for(int i = 0; i < sz; ++i)
		totSizeRegular += sizesreg[i];

	for(int i = 0; i < sz; ++i)
	{
		for(int j = i + 1; j < sz; ++i)
		{
			ans += sizesreg[i] * sizesreg[j];
		}
	}
	for(int i = 0; i < sz; ++i)
	{
		for(int j = 0; j < ccRegular[i].size(); ++j)
		{
			for(int q = j+1; k < ccRegular[i].size(); ++q)
			{
				if(adjMat[ccRegular[i][j]][ccRegular[i][q]] == 0)
				{
					ans++;
				}
			}
		}
	}
	if(mxSpecial != 0 && ccRegular.size() != 0)
		ans += mxSpecial * totSizeRegular;
	printf("%d\n", ans);
	return 0;

}