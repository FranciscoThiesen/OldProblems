#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define ii pair< pair<int, int>, char>
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int x, y;
	cin >> x >> y;
	vector<ii> upperRightDiag;
	vector<ii> upperLeftDiag;
	vector<ii> lowerRightDiag;
	vector<ii> lowerLeftDiag;
	vector<ii> upperLine;
	vector<ii> lowerLine;
	vector<ii> leftLine;
	vector<ii> rightLine;
	for(int i = 0; i < n; ++i)
	{
		char c;
		int cx, cy;
		cin >> c >> cx >> cy;
		// checando os casos
		if(cx == x)
		{
			if(cy < y)
				upperLine.pb(mp(mp(cy, cx), c));
			else
				lowerLine.pb(mp(mp(cy, cx), c));
		}
		else if(cy == y)
		{
			if(cx < x)
				leftLine.pb(mp(mp(cx,cy), c));
			else
				rightLine.pb(mp(mp(cx, cy), c));
		}
		else if(abs(cy-y) == abs(cx-x))
		{
			if(cy < y)
			{
				if(cx < x)
					upperLeftDiag.pb(mp(mp(cx, cy), c));
				else
					upperRightDiag.pb(mp(mp(cx, cy), c));
			}
			else if(cy > y)
			{
				if(cx < x)
					lowerLeftDiag.pb(mp(mp(cx, cy), c));
				else
					lowerRightDiag.pb(mp(mp(cx, cy), c));

			}
		}
	}
	if(upperLeftDiag.size() > 0)
		sort(upperLeftDiag.begin(), upperLeftDiag.end(), greater<ii>());
	if(upperRightDiag.size() > 0)
		sort(upperRightDiag.begin(), upperLeftDiag.end());
	if(lowerLeftDiag.size() > 0)
		sort(lowerLeftDiag.begin(), lowerLeftDiag.end(), greater<ii>());
	if(lowerRightDiag.size() > 0)
		sort(lowerRightDiag.begin(), lowerRightDiag.end());
	if(upperLine.size() > 0)
		sort(upperLine.begin(), upperLine.end(), greater<ii>());
	if(lowerLine.size() > 0)
		sort(lowerLine.begin(), lowerLine.end());
	if(leftLine.size() > 0)
		sort(leftLine.begin(), leftLine.end(), greater<ii>());
	if(rightLine.size() > 0)
		sort(rightLine.begin(), rightLine.end());
	bool check = false;
	if(upperRightDiag.size() > 0)
	{
		if(upperRightDiag[0].second == 'B' || upperRightDiag[0].second == 'Q')
			check = true;
	}	
	if(upperLeftDiag.size() > 0)
	{
		if(upperLeftDiag[0].second == 'B' || upperLeftDiag[0].second == 'Q')
			check = true; 
	}
	if(lowerRightDiag.size() > 0)
	{
		if(lowerRightDiag[0].second == 'B' || lowerRightDiag[0].second == 'Q')
			check = true;
	}
	if(lowerLeftDiag.size() > 0)
	{
		if(lowerLeftDiag[0].second == 'B' || lowerLeftDiag[0].second == 'Q')
			check = true; 
	}
	if(upperLine.size() > 0)
	{
		if(upperLine[0].second == 'R' || upperLine[0].second == 'Q')
			check = true;
	}
	if(lowerLine.size() > 0)
	{
		if(lowerLine[0].second == 'R' || lowerLine[0].second == 'Q')
			check = true;	
	}
	if(leftLine.size() > 0)
	{
		if(leftLine[0].second == 'R' || leftLine[0].second == 'Q')
			check = true;
	}
	if(rightLine.size() > 0)
	{
		if(rightLine[0].second == 'R' || rightLine[0].second == 'Q')
			check = true;
	}
	if(check)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}