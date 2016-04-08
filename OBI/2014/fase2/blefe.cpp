#include <cmath>
#include <climits>
#include <queue>
#include <vector>
#include <map>
#include <cstdlib>
#include <fstream>
#include <iomanip>   
#include <iostream>  
#include <sstream>  // istringstream buffer(myString);
#include <stack>
#include <algorithm>
#include <cstring>
#include <cassert>
#include <set>
#include <cstdio>
using namespace std;
#define F(i,L,R) for (int i = L; i < R; i++) //next four are for "for loops"
#define FE(i,L,R) for (int i = L; i <= R; i++)
#define FF(i,L,R) for (int i = L; i > R; i--)
#define FFE(i,L,R) for (int i = L; i >= R; i--)
#define getI(a) scanf("%d", &a) //next three are handy ways to get ints, it's also force you to use '&' sign
#define getII(a,b) scanf("%d%d", &a, &b)
typedef int elem_t;
typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii; 
typedef vector<ii> vii;
 
int main()
{
    int a,b;
    getII(a,b);
    set<int> plays;
    F(i,0,a)
    {
        int x;
        cin >> x;
        plays.insert(x);
    }
    F(j,0,b)
    {
        int p;
        cin >> p;
        if(plays.find(p) == plays.end())
        {
            cout << p << endl;
            return 0;
        }
        else
        {
            for(auto& x : plays)
                plays.insert(x + p);
            plays.insert(p);
        }
    }   
    cout << "sim" << endl;
    return 0;
}
