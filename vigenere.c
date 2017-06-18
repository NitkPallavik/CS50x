#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include<ctype.h>

 int main(int argc,string argv[])
 {
   if ((argc!=2) || (!isalpha(argv[1][0])))
        {
        printf("usage : ./vignere k \n");
        return 1;
    }
    string key=argv[1];
    int i=0,n=0,k;
    for(i=0;i<strlen(key);i++)
    {
     if((isalpha(key[i])))
        n++;    
    }
    if(i!=n)
    {
        printf("usage : ./vignere k \n");
        return 1;
    }
    printf("plaintext: "); 
    string input = get_string();
    if(input != NULL)
    { 
        i=0,k=0;
        n = strlen(input);
        printf("ciphertext: ");
        while (input[i]!='\0')
       {
          int encry=input[i];
          if (isalpha(input[i]))
          {
              if(k==strlen(key))
                  k=0;
             if(islower(input[i]) && islower(key[k]))
             {
                if((input[i]+(key[k]%97))<122)
                 encry=input[i]+(key[k]%97);
                else
                 encry=input[i]+(key[k]%97)-122+96;
              }
             if(isupper(input[i]) && isupper(key[k]))
              {
                if((input[i]+(key[k]%65))<90)
                encry=input[i]+(key[k]%65);
                else
                encry=input[i]+(key[k]%65)-90+64;
               }
               if(islower(input[i]) && isupper(key[k]))
             {
                if((input[i]+(key[k]%65))<122)
                 encry=input[i]+(key[k]%65);
                else
                 encry=input[i]+(key[k]%65)-122+96;
              }
             if(isupper(input[i]) && islower(key[k]))
              {
                if((input[i]+(key[k]%97))<90)
                encry=input[i]+(key[k]%97);
                else
                encry=input[i]+(key[k]%97)-90+64;
               }
             k++;
           }
            
            printf("%c",encry);
            i++; 
        }    
    }
    printf("\n");
    return 0;
 }