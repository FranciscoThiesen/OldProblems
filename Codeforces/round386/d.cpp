/*input
5 4 0
1 2
3 1
*/
#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<pair<int, int> > vii;

int main()
{
	int maxCord, x1, x2;
	cin >> maxCord >> x1 >> x2;
	int sTram, sIgor;
	cin >> sTram >> sIgor;
	int tramPos, tramDir;
	cin >> tramPos >> tramDir;
	//Case 1 igor faster than tram
	int s;
	int tramTime, igorTime;
	if(sIgor <= sTram)
	{
		s = abs(x1 - x2) * sIgor;
	}
	else // Case 2, it might be better by tram
	{
		//Case 2.1 Tram is going on the same direction, but is ahead of Igor
		if(x1 < x2)
		{
			igorTime = (x2 - x1)*sIgor;
			// x1 maior que x2
			if(tramPos == x1)
			{
				if(tramDir == 1)
					s = min((x2-x1)*sIgor,  (x2-x1)*sTram);
				else if(tramDir == -1)
					s = min((x2-x1)*sIgor, (x1 + x2)*sTram);
			}
			else if(tramPos == x2)
			{
				if(tramDir == 1)
					tramTime = (maxCord - tramPos + maxCord + x2)*sTram;
				else
					tramTime = (tramPos + x2)*sTram;
			}
			else if(tramPos > x2 && tramDir == 1)
				tramTime = (maxCord-tramPos + maxCord + x2)*sTram;
			else if(tramPos > x2 && tramDir == -1)
				tramTime = (tramPos + x2)*sTram;
			else if(tramPos < x2 && tramDir == 1)
			{
				if(tramPos > x1)
					tramTime = (maxCord-tramPos + maxCord + x2)*sTram;
				else
					tramTime = (x2 - tramPos)*sTram;
			}
			else if(tramPos < x2 && tramDir == -1)
				tramTime = (x2 + tramPos)*sTram;

			
			s = ((igorTime < tramTime)? igorTime : tramTime);
		}
		else
		{
			igorTime = (x1 - x2)*sIgor;
			//x1 > x2
			if(tramPos == x1)
			{
				if(tramDir == -1)
					s = min((x1-x2)*sIgor,  (x1-x2)*sTram);
				else if(tramDir == -1)
					s = min((x1-x2)*sIgor, (maxCord - x1 + maxCord - x2)*sTram);
			}
			else if(tramPos == x2)
			{
				if(tramDir == 1)
				{
					tramTime = (maxCord - tramPos + maxCord - x2)*sTram;
				}
				else
					tramTime = (tramPos + maxCord + maxCord - x2)*sTram;
			}
			else if(tramPos > x2 && tramDir == 1)
			{
				
				tramTime = (maxCord-tramPos+(maxCord-x2))*sTram;
			}
			else if(tramPos > x2 && tramDir == -1)
			{
				if(tramPos < x1)
					tramTime = (tramPos + maxCord + (maxCord-x2));
				else
					tramTime = (tramPos - x2)*sTram;
			}
			else if(tramPos < x2 && tramDir == 1)
			{
				tramTime = (maxCord-tramPos+maxCord-x2)*sTram;
			}
			else if(tramPos < x2 && tramDir == -1)
			{
				tramTime = (tramPos + maxCord + (maxCord-x2))*sTram;
				
			}
			s = ((igorTime < tramTime)? igorTime : tramTime);
		}
	}
	cout << s << endl;
	return 0;
}
