#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <set>
#include <map>
#include <utility>

using namespace std;

#define pb push_back
#define fi first
#define se second
#define mp make_pair

#define TRACE(x...)

#define PRINT(x...) TRACE(printf(x)) 
#define WATCH(x) TRACE(cout << #x << " = " << x << endl)
#define WATCH(x) TRACE(cout << #x << " = " << x << endl)

const int INF = 0x3F3F3F3F; const int NEGINF = 0xC0C0C0C0; const int NULO = -1;
const double EPS = 1e-10;

string num1, num2;
double v;

double apostRecebe()
{
	int sz1 = num1.size(), sz2 = num2.size(), vez = 0;

	for (int i = 0; i < 4; ++i)
	{
		if(num1[sz1 - 1 - i] == num2[sz2 - 1 - i])
		{
			vez++;
		}
		else
			break;
	}

	if(vez == 4)
		return 3000 * v;

	else if(vez == 3)
		return 500 * v;

	else if(vez == 2)
		return 50 * v;
	else
	{
		int bicho1 = 0, bicho2 = 0, dec = 10;
		for (int i = 1; i >= 0; --i)
		{
			bicho1 += (num1[sz1 - 1 - i] - '0') * dec;
			bicho2 += (num2[sz2 - 1 - i] - '0') * dec;

			dec = 1;

			PRINT("%d %d\n", bicho1, bicho2);
		}
		if((bicho1 >= 97 || bicho1 == 0) && (bicho2 >= 97 || bicho2 == 0))
		{
			return 16 * v;
		}
		if(ceil((double)bicho1 / 4) == ceil((double)bicho2 / 4))
			return 16 * v;
	}

	return 0.0;
}

int main(void)
{

	cin >> v >> num1 >> num2;

	while(v > 0)
	{
		TRACE(cout << "num1: " << num1 << " / num2: " << num2 << endl;);
		if(num1.size() < 4)
		{
			string novo;
			novo.resize(4);

			for (int i = 0; i < 4 - num1.size(); ++i)
			{
				novo.pb('0');
			}

			for (int i = 0; i < num1.size(); ++i)
			{
				novo.pb(num1[i]);
			}

			num1 = novo;

			TRACE(
				cout << "Novo num: " << num1 << endl;
				);
		}
		if(num2.size() < 4)
		{
			string novo;
			novo.resize(4);

			for (int i = 0; i < 4 - num2.size(); ++i)
			{
				novo.pb('0');
			}

			for (int i = 0; i < num2.size(); ++i)
			{
				novo.pb(num2[i]);
			}

			num2 = novo;

			TRACE(
				cout << "Novo num: " <<num2 << endl;
				);
		}

		double resp = apostRecebe();

		cout << fixed << setprecision(2);

		cout << resp << endl;

		cin >> v >> num1 >> num2;
	}

	return 0;
}