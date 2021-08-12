#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	char buffer[100];
	puts("hello world.");
	
	fread(buffer, sizeof(char), 100, stdin);
	
	printf("String: %s \n", buffer);
	
	return 0;
}
