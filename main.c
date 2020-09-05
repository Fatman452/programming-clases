#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>

#define MAXNOMBRE 15
#define MAXAPEL   20
#define HASH_SIZE 10
#define DELETED 

typedef struct people
{
	char name[MAXNOMBRE];
	char apellido[MAXAPEL];
	int edad;
}PERSON;
int hash_function(char *);
void initialize_table();
void print_table();
int insert_hashtable(PERSON *);
PERSON *search_hashtable(char *);
PERSON *delete_hashtable(char *);

PERSON *hash_table[HASH_SIZE];
int main()
{
	initialize_table();
	print_table();
	PERSON diana={.name="Diana",.apellido="Monegro",.edad=19};
	PERSON angelina={.name="Angelina",.apellido="Peralta",.edad=18};
	PERSON marvin={.name="Marvin",.apellido="Beltre",.edad=17};
	insert_hashtable(&diana);
	insert_hashtable(&angelina);
	insert_hashtable(&marvin);
	print_table();
	if(search_hashtable("hola")==0)
		printf("\nNot found");
	if(search_hashtable("Diana")!=0)
		printf("\nFound");
	delete_hashtable("Angelina");
	print_table();
	return 0;
}
//devuelve puntero de la persona si esta, y si no, NULL
PERSON *search_hashtable(char *name)
{
	int index=hash_function(name);
	int a,position=0;
	for(a=0;a<HASH_SIZE;a++){
		position=(a+index) % HASH_SIZE;
		if(hash_table[position]!=NULL && strcmp(hash_table[position]->name,name)==0){
			return hash_table[position];
		}
	}
	return 0;
	
}
PERSON *delete_hashtable(char *name)
{
	int index=hash_function(name);
	int a,position=0;
	for(a=0;a<HASH_SIZE;a++){
		position=(a+index)%HASH_SIZE;
		if(hash_table[position]!=NULL && strcmp(hash_table[position]->name,name)==0){
			PERSON *aux=hash_table[position];
			hash_table[position]=NULL;
			return aux;
		}
	}
	return 0;
	
}
void print_table()
{
	int i=0;
	for(i=0;i<HASH_SIZE;i++){
		if(hash_table[i]==NULL)
			printf("\n%d   ---", i);
		else
			printf("\n%d   %s", i, hash_table[i]->name);
	}
}
int insert_hashtable(PERSON *value)
{
	int position=0;
	if(value==NULL)
		return 0;
	int index=hash_function(value->name);
	for(int i=0;i<HASH_SIZE;i++){
		position=(i+index)%HASH_SIZE;
		if(hash_table[position]==NULL){
			hash_table[position]=value;
			return 1;
		}
	}
	return 0;
	
}
void initialize_table()
{
	int i=0;
	for(i=0;i<HASH_SIZE;i++){ 	//se inicializa la tabla en 0, si tiene una posicion sin usar es NULL
		hash_table[i]=NULL;
	}
}
int hash_function(char *name)
{
	int length=0, hash_value=0;
	length=strlen(name);
	for(int i=0;i<length;i++){
		hash_value+=(name[i]*name[i])%HASH_SIZE;
	}
	return hash_value;
}