#include<stdio.h>
#include<ctype.h>
int get_int(void);
int main(void)
{
    int i,j,k,h;
    do
    {
       printf("Height: ");    
       h = get_int();
    }while(h<0 || sizeof(h)!=4 || h>23);
    for(i=1;i<=h;i++)
    {
        for (j=0;j<h-i;j++)
        printf(" ");
        for(k=j;k<=h;k++)
        printf("#");
        printf("\n");
    }
    return 0;
}

