#include <stdio.h>
#include <algorithm>
#include <utility>
#define WT 50
 
using namespace std;
 
bool compare(const pair<int, int>&i, const pair<int, int>&j)
{
    return i.first < j.first;
}
 
int main()
{
    int N;
    scanf("%d", &N);
    for (int k = 0; k < N; ++k)
    {
        int nPacs;
        scanf("%d", &nPacs);
        pair<int,int> items[100];
        for (int i = 0; i < nPacs; ++i)
        {
            scanf("%d %d", &items[i].first, &items[i].second);
        }
 
        sort(items, items+nPacs,compare);
 
        int matrix[100][51];
 
        for (int i = 0; i < nPacs; ++i)
        {
            matrix[i][0] = 0;
        }
 
        for (int j = 0; j < WT+1; ++j)
        {
            if(items[0].second>j)
                matrix[0][j] = 0;
            else
                matrix[0][j] = items[0].first;
        }
 
        for (int i = 1; i < nPacs; ++i)
        {
            for (int j = 1; j < WT+1; ++j)
            {
                if(items[i].second>j)
                {
                    matrix[i][j] = matrix[i-1][j];
                }
                else
                {
                    matrix[i][j] = max(matrix[i-1][j], matrix[i-1][j-items[i].second]+items[i].first);
                }
            }
        }
 
 
        /*for (int i = 0; i < nPacs; ++i)
        {
            for (int j = 0; j < 51; ++j)
            {
                printf("%d ", matrix[i][j]);
            }
            printf("\n");
        }
        printf("\n");*/
 
        int i = nPacs-1;
        int j = WT;
        int qtItems = 0;
        int peso = 0;
        int val = 0;
        while(i>0)
        {
            if( matrix[i][j] - matrix[i-1][j - items[i].second] == items[i].first )
            {
            qtItems++;
            j=j-items[i].second;
            peso = peso + items[i].second;
            val = val + items[i].first;
          }
          i--;
        }
        if(matrix[i][j]==items[i].first)
        {
            qtItems++;
        j=j-items[i].second;
        peso = peso + items[i].second;
        val = val + items[i].first;
        }
 
        printf("%d brinquedos\n", val);
        printf("Peso: %d kg\n", peso);
        printf("sobra(m) %d pacote(s)\n", nPacs - qtItems);
        printf("\n");
 
    }
 
    return 0;
}
