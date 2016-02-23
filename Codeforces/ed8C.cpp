#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int size, dif;
    scanf("%d%d", &size, &dif);
    int curdif = 0;
    string word;
    cin >> word;
    string ans;
    for(int i = 0; i < word.size(); ++i)
    {
        bool famb = false;
        int down = word[i] - 'a';
        int up = 'z' - word[i];
        if(up > down)
            famb = true;
        int maxDif = max(up,down);
        while(maxDif > dif-curdif)
            maxDif--;
        if(famb)
            ans += word[i] + maxDif;
        else
            ans += word[i] - maxDif;
        curdif += maxDif;
    }
    if(dif > curdif)
        cout << -1 << endl;
    else
        cout << ans << endl;
    return 0;

}
