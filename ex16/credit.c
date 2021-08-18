#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

typedef struct Person{
	char *name;
	int age;
	int height;
	int weight;
} Person;

struct Person Person_create(Person person, char *name, int age, int height, int weight){
	
	person.name = strdup(name);
	person.age = age;
	person.height = height;
	person.weight = weight;
	
	return person;
}

void Person_destroy(Person who){
	free(who.name);
	free(who);
}

void Person_print(Person who){
	printf("Name : %s \n", who.name);
	printf("Age : %d \n", who.age);
	printf("Height: %d \n", who.height);
	printf("Weight: %d \n", who.weight);
}

int main(int argc, char *argv[]){
	auto Person Roman;
	Person_print(Roman);
	printf("Roman loc in memory: %p", &Roman);
	Roman = Person_create(Roman, "Roman", 22, 177, 80);
	auto Person Amy;
	Amy = Person_create(Amy, "Amy", 20, 172, 60);
	
	printf("Roman is at memloc %p \n", &Roman);
	printf("Amy is at memloc %p \n", &Amy);
	
	Person_print(Roman);
	Person_print(Amy);
	
	return 0;
}
