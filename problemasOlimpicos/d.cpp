#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>
#include <cassert>
#include <cstdio>
#include <queue>
#include <set>
#include <map>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <numeric>

#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;

int soma, ini, n, m, b, diff = 0;

int num[5] = {1, 10, 100, 1000, 10000};

int main(void)
{
	cin >> n >> m;

	forn(i, m)
	{
		cin >> b;
		cin >> ini;
		soma = 0;
		forn(j, n - 1)
		{
			int temp;
			cin >> temp;
			soma += temp;
		}

		int at = ini;
		int ant = ini;
		while (soma + at > b && at > num[0] && soma < b)
		{
			ant = at;
			at = at * 0.1;
		}

		while (soma + at <= b && at <= num[4])
		{
			ant = at;
			at = at * 10;
		}

		diff += (ant >= ini)? abs(ant - ini) : ant; 
	}

	printf("%d\n", diff );

	return 0;
}