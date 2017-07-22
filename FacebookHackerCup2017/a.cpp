// Francisco Thiesen Solution
#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second

int main()
{
	int t;
	ifstream in;
	ofstream out;
	in.open("in.txt");
	out.open("out.txt");
	in >> t;
	for(int test = 0; test < t; ++test)
	{
		int n, m;
		in >> n >> m;
		unsigned long long tot = 0;
		priority_queue<int, vector<int>, greater<int> > pieQueue;
		for(int i = 0; i < n; ++i)
		{
			vector<int> pie(m);
			for(int j = 0; j < m; ++j)
			{
				in >> pie[j];
			}
			sort(pie.begin(), pie.end());
			for(int j = 0; j < m; ++j)
			{
				pieQueue.push(pie[j] + (j+1)*(j+1) - (j*j) );
			}
			tot += pieQueue.top();
			pieQueue.pop();
		}
		out << "Case #" << test+1 << ": " << tot << endl;
	}
	out.close();
	in.close();
}