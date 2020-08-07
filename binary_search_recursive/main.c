#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int binary_search_recursive(int searched_number);
int	recursive_search(int l_limit, int h_limit);

int sorted_numbers[20] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
int number = 56;

int main(int argc, char *argv[]) {
		
	if (binary_search_recursive(number)){	
		printf("\n\n encontrado!!! \n");
	}
	else{
		printf("\n\nNo existe un registro con ese numero \n");
	}
	
	return 0;
}

int binary_search_recursive(int searched_number){
	size_t arr_length = sizeof(sorted_numbers) / sizeof(sorted_numbers[0]);
	int low_limit = 0;
	int high_limit = arr_length-1;
	int mid_limit = 0;
	
	return recursive_search(low_limit, high_limit);
}

int	recursive_search(int l_limit, int h_limit){
	
	int limit= (l_limit+h_limit)/2;
	if(l_limit>h_limit){
			return 0;
	}
	if(sorted_numbers[limit]==number){
		return 1;
	}
	else if(sorted_numbers[limit]>number){
		h_limit=limit-1;
		return recursive_search(l_limit, h_limit);
	}
	else{
		l_limit=limit+1;
		return recursive_search(l_limit, h_limit);
	}
}
