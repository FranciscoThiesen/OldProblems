#include <stdio.h>

int main(void) {
    int t;
    int w;
    int b;
    int i;
    int casosemp = 0;
    scanf("%d %d %d", &t, &w, &b);
    if(b >= w){
                casosemp = casosemp + w - 1;
           }
            else{
                casosemp = casosemp + b - 1;
            }
    for(i = 1; i <= t; i++){
        if(i % (w*b) == 0){
            casosemp++;
            if(b >= w){
                casosemp = casosemp + w - 1;
            }
            else{
                casosemp = casosemp + b - 1;
            }
        }
    }
    printf("%d", casosemp);
}