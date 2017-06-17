#include<stdio.h>
#include<ctype.h>
int get_int(void);
int main(void)
{
    int min;
    int Bottles=0;
    do
    {
        printf("Minutes: ");
        min = get_int();
    }while(min<0 || sizeof(min)!=4);
    if(min>0)
    Bottles=12*min;
    printf("Bottles: %d\n",Bottles);
    return 0;
}

