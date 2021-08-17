#include <stdio.h>

int main(int argc, char *argv[]){
	int numbers[4] = {0};
	char name[5] = {'a'};
	
	printf("numbers: %d %d %d %d \n",
			numbers[0], numbers[1],
			numbers[2], numbers[3]);
	
	printf("name: %c %c %c %c %c\n",
			name[0], name[1],
			name[2], name[3], name[4]);
	
	numbers[0] = 1;
	numbers[1] = 9;
	numbers[2] = 9;
	numbers[3] = 8;
	
	name[0] = 'R';
	name[1] = 'o';
	name[2] = 'm';
	name[3] = 'a';
	name[4] = '\0';
	
	printf("numbers: %d %d %d %d \n",
			numbers[0], numbers[1],
			numbers[2], numbers[3]);
	
	printf("name: %c %c %c %c %c\n",
			name[0], name[1],
			name[2], name[3], name[4]);
			
	return 0;
}
