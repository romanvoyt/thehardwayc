#include <stdio.h>

int main(int argc, char *argv[])
{
	int ages[] = {23, 43, 12, 80, 2};
	char *names[] = {
	"Alan", "Frank",
	"Mary", "John", "Lisa"
	};
	
	int count = sizeof(ages)/ sizeof(int);
	int i = 0;
	
	//1st way using indexing
	for(i = 0; i < count; i++){
		printf("%s has %d years allive. \n", names[i], ages[i]);
	}
	
	printf("... \n");
	
	// pointers to the start of the arrays
	int *cur_age = ages;
	char **cur_name = names;
	
	//2nd way using pointers
	for(i = 0; i < count; i++){
		printf("%s has %d years allive. \n",
		 *(cur_name+i), *(cur_age+i));
	}
	
	printf("... \n");
	
	//3rd way, pointer are just arrays
	for(i = 0; i < count; i++){
		printf("%s has %d years allive. \n", cur_name[i], cur_age[i]);
	}
	
	printf("... \n");
	
	//4th way with pointers in a stupid complex way
	for(cur_name = names, cur_age = ages; (cur_age - ages) < count; cur_name++, cur_age++){
		printf("%s has %d years allive. \n", *cur_name, *cur_age);
	}
	
	return 0;	
}


