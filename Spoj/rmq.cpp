#include <bits/stdc++.h>

using namespace std;


class SegmentTree{
private: vector<int> st, A;
	int n;
	int left(int p)
	{
		return (p << 1);
	}
	int right(int p)
	{
		return (p << 1) + 1;
	}

	void build(int p, int L, int R)
	{
		if(L == R)
			st[p] = L;
		else
		{
			build(left(p), L, (L+R)/2);
			build(right(p), (L+R)/2 + 1, R);
			int p1 = st[left(p)], p2 = st[right(p)];
			st[p] = (A[p1] <= A[p2] ? p1 : p2);
		}
	}

	int rmq(int p, int L, int R, int i, int j)
	{
		if(i > R || j < L) return -1;
		if(L >= i && R <= j) return st[p];

		
	}
};

