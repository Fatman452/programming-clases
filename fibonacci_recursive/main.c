#include <stdio.h>
#include <stdlib.h>
#define ELEMENTS 20
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int fibonacci_serie[ELEMENTS];
int fibonacci();

int indx = 0;

int main(int argc, char *argv[]) {
	
	fibonacci();
	
	return 0;
}

int fibonacci(){
	
	if(indx==0){
		fibonacci_serie[0] = 0;
		printf("%d, ",fibonacci_serie[0]);
		fibonacci_serie[1] = 1;
		printf("%d, ",fibonacci_serie[1]);
		indx=2;
		return fibonacci();
	}
	else{
		if(indx <= ELEMENTS){
			fibonacci_serie[indx] = fibonacci_serie[indx-2]+fibonacci_serie[indx-1];
			printf("%d, ",fibonacci_serie[indx]);
			++indx;
			return fibonacci();
		}
		else return 0;
		
	}
}
