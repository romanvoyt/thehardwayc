#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

void die(const char *message)
{
	if(errno){
		perror(message);
	}else{
		printf("ErrorL %s \n", message);
	}
	
	exit(1);
}

typedef int (*compare_cb)(int a, int b);
typedef int	*(*buble_sort)(int *numbers, int count, compare_cb  cmp);
typedef void (*q_sort)(int *numbers, int firstElem, int lastElem);

/* Buble sort function */

int *b_sort(int *numbers, int count, compare_cb cmp)
{
	int temp = 0;
	int i = 0;
	int j = 0;
	int *target = malloc(count * sizeof(int));
	
	if(!target) die("Memory error");
	
	memcpy(target, numbers, count * sizeof(int));
	
	for(i = 0; i < count; i++){
		for(j = 0; j < count - 1; j++){
			if(cmp(target[j], target[j+1]) > 0){
				temp = target[j+1];
				target[j+1] = target[j];
				target[j] = temp;
			}
		}
	}
	
	return target;
}

int sorted_order(int a, int b){
	return a - b;
}

int reverse_order(int a, int b){
	return b - a;
}

int strange_order(int a, int b){
	if(a == 0 || b == 0){
		return 0;
	} else {
		return a%b;
	}
}

/* Quick sort */

void swap(int *x, int *y){
	int temp = *x;
	*x = *y;
	*y = temp;
}

int partition(int *numbers, int firstElem, int lastElem){
	int pivot = numbers[lastElem];
	int i = (firstElem - 1);
	
	for(int j = firstElem; j <= lastElem - 1; j++){
		if(numbers[j] <= pivot){
			i++;
			swap(&numbers[i], &numbers[j]);
		}
	}
	swap(&numbers[i+1], &numbers[lastElem]);
	return (i + 1);
}

void quick_sort(int *numbers, int firstElem, int lastElem){
	
	if(firstElem < lastElem){
		int p = partition(numbers, firstElem, lastElem);
		quick_sort(numbers, firstElem, p-1);
		quick_sort(numbers, p+1, lastElem);
	}
}


void print_array(int *numbers, int size){
	for(int i = 0; i < size; i++){
		printf("%d \n", numbers[i]);
	}
}

/* Test functions */

void test_buble_sorting(int *numbers, int count, q_sort alg1, buble_sort alg2, compare_cb cmp){
	int i = 0;
	int *sorted = b_sort(numbers, count, cmp);
	
	if(!sorted) die("Failed to sort as requested.");
	
	for(i = 0; i < count; i++){
		printf("%d ", sorted[i]);
	}
	printf("\n");
	
	free(sorted);
}

void test_quick_sorting(int *numbers, int count){
	
	quick_sort(numbers, 0, count-1);
	printf("Sorted array: \n");
	print_array(numbers, count);
}

void test_sorting(int *numbers, int count, q_sort alg1, buble_sort alg2, compare_cb cmp){
	if(!numbers){
		die("Wrong sort type. Try q - for quick sort of b - for buble sort. \n");
	}
	
	if(alg1!=NULL){
		alg1(numbers, 0, count-1);
		printf("Sorted array: \n");
		print_array(numbers, count);
	}else{
		int i = 0;
		int *sorted = alg2(numbers, count, cmp);
	
		if(!sorted) die("Failed to sort as requested.");
	
		for(i = 0; i < count; i++){
			printf("%d ", sorted[i]);
		}
		printf("\n");
	
		free(sorted);
	}
}


int main(int argc, char *argv[]){
	if(argc < 2) die("Usage example : ex18 <b> 4 3 1 5 6");
	
	int count = argc - 1;
	int i = 0;
	char **inputs = argv + 1;
	
	int *numbers = malloc(count * sizeof(int));
	if(!numbers) die("Memory eror.");
	
	for(i=0; i < count; i++){
		numbers[i] = atoi(inputs[i]);
	}
	
	test_sorting(numbers, count, quick_sort, NULL, NULL);
	//test_sorting(numbers, count, NULL, b_sort, sorted_order);
	
	free(numbers);
	
	return 0;
}




















