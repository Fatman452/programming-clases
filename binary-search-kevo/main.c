#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void binary_search(int number);

int numbers[]={1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
int number =0;

int main(int argc, char *argv[]) {
	
	printf("Digite el numero que desea encontrar: ");
	scanf("%d", &number);
	
	binary_search(number);
	
	return 0;
}

void binary_search(int num){
	size_t arr_length = sizeof(numbers) / sizeof(numbers[0]);
	int low_limit=0;
	int high_limit=arr_length-1;
	int mid_limit= 0;
		
	while(low_limit<=high_limit){
		mid_limit= (low_limit+high_limit)/2;
	
		if(numbers[mid_limit]==num){
			printf("encontrado!!! \n");
			break;
		}
		else if(numbers[mid_limit]>num){
			high_limit=mid_limit-1;
		}
		else{
			low_limit=mid_limit+1;
		}
	
		if(low_limit>high_limit){
			printf("No existe un registro con ese numero \n");
		}
	}
	
}
