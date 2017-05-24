/*input
1
3
0 3 7
*/
#include <bits/stdc++.h>

using namespace std;

map<int, int> tree;
unordered_set<int> inseriZero;

void insertVal(int n, int pos)
{
	if(tree[pos] == 0 && inseriZero.find(pos) == inseriZero.end())
	{
		tree[pos] = n;
		if(!n)
			inseriZero.insert(pos);
	}
	else if(n < tree[pos])
		insertVal(n, 2*pos + 1);
	else
		insertVal(n, 2*pos + 2);
}

void printInfix(int pos)
{
	if(!tree[pos] && inseriZero.find(pos) == inseriZero.end())return;
	printInfix(2*pos + 1);
	printf(" %d", tree[pos]);
	printInfix(2*pos + 2);
}

void printPostfix(int pos)
{
	if(!tree[pos] && inseriZero.find(pos) == inseriZero.end())return;
	printPostfix(2*pos+1);
	printPostfix(2*pos + 2);
	printf(" %d", tree[pos]);
}

void printPrefix(int pos)
{
	if(!tree[pos] && inseriZero.find(pos) == inseriZero.end())return;
	printf(" %d", tree[pos]);
	printPrefix(2*pos+1);
	printPrefix(2*pos + 2);

}

int main()
{
	int t, n, k, count = 1;
	scanf("%d", &t);
	while(t--)
	{
		tree.clear();
		inseriZero.clear();
		scanf("%d", &n);
		for(int i = 0; i < n; ++i)
		{
			scanf("%d", &k);
			insertVal(k, 0);
		}
		printf("Case %d:\n", count);
		printf("Pre.:");
		printPrefix(0);
		printf("\nIn..:");
		printInfix(0);
		printf("\nPost:");
		printPostfix(0);
		printf("\n\n");
		count++;
	}
	return 0;
}