#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int t;
    cin >> t;
    FILE * pFile;
    pFile = fopen ("myfile.txt","w");
    int a = 1;
    while(t--)
    {
        int ms;
        string crowd;
        cin >> ms >> crowd;
        int total = 0;
        int up = 0;
        for(int i = 0; i < crowd.size(); ++i)
        {
            if(up <  i)
            {
                total += i - up;
                up += (i-up) + (crowd[i] - '0');
            }
            else
                up += (crowd[i] - '0');

        }
        fprintf(pFile,"Case #%d: %d\n", a, total);
        a++;
    }
    fclose(pFile);
    return 0;
}
