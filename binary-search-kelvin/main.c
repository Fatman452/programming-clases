#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void find_minor(int min_age);
void response (int age_allowed);

int ages[6]={13, 15, 18, 25, 30, 60};
char names[6][8]={"Reynold", "Kelvin", "Diana", "Maria", "John", "Jose"};
int age_test =0;

int main(int argc, char *argv[]) {
	
	printf("Digite la edad minima para entar al club: ");
	scanf("%d", &age_test);
	
	find_minor(age_test);
	
	return 0;
}

void find_minor(int min_age){
	size_t arr_length = sizeof(ages) / sizeof(ages[0]);
	int low_limit=0;
	int high_limit=arr_length-1;
	int mid_limit= 0;
		
	while(low_limit<=high_limit){
		mid_limit= (low_limit+high_limit)/2;
	
		if(ages[mid_limit]<=min_age){
			response(min_age);
			return;
		}
		else if(ages[mid_limit]>min_age){
			high_limit=mid_limit-1;
		}
	}
	
}

void response (int age_allowed){
	int index_names=0;
	if(ages[index_names]==age_allowed){
		printf("No hay menor de edad \n");
	}
	else{
		while(ages[index_names]<age_allowed){
			printf("%s es un menor de edad \n", &names[index_names]);
			++index_names;
		}		
	}
}
