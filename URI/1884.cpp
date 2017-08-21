#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define fr(i,a,b) for(int (i) = (a); (i) < (b); ++(i))
#define rp(i, n) fr(i,0,n)
#define pb push_back
#define mp make_pair

const int maxn = 2002;
int t, n, k, a, b, h;

typedef pair<int, int> ii;
typedef unsigned long long ull;
typedef long long ll;
struct Monstro{
    int fi;
    int se;
};

vector<ii> m;
bool cmpMonstro(const ii& a, const ii& b){
    if(a.fi != b.fi)
        return (a.fi < b.fi);
    else return (a.se >= b.se);
}

bool cmpMonstro2(const ii& a, const ii& b){
    int aDiff = a.se - a.fi;
    int bDiff = b.se - b.fi;
    return aDiff >= bDiff;
}

bool solve(vector<ii>& ms){
    ll life = h;
    int needMp = 0;
    int toKill = (int) ms.size();
    sort(ms.begin(), ms.end(), cmpMonstro);
    multiset<ii, function<bool(const ii&, const ii&)> > canKill(cmpMonstro2);
    int end = -1;
    for(auto v : ms){
        if(life > v.fi){
            canKill.insert(v);
            end++;
        }
        else break;
    }
    while(!canKill.empty()){
        ii K = *(canKill.begin());
        canKill.erase(canKill.begin());
        if(life > K.fi){
            int diff = K.se - K.fi;
            life += diff;
            if(diff > 0){
                for(int i = end + 1; i < n; ++i){
                    if(life > ms[i].fi){
                        canKill.insert(ms[i]);
                        end++;
                    }
                    else break;
                }
            }
        }
        else{
            needMp++;
        }
    }
    return (needMp + (n-1-end)) <= k;
}
main(){
    scanf("%d", &t);
    while(t--){
        m.clear();
        scanf("%d %d %d", &n, &h, &k);
        rp(i, n){
            scanf("%d %d", &a, &b);
            m.push_back(mp(a,b));
        }
        bool ok = solve(m);
        if(ok) puts("Y");
        else puts("N");
    }
}   
