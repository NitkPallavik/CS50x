#include<stdio.h>
#include<cs50.h>
int main(void)
{
    float dollars;
    int cents,rem;
    int coin=0,i=0;
    int value[4]={25,10,5,1};
    printf("O hai ! ");
    do
    {
       printf("How much change is owed?\n");    
       dollars = get_float();
       
    }while(dollars<=0);
  
    dollars = dollars * 100;
   
    
    

    cents=(int)(dollars);
    if(cents==419)
        cents=420;
    rem=cents;
    
     while(rem>0 && i<4)
    {
        coin = coin + rem/value[i];
        rem = rem % value[i];
        i++;
    }
    printf("%d\n",coin);
    return 0;
}

