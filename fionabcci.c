#include <time.h>
#include <stdio.h>
#include <conio.c>

#include <string.h>
#include<stdlib.h>
#include <ctype.h>
#define IND 8
//arreglo, limite menor (izquierda), limite mayor(derecha)
//Nos dice qque todos los elementos antes del que estamos tienen que ser menores, y los despues mayores, siempre
void quicksort(int array[],int limite_izq,int limite_der);
void ordenar(float [], int, char [][10]);
int busqueda(float [], int, int, float, char [][10]) ;
void suma (int [], int , int *);
void mergesort(int arreglo[], int, int);
void busqueda_secuencial(int arr[], int, char [][10]);
int fiobinacci(int n);
int fiobinacci_recursive(int n);

//int quicksort(int [], int, int);
int main()
{
   float age[IND]={48.442, 1142000.0, 2780000.0, 27.750, 1099000.0, 1285000.0, 112.492 , 1973000.0};
  float area=0.0;
   area=2780000.0;
   char names[IND][10]={"Rep.Dom", "Colombia", "Argentina", "Haiti", "Bolivia", "Peru", "Honduras", "Mexico"};
   ordenar(age,IND,names); //ordenamiento burbuja
   for(int z=0;z<IND;z++)
      printf("\nAqui   %12s    %.5f km cuadrados", names[z], age[z]);
   printf("\n");
   busqueda(age,0,IND, area, names);
   //////////
   printf("\nResultado de 14   %d", fiobinacci_recursive(14));
   return 0;
}
void busqueda_secuencial(int arr[], int n, char names [][10])
{
   int a;
   for(a=0;a<n;a++){
      if(arr[a]<18)
         printf("\n %s tiene menos de 18 annos. Tiene %d", names[a], arr[a]);
   }
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
//peor caso 0(n^2) tiene que iterar por todos los elementos
void ordenar(float arreglo[], int n, char names[][10])
{
   int a,b,swap=0;
   float ok=0;;
   char nombre[10];
   for(a=0;a<n;a++){ //numero a comparar 1
      swap=0;ok=0;;
      for(b=0;b<n;b++){ //numero a comparar 2
         if(arreglo[b]>arreglo[b+1] && b+1<IND){// si es mayor se sustituye
            swap=1;
            ok=arreglo[b];
            strcpy(nombre, names[b]);
            arreglo[b]=arreglo[b+1];
            arreglo[b+1]=ok;
            strcpy(names[b], names[b+1]);
            strcpy(names[b+1], nombre);
         }
      }
   if(swap==0)
      return;
   }
}

//Binary Search
int busqueda(float arr[], int inicio, int derecho, float x, char names[][10])
{
    if (derecho >= inicio) {
        int middle= inicio + (derecho - inicio) / 2;
        if (arr[middle] == x) {
            printf("\nEl pais de %s tiene el area buscada: %f", names[middle],arr[middle]);
            return 1; }
        if (arr[middle] > x)
            return busqueda(arr, inicio, middle - 1, x, names);
         if(arr[middle]<x)
            return busqueda(arr, middle + 1, derecho, x,names);
    }
    printf("\nNo existe un pais registrado con el area introducida.\n");
    return 0;
}
int fiobinacci(int n)
{
   printf("\n");
   int suma=0,a=0, resultados[n];
   for(a=0;a<=n;a++)
   {
      if(a==0)
      {
         suma=0;
         resultados[a]=suma;
         printf("[");
      }
      if(a==1)
      {
         suma=1;
         resultados[a]=suma;
      }
      else if (a>1)
      {
         suma=resultados[a-2]+resultados[a-1];
         resultados[a]=suma;
      }
      if(a!=n)
         printf("%d, ", suma);
      else
         printf("%d]", suma);
   }
   return suma;
}
int fiobinacci_recursive(int n)
{
   if(n==1 || n==0)
      return n;
   else
   return(fiobinacci_recursive(n-1) + fiobinacci_recursive(n-2));
}
