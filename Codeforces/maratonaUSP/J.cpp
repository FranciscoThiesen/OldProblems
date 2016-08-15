#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	vector<set<int> > collide(n);
	vector<pair<pair<double, double>, double> > circles;
	for(int i = 0; i < n; ++i)
	{
		double a, b, c;
		cin >> a >> b >> c;
		circles.push_back(make_pair(make_pair(a,b), c));
	}
	for(int x = 0; x < circles.size(); ++x)
	{
		for(int y = x+1; y < circles.size(); ++y)
		{
			double fst = abs(circles[x].first.first - circles[y].first.first);
			double se = abs(circles[x].first.second - circles[y].first.second);
			double dist = sqrt(fst*fst + se*se);
			if(dist <= circles[x].second + circles[y].second)
				collide[x].insert(y);
		}
	}
	for(int i = 0; i < collide.size(); ++i)
	{
		for(auto& p : collide[i])
		{
			cout << i+1 << " " << p+1 << endl;
		}

	}
	return 0;
}

