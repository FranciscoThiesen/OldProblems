#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <functional>
#include <unordered_map>
#include <algorithm>
#include <iterator>
#include <cstring>

using namespace std;

#define fi first
#define se second
#define all(v) (v).begin(), (v).end()
#define mp make_pair
#define pb push_back

typedef pair<int, int> ii;

int main()
{

	ifstream in;
	in.open("input.txt");
	ofstream out;
	out.open("output.txt");
	int n;

	set<pair<int, int>,  greater<pair<int, int> > > freq;
	multimap<int, int> largSeq;
	in >> n;
	for(int i = 0; i < n; ++i)
	{
		int x;
		in >> x;
		cout << x << endl;
		for(auto& p : largSeq)
		{
			cout << "p.se " << p.se << "  x = " << x << endl;
			if(abs(p.se - x) != 1)
			{
				largSeq.insert(mp(p.fi+1, x));
				freq.insert(p.fi+1, x));
				break;
				// if(largSeq.find(x) != largSeq.end() && largSeq[x] < p.fi+1)
				// {
				// 	freq.insert(mp(p.fi+1, x));
				// 	largSeq[x] = p.fi+1;
				// 	break;
				// }
				// else if(
				// {
				// 	freq.insert(mp(max(largSeq[x], p.fi+1,x));
				// 	largSeq[x] = p.fi+1;
				// }
			}
		}
		if(largSeq.find(x) == largSeq.end())
		{
			largSeq.insert(mp(1,x));
			freq.insert(mp(1, x));
		}
	}
	vector<int> resp;
	int curSize = -1;
	int curNum = -1;

	for(auto& p : freq)
		cout << p.fi << " " << p.se << endl;
	for(auto& p : freq)
	{
		if(curSize == -1)
		{
			curNum = p.se;
			curSize = p.fi;
			resp.pb(curNum);
		}
		else if(curSize > 0)
		{
			if(abs(p.se - curNum) != 1 && p.fi == curSize-1)
			{
				curSize--;
				curNum = p.se;
				resp.pb(curNum);
			}
		}
		else
			break;
	}

	out << n - resp.size() << endl;
	reverse(resp.begin(), resp.end());
	for(auto& p : resp)
		out << p << " ";
	out << endl;

	return 0;
}