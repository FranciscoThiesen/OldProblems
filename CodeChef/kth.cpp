#include <bits/stdc++.h>

using namespace std;
#define pb push_back
#define ins insert

bool sortFunc(const vector<int>& p1, const vector<int>& p2)
{
	if(p1.size() < p2.size())
	{
		for(int i = 0; i < p2.size(); ++i)
		{
			if(i < p1.size())
			{
				if(p1[i] < p2[i])
					return false;
				else if(p2[i] < p1[i])
					return true;
			}
			else
			{
				if(p2[i] > 0)
					return false;
			}
		}
	}
	else if(p1.size() > p2.size())
	{
		for(int i = 0; i < p1.size(); ++i)
		{
			if(i < p2.size())
			{
				if(p1[i] < p2[i])
					return false;
				else if(p2[i] < p1[i])
					return true;
			}
			else
			{
				if(p1[i] > 0)
					return true;
			}
		}
	}
	else
	{
		for(int i = 0; i < p1.size(); ++i)
		{
			if(p1[i] < p2[i])
				return false;
			else if(p2[i] < p1[i])
				return true;
		}
	}
	return true;
	
}

int main()
{
	ios::sync_with_stdio(0);
	int t;
	cin >> t;
	vector<vector<int> > seq;
	while(t--)
	{
		int n, q;
		cin >> n >> q;
		vector<int> nums(n);
		for(int i = 0; i < n; ++i)	
		{
			int x;
			cin >> x;
			nums[i] = x;
		}
		for(int i = 0; i < n; ++i)
		{
			vector<int> tmp;
			tmp.pb(nums[i]);
			seq.pb(tmp);
			for(int j = i + 1; j < n; ++j)
			{
				tmp.pb(nums[j]);
				seq.pb(tmp);
			}
		}

		sort(seq.begin(), seq.end(), sortFunc);
		for(int k = 0; k < q; ++k)
		{
			int a;
			cin >> a;
			int mx = seq[a-1][0];
			for(int i = 1; i < seq[a-1].size(); ++i)
				mx = ((seq[a-1][i] > mx)? seq[a-1][i] : mx);
			cout << mx << endl;
		}
		seq.clear();
	}
	return 0;
}