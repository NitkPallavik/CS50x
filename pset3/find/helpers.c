#include <cs50.h>
#include "helpers.h"

bool binarysearch(int key, int array[], int min, int max);

bool search(int value, int values[], int n)
{
 return binarysearch(value, values,0, n-1);
}

bool binarysearch(int key, int values[], int l, int r)
{
   if (r >= l)
   {
        int mid = l + (r - l)/2;
        if (values[mid] == key)  return true;
        if (values[mid] > key) return binarysearch(key,values, l, mid-1);
        return binarysearch(key,values, mid+1, r);
   }
   return false;
}
/*
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
   int i, j,temp;
   for (i = 0; i < n-1; i++)      
  {
      for (j = 0; j < n-i-1; j++) 
          {
              if (values[j] > values[j+1])
              {
                  temp=values[j];
                  values[j]=values[j+1];
                  values[j+1]=temp;
              }
           }
  }       
       return;
}
