#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include<ctype.h>

 int main(int argc,string argv[])
 {
        if ( argc != 2)    
       {
            printf("usage : ./caesar k \n");
            return 1;
        }
    int key=atoi(argv[1]);
    int i=0,n;
    if(key>26)
    key=key%26;
    printf("plaintext: "); 
    string input = get_string();
    if(argc==2)
    {
    if(input != NULL)
    { 
        n = strlen(input);
        printf("ciphertext: ");
        while (input[i]!='\0')
       {
          int encry=input[i];
          if (isalpha(input[i]))
          {
            if(islower(input[i]))
            {
                if((input[i]+key)<122)
                 encry=input[i]+key;
                else
                encry=input[i]+key-122+96;
            }
            else
            {
                if((input[i]+key)<90)
                encry=input[i]+key;
                else
                encry=input[i]+key-90+64;
            }
          }
          printf("%c",encry);
          i++; 
        }    
    }
    printf("\n");
    }
    return 0;
 }