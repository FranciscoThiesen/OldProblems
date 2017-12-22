#include <bits/stdc++.h>
 
using namespace std;
 
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
  
const int MAXN = 1 << 21;
string S;
int N, gap;
int sa[MAXN], pos[MAXN], tmp[MAXN], lcp[MAXN];
 
bool sufCmp(int i, int j)
{
	if (pos[i] != pos[j])
		return pos[i] < pos[j];
	i += gap;
	j += gap;
	return (i < N && j < N) ? pos[i] < pos[j] : i > j;
}
 
void buildSA()
{
	N = (int)S.size();
	REP(i, N) sa[i] = i, pos[i] = S[i];
	for (gap = 1;; gap *= 2)
	{
		sort(sa, sa + N, sufCmp);
		REP(i, N - 1) tmp[i + 1] = tmp[i] + sufCmp(sa[i], sa[i + 1]);
		REP(i, N) pos[sa[i]] = tmp[i];
		if (tmp[N - 1] == N - 1) break;
	}
}
 
void buildLCP()
{
	for (int i = 0, k = 0; i < N; ++i) if (pos[i] != N - 1)
	{
		for (int j = sa[pos[i] + 1]; S[i + k] == S[j + k];)
		++k;
		lcp[pos[i]] = k;
		if (k)--k;
	}
}
 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t = 1;
	while(t--){
		cin >> S;
		buildSA();
		buildLCP();
		// dp no lcp
		int ans = N - sa[0];
		for(int i = 0; i < N-1; ++i){
			ans += max(0, N - sa[i+1] - lcp[i]);
		}
		cout << ans << endl;
	}
	return 0;
} 
