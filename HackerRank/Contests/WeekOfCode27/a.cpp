#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	int dest = k/2;
	int last = n/2;
	cout << min(dest, last - dest) << endl;
	return 0;
}