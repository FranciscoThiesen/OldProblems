#include <cstdio>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <utility>
#include <istream>

using namespace std;

int main()
{
    string s;
    while(getline(cin, s))
    {
        int fst = 0;
        int snd = 0;
        for(int i = 0; i < s.size(); ++i)
        {
            if(i%2 == 0 && s[i] >= 'a' && s[i] <= 'z')
            {
                fst++;
            
            }
            else if(i%2 == 1 && s[i] >= 'A' && s[i] <= 'Z')
            {
                fst++;
            }
        }
        for(int i = 0; i < s.size(); ++i)
        {
            if(i%2 == 1 && s[i] >= 'a' && s[i] <= 'z')
            {
                snd++;
            
            }
            else if(i%2 == 0 && s[i] >= 'A' && s[i] <= 'Z')
            {
                snd++;
            }
        }
        cout << min(snd, fst) << endl;
    }
    return 0;
}
