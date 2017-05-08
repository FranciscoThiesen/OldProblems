#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <functional>
#include <cstdio>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define ALL(x) (x).begin(),(x).end()

typedef pair<int, int> ii;

int main()
{
	ifstream in;
	ofstream out;
	in.open("input.txt");
	out.open("output.txt");

	int n, k;
	in >> n >> k;
	vector<int> freq(4001, 0);
	vector< multiset<int, greater<int> >  > elems(4001);
	for(int i = 0; i < n; ++i)
	{
		int a, b;
		in >> a >> b;
		elems[a].insert(b);
		freq[a]++;
	}

	vector<ii> frequencyAndNumber;
	for(int i = 0; i < 4001; ++i)
		if(freq[i]!=0)
			frequencyAndNumber.pb(mp(freq[i], i));

	sort(frequencyAndNumber.rbegin(), frequencyAndNumber.rend());


	if(frequencyAndNumber.size() < k)
	{
		out << 0 << " " << 0 << endl;
		out.close();
		return 0;
	}
	else
	{
		int minimumFreqRequired = frequencyAndNumber[k-1].fi;
		vector<int> candidates;
		for(int i = 0; i < frequencyAndNumber.size(); ++i)
		{
			if(frequencyAndNumber[i].fi >= minimumFreqRequired)
			{
				int sum = 0;
				int cur = 0;
				for(auto& p : elems[frequencyAndNumber[i].se])
				{
					sum += p;
					cur++;
					if(cur == minimumFreqRequired)
						break;
				}
				candidates.pb(sum);
			}
		}
		sort(candidates.rbegin(), candidates.rend());
		int resp = 0;
		for(int i = 0; i < k; ++i)
		{
			resp += candidates[i];
		}
		out << minimumFreqRequired << " " << resp << endl;
	}
	in.close();

	out.close();
	return 0;
}