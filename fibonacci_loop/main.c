#include <stdio.h>
#include <stdlib.h>
#define ELEMENTS 20
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int fibonacci_serie[ELEMENTS];
void fibonacci();

int main(int argc, char *argv[]) {
	
	fibonacci();
	
	return 0;
}

void fibonacci(){
	int index = 2;	
	fibonacci_serie[0] = 0;
	fibonacci_serie[1] = 1;
	for(index;index <= ELEMENTS;++index){
		fibonacci_serie[index] = fibonacci_serie[index-2]+fibonacci_serie[index-1];
	}

	index=0;

	for(index;index <= ELEMENTS;++index){
		printf("%d, ",fibonacci_serie[index]);
	}
}
