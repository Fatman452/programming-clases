#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void search_country(int surface);

unsigned long surface_areas[10]={10992, 27750, 109884, 130395, 283560, 357386, 756950, 1142000,  1285000, 1973000};
char countries[10][12]={"Jamaica", "Haiti", "Cuba", "Inglaterra", "Ecuador", "Alemania", "Chile", "Colombia",   "Peru", "Mexico"};
unsigned long area =1973000;

int main(int argc, char *argv[]) {
	
	search_country(area);
	
	return 0;
}

void search_country(int surface){
	size_t arr_length = sizeof(surface_areas) / sizeof(surface_areas[0]);
	int low_limit=0;
	int high_limit=arr_length-1;
	int mid_limit= 0;
		
	while(low_limit<=high_limit){
		mid_limit= (low_limit+high_limit)/2;
	
		if(surface_areas[mid_limit]==surface){
			printf("\n\n Area perteneciente a: %s \n\n", countries[mid_limit]);
			return;
		}
		else if(surface_areas[mid_limit]>surface){
			high_limit=mid_limit-1;
		}
		else{
			low_limit=mid_limit+1;
		}
	}
	printf("\n\n Area no encontrada \n\n");
	
}

