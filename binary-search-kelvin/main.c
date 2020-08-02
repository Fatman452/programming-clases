#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void find_minor(int min_age);
void response (int index);

int ages[]={13, 15, 18, 25, 30, 60};
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
	
		if(ages[mid_limit]==min_age){
			int i=mid_limit-1;
			response(i);
		
			}
			if(i<0){
				printf("No hay ninos \n");
			}
			break;
		}
		else if(ages[mid_limit]>min_age){
			high_limit=mid_limit-1;
		}
		else{
			low_limit=mid_limit+1;
		}
	
		if(low_limit>high_limit){
			printf("No existe un registro con la edad que suministro \n");
		}
	}
	
}

void response (int index){
	
		for(i;i>=0;--i){
				if(i==5){
					printf("José es un nino \n");
				}
				else if(i==4){
					printf("María es una nina \n");
				}
				else if(i==3){
					printf("John es un nino \n");
				}
				else if(i==2){
					printf("Diana es una nina \n");
				}
				else if(i==1){
					printf("Kelvin es un nino \n");
				}
				else if(i==0){
					printf("Reynold es un nino \n");
				}
}
