#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <queue>
#include <vector>
#include <utility>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <set>
#include <list>
using namespace std;

#define pii pair<int, int>

bool cmp(const pii& p1, const pii& p2){
	return p1.first <= p2.first;
}

int main() {
	int n;
	cin >> n;

	vector<pii> v(n);
	vector<pii> v1(n, make_pair(-1, -1));
	vector<pii> v2(n, make_pair(-1, -1));

	for (int i = 0; i < n; i++) {
		int begin, end;
		cin >> begin >> end;

		v[i] = make_pair(begin, end);
	}

	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < n - 2; i++) {
		if (v1.back().second != v[i].first && v1.back().first != v[i].first) {
			v1.push_back(v[i]);
		}
		else if (v2.back().second != v[i].first && v2.back().first != v[i].first) {
			v2.push_back(v[i]);
		} else {
			cout << "NO" << endl;
			return 0;
		}
	}

	cout << "YES" << endl;

	return 0;
}
