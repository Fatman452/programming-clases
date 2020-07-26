#include <time.h>
#include <stdio.h>
#include <conio.c>

#include <string.h>
#include<stdlib.h>
#include <ctype.h>
#define IND 20

int busqueda(int [], int);
int main()
{
   int array[IND]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20},num;
   printf("\nIntroduzca el numero a buscar: ");
   scanf ("%d", &num);
   printf("result %d",busqueda(array,num));
   return 0;
}
int busqueda(int array[], int num)
{
   int a;
   for(a=0;a<20;a++)
   {
      if(array[a]==num)
         return 1;

   }
   return 0;
   //printf("%d", x);
}
