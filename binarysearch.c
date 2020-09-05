#include <time.h>
#include <stdio.h>
#include <conio.c>

#include <string.h>
#include<stdlib.h>
#include <ctype.h>
#define IND 7
//arreglo, limite menor (izquierda), limite mayor(derecha)
//Nos dice qque todos los elementos antes del que estamos tienen que ser menores, y los despues mayores, siempre
void quicksort(int array[],int limite_izq,int limite_der);
void ordenar(int [], int, char [][10]);
int busqueda(int [], char[][10], int);
void suma (int [], int , int *);
//int quicksort(int [], int, int);
int main()
{
   int age[IND]={25, 30, 15, 18, 13, 60, 5}, *diana;
   diana = (int *)malloc(sizeof(int[IND]));
   char names[IND][10]={"John", "Maria", "Kelvin", "Diana", "Reynold", "Jose", "Camila"};
   ordenar(age,IND,names); //lo puedo poner con quicksort, pero por los nombres lo deje asi
   //Muestra los nombres con sus edades
   for(int z=0;z<IND;z++)
      printf("\n%s %d", names[z], age[z]);
      printf("\n");
      busqueda(age,names,IND);
      int arreglo[IND]={3,5,2,1,7,9,0};
      //int t[4]={1,2,3,4};
      printf("\n");
      //Muestra los nombres con sus edades organizadas
      for(int z=0;z<IND;z++)
      printf("\n%s %d", names[z], age[z]);
      printf("\n");
      quicksort(arreglo,0,IND-1);
      //muestra los numeros del arreglo ordenados
      printf(" \nNumeros del arreglo ordenado:");
      for(int z=0;z<IND;z++)
         printf(" %d", arreglo[z]);
        suma(arreglo,IND, diana);
        //muestra el resultado
        printf("\nSumas resultado= [");
        for(int z=0;z<IND;z++)
         printf(" %d,", diana[z]);
         printf("]");
        free(diana);
   return 0;
}
void suma (int arreglo[], int n, int *arr)
{
   int a=0, b=0, sum=0 ;
   //printf ("Rango [%d,%d] = ", val1, val2);
   for(a=0;a<n;a++){
      for(b=b;b<=arreglo[a];b++){
         sum+=b;
         //printf(" +%d", b);
      }
      arr[a]=sum;
   }
   //printf("\nsuma %d\n", sum);
}
//Ordenamiento quicksort
void quicksort(int array[],int limite_izquierdo,int limite_derecho)
{
    int izquierda=0,derecha=0,sustituir=0,mitad=0;;
    izquierda=limite_izquierdo;
    derecha = limite_derecho;
    mitad = array[(izquierda+derecha)/2]; //elemento que esta en la mitad de los limites que nos dieron
    do{
        while(array[izquierda]<mitad && izquierda<limite_derecho)izquierda++;
        //incrementa hasta que encuentres un numero mayor al pivote
        while(mitad<array[derecha] && derecha > limite_izquierdo)derecha--;
        //disminuye hasta que encuentres un numero menor al pivote
        //Aqui, ya se tendra el indice con el numero mayor y con el numero menor al pivote, y ests dos se van a intercambiar
        if(izquierda <=derecha) //el INDICE (NO elemento del arreglo) tiene que ser menor al de la derecha
        {
            sustituir= array[izquierda];
            array[izquierda]=array[derecha];
            array[derecha]=sustituir;
            izquierda++;//nos movemos al elemento que sigue a la derecha (para hacer el proceso de arriba again)
            derecha--; //nos movemos al elemento que sigue a la izquierda
            //printf("\n lista[izq]:%d izq:%d lista[derecha]:%d derecha:%d", lista[izq-1], izq, lista[der+1],der);
        }

    }while(izquierda<=derecha);
    //mientras el indice no sea igual o el indice de la izq sea mayor al de la derecha
    //Si los indices de izq y der se cruzan, se sale
    if(limite_izquierdo<derecha)
      quicksort(array,limite_izquierdo,derecha);
    //desde el primer elemento hasta donde esta el pivote
    //organizara los elementos menores al pivote
    if(limite_derecho>izquierda)
      quicksort(array,izquierda,limite_derecho);
    //desde el numero despues del pivote (izq) hasta el indice maximo
    //organizara los elementos del otro lado del arreglo mayores al pivote

}
//Ordenamiento Burbuja
void ordenar(int arreglo[], int n, char names[][10])
{
   int a,b,ok=0;
   char nombre[10];
   for(a=0;a<n;a++){ //el proceso de sustitucion COMPLETO se hara n veces
      for(b=0;b<n;b++){
         if(arreglo[b]>arreglo[b+1]){// si es mayor se sustituye
            ok=arreglo[b];
            strcpy(nombre, names[b]);
            arreglo[b]=arreglo[b+1];
            arreglo[b+1]=ok;
            strcpy(names[b], names[b+1]);
            strcpy(names[b+1], nombre);
         }
      }
   }
}
//Binary Search
int busqueda(int array[], char names[][10], int n)
{
   int middle=(int)n/2, a;
   if(array[middle]<18){
      for(a=0;a<=middle;a++)
         printf("\n %s tiene %d annos, es menor de edad",names[a],array[a]);
      return 1;
   }
   if(array[middle]==18){
      return busqueda(array,names,n-1);
   }
   if(array[middle]>18){
      return busqueda(array,names, n-1);
   }
   return 0;
}
