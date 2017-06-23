
#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include "helpers.h"

const int MAX = 65536;

int main(int argc, string argv[])
{
// ensure proper usage
if (argc != 2)
{
    printf("Usage: ./find needle\n");
    return -1;
}

// remember needle
int needle = atoi(argv[1]);

// fill haystack
int size;
int haystack[MAX];
for (size = 0; size < MAX; size++)
{
    // wait for hay until EOF
    printf("\nhaystack[%i] = ", size);
    int straw = GetInt();
    if (straw == INT_MAX)
    {
        break;
    }

    // add hay to stack
    haystack[size] = straw;
}
printf("\n");

// sort the haystack
sort(haystack, size);
int n;

for(n=0;n<size;n++)
    {
        printf("%i \n",haystack[n]);
    }

//try to find needle in haystack
if (search(needle, haystack, size)==1)
{
    printf("\nFound needle in haystack!\n\n");
    return 0;
}
else if(search(needle, haystack, size)==0)
{
    printf("\nDidn't find needle in haystack.\n\n");
    return 1;
}

}