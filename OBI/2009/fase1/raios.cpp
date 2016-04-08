#include <cstdio>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

int main()
{
    int c;
    cin >> c;
    bool dup = false;
    int mat[501][501];
    memset(mat, 0,sizeof (mat[0][0]) * 501 * 501);
    for(int i = 0; i < c; i++)
    {
        int a,b;
        cin >> a >> b;
        mat[a][b]++;
        if(mat[a][b] >= 2)
        {
            dup = true;
            break;
        }
        
    }
    if(dup)
        cout << "1"<< endl;
    else
        cout << "0" << endl;
    return 0;
}
