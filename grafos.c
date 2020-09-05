#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
 
#define CANT 10
#define INFINITE 9999

typedef struct nodo
{
    int node_hijo;
    int arista;
    struct nodo *next;
}NODO;


typedef struct graph{
    int nodo_actual[CANT];
    int peso[CANT];
    NODO *head[CANT];
    NODO *etiqueta[CANT];
}GRAPH;
typedef struct arista
{
    int padre; 
    int hijo; 
    int peso;
}ARISTA;
typedef struct Stack { 
    int top; 
    int capacity; 
    int* array; 
}STACK;
GRAPH* create_graph(ARISTA [], int);
void show_graph(GRAPH *);
void show_weights(GRAPH *);
void mark_nodes(GRAPH*, int,int);
void change_permanent(NODO *, int);
void show_weights_hijos(GRAPH *);
void path(GRAPH*,int,int,STACK*);
int isEmpty(STACK* ); 
void push(STACK*, int);  
int peek(STACK*);
STACK* crearStack(int);

char nodos_letras[CANT]={'A','B','C','D','E','F','G','H','I','J'};

int main()
{
    ARISTA datos[12]={
        {0,4,1},{0,2,2},{4,1,3},{2,4,5},{2,5,1},{1,7,8},{1,6,4},{5,6,1},{6,8,3},{7,3,1},{7,9,10}
        //{0,1,100},{0,2,30},{1,2,20},{2,3,10},{3,1,15},{2,4,60},{3,4,50}
    };
    STACK* stack = crearStack(CANT);
    int n=0,inicio=0,end=5,indice=0,cont=0;
    n=sizeof(datos)/sizeof(datos[0]);
    GRAPH *grafo=create_graph(datos,n-1);
    grafo->peso[inicio]=0;
    mark_nodes(grafo,inicio,0);
    printf("\n");
    //show_weights(grafo);
    //show_weights_hijos(grafo);
    //show_graph(grafo);
    push(stack,end);
    path(grafo,inicio,end,stack);
    //push(stack,inicio);
    printf("\nCamino mas corto de peso %d: ",grafo->peso[end]);
    while(isEmpty(stack)!=-1){
        indice=peek(stack);
        if(cont==0)
        printf(" %c(%d) ", nodos_letras[indice],indice+1);
        else
        printf(" -> %c(%d) ", nodos_letras[indice],indice+1);
        cont=1;
    }
    return 0;
}
STACK* crearStack(int capacity) 
{ 
    STACK* stack = (STACK*)malloc(sizeof(STACK)); 
    stack->capacity = capacity; 
    stack->top = -1; 
    stack->array = (int*)malloc(stack->capacity * sizeof(int)); 
    return stack; 
}
GRAPH* create_graph(ARISTA datos[], int n)
{
    int a=0,peso=0;
    int padre=0, hijo=0;
    GRAPH *grafo=(GRAPH*)malloc(sizeof(GRAPH));
    for(a=0;a<CANT;a++){
        grafo->nodo_actual[a]=a;
        grafo->peso[a]=INFINITE;
        grafo->head[a] =NULL;
        grafo->etiqueta[a]=NULL;
    }
    for(a=0;a<n;a++){
        padre=datos[a].padre;
        hijo=datos[a].hijo;
        peso=datos[a].peso;
        
        NODO *nuevo= (NODO*)malloc(sizeof(NODO));
        NODO *new=(NODO *)malloc(sizeof(NODO));
        nuevo->node_hijo=hijo;
        new->node_hijo=padre;
        nuevo->arista=peso;
        new->arista=peso;
        nuevo->next=grafo->head[padre];
        new->next=grafo->etiqueta[hijo];
        grafo->head[padre]=nuevo;
        grafo->etiqueta[hijo]=new;
    }
    return grafo;
}

void show_graph(GRAPH *grafo)
{
    int a;
    printf("\n");
	for (a = 0; a < CANT; a++)
	{
		NODO* ptr = grafo->head[a];
        while (ptr)
		{
			int k=grafo->nodo_actual[a];
            printf("Padre (%d)%c -> (%d)%c aris(%d)   ", k,nodos_letras[k],ptr->node_hijo,nodos_letras[ptr->node_hijo],ptr->arista);
			ptr = ptr->next;
		}
		printf("\n");
	}
}
void show_weights(GRAPH *grafo){
    int a;
	for (a = 0; a < CANT; a++)
	{
        printf("\nPeso del nodo %d:  %d", grafo->nodo_actual[a]+1,grafo->peso[a]);
	}
}
void show_weights_hijos(GRAPH *grafo){
    int a;
    printf("\n");
	for (a = 0; a < CANT; a++)
	{
		NODO* ptr = grafo->etiqueta[a];
        while (ptr)
		{
            printf("Hijo %d PADRE %d (%d)   ", a,ptr->node_hijo,ptr->arista);
			ptr = ptr->next;
		}
		printf("\n");
	}
}
void mark_nodes(GRAPH *grafo,int source,int j){
    int nodo_mandar=source;
    NODO* ptr = grafo->head[nodo_mandar];
    int permanente=0,min=0,i=0,newSource=0;
    permanente=grafo->peso[nodo_mandar];
    while (ptr)
    {
        if(grafo->peso[ptr->node_hijo]>ptr->arista+permanente || grafo->peso[ptr->node_hijo]==INFINITE){
            grafo->peso[ptr->node_hijo]=ptr->arista+permanente;
        }
        if(i==0){
            min=grafo->peso[ptr->node_hijo];
            newSource=ptr->node_hijo;
        }
        else {
            if(min>grafo->peso[ptr->node_hijo]){
                min=grafo->peso[ptr->node_hijo];
                newSource=ptr->node_hijo;
            }
        }
        if(grafo->head[ptr->node_hijo]!=NULL && j<CANT){
            mark_nodes(grafo,ptr->node_hijo,++j);
        }
        ptr = ptr->next;
        
    }
}
void path(GRAPH*grafo,int source,int end,STACK *stack){
    int a=end,peso=0;
    if(a==source){
        return;
    }
	NODO* ptr = grafo->etiqueta[a];
    peso=grafo->peso[end];
    while (ptr)
    {
        if(peso-ptr->arista==grafo->peso[ptr->node_hijo]){
            push(stack,ptr->node_hijo);
            return path(grafo,source,ptr->node_hijo,stack);
        }
		ptr = ptr->next;
	}
}
int isEmpty(STACK* stack) 
{ 
    if(stack->top==-1)
    return -1;
} 
void push(STACK* stack, int item) 
{  
    stack->array[++stack->top] = item; 
} 
int peek(STACK* stack) 
{ 
   if (isEmpty(stack)==-1) 
        return -1; 
    return stack->array[stack->top--]; 
} 