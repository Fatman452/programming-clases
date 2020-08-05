#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int integers_array[4];
void sums_arrays(int *array);

int main(int argc, char *argv[]) {
	int i;
	for(i=0;i<4;++i){
		printf("Digite el valor #%d:   ", i);
		scanf("%d", &integers_array[i]);	
		
	}
	
	printf("\n\n");
	sums_arrays(integers_array);

	for(i=0;i<4;++i){
		printf("resultado posicion #%d:   %d\n", i,integers_array[i]);
	}
	
	return 0;
}

void sums_arrays(int *array){
	int b;
	for(b=1;b<4;++b){
		array[b]=array[b]+array[b-1];
	}
}
