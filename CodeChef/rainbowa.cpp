#include <bits/stdc++.h>

using namespace std;

#define fr(i,a,b) for(int (i) = (a); (i) < (b); ++(i))
#define rp(i,n) fr(i,0,n)
#define fi first
#define se second
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define mt make_tuple
#define mp make_pair
#define sz(a) (int)(a.size())

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

const int inf = 0x3f3f3f3f;
const int neginf = 0xc0c0c0c0;
const int maxn = 101;

int t, n;

int main() {
    scanf("%d", &t);
    while(t--) {
        cin >> n;
        vi arr(n);
        vi freq(8, 0);
        bool ok = true;
        int last = 0;
        bool inc = true;
        rp(i, n) {
            cin >> arr[i];
            if(arr[i] > 7 || arr[i] < 1)
                ok = false;
            else
                freq[arr[i]]++;

            if(arr[i] == last) continue;
            else{
                if(arr[i] == last + 1 && !inc){
                    ok = false;
                }
                else if(arr[i] == last-1 && inc){
                    ok = false;
                }
            }
            if(abs(arr[i] - last) > 1) ok = false;
            last = arr[i];
            if(last == 7) inc = false;
        }
        if(n < 13){
            puts("no");
            continue;
        }
        vi freq2(arr);
        reverse(all(freq2));
        for(int i = 0; i < n; ++i){
            if(arr[i] != freq2[i]){
                ok = false;
            }
        }
        fr(i, 1, 8){
            if(freq[i] == 0) ok = false;
        }
        if(ok) puts("yes");
        else puts("no");
    }
}
