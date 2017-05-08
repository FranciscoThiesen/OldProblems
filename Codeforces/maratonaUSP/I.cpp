#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, t;
	scanf("%d %d", &n, &t);
	vector<int> food;
	for(int i = 0; i < n; ++i)
	{
		int x;
		cin >> x;
		food.push_back(x);
	}
	vector<int> foodRev = food;
	reverse(foodRev.begin(), foodRev.end());
	int yan = 0;
	int nathan = 0;
	int yt = t;
	int nt = t;
	for(int i = 0; i < food.size(); ++i)
	{
		if(yt >= food[i])
			yan++, yt-=food[i];
		else
			yt = -1;
		if(nt >= foodRev[i])
			nathan++, nt -= foodRev[i];
		else
			nt = -1;
	}
	if(yan > nathan)
		cout << "Yan" << endl;
	else if(nathan > yan)
		cout << "Nathan" << endl;
	else
		cout << "Empate" << endl;
	return 0;
}