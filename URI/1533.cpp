#include <stdio.h>



int main()
{
    int N;
    int nums[1010];
    while(scanf("%d", &N), N!=0)
    {
        int a, M, sM, indexM, indexSM;
        for(int i=1; i<=N; i++)
        {
            scanf("%d", &a);
            nums[i] = a;
        }
        M=nums[1];
        for(int i =2; i<=N; i++)
        {
            if(nums[i]>M)
            {
                M=nums[i];
            }
        }
        sM = -1;
        for(int i=1;i<=N; i++)
        {
            if(nums[i]>sM && nums[i]!=M)
            {
                sM = nums[i];
                indexSM = i;
            }
        }
        printf("%d\n", indexSM);
    
    }

}
