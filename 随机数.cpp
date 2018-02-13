#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
    srand(time(0));
    for(int i=0;i<=2000;i++)
        printf("%d %d\n",rand()%10000, rand()%10000);
    //printf("\n");
    return 0;
}
