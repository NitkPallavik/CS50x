#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include<ctype.h>
 int main(void)
 {
    string input = get_string();
    if(input != NULL)
    {
    int i =0; 
    int n = strlen(input);
    printf("%c",toupper(input[i++]));
    while (i<=n)
    {
        if (input[i]==32 && input[i+1] != '\0')
        {
            printf("%c", toupper(input[i+1]));
        }
      i++; 
    }
    }
  printf("\n");

 }