#include<stdio.h>

void input_array(int *array1, int *array2, int *num);
int check_intersection(int *array1, int *array2, int *intersection_array, int *num);
void print_intersection(int *intersection_array, int k);

int main() {

	int array1[80];
	int array2[80];
	int intersection_array[80];
	int check_index, num;

	input_array(array1, array2, &num);

	check_index = check_intersection(array1, array2, intersection_array, &num);

	print_intersection(intersection_array, check_index);

	return 0;
}

void input_array(int *array1, int *array2, int *num){

	int i, j;
	
	printf("몇 개의 숫자들을 입력 받으시겠습니까 : ");
	scanf("%d", num);
	printf("\n");

	for(j = 0 ; j < *num ; j++){

		printf("첫 번째 배열의 %d번 숫자 : ", j+1);
		scanf("%d", (array1 + j) );
	}
	printf("\n");

	for(j = 0 ; j < *num ; j++){

		printf("두 번째 배열의 %d번 숫자 : ", j+1);
		scanf("%d", (array2 + j) );
	}
	printf("\n");
	
}

int check_intersection(int *array1, int *array2, int *intersection_array, int *num){

	int i, j, k = 0, check;

	for(i = 0 ; i < *num ; i++){
		for(j = 0 ; j < *num ; j++){

			if( *(array1 + j) == *(array2 + i) ){

				for(check = 0 ; check <= k ; check++){

					if( *(intersection_array + check) == *(array1 + j) ) break;

					else if(check == k){

						*(intersection_array + k) = *(array1 + j);
						k++;
						break;
					}
					
				}
			}
		}

	}

	return k;
}

void print_intersection(int *intersection_array, int k){

	int i;

	printf("Intersection : ");
	for(i = 0 ; i < k ; i++) printf("%d ", *(intersection_array + i) );
	printf("\n");
}