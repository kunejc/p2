#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_LINE 101*100 



int main(int argc, char** argv)
{
	FILE *vhodna = fopen(argv[1], "r");
	FILE *izhodna = fopen(argv[2], "w");
	char kljuc[100];
	strcpy(kljuc, argv[3]);

	int indexStarost = -1;
	int indexKljuc = -1;
	int i = 0;
	char buffer[MAX_LINE];

	fgets(buffer, MAX_LINE, vhodna);
	buffer[strcspn(buffer, "\n")] = 0;

	char *token = strtok(buffer, " ");
	while (token != NULL)
	{
		if (strcmp(token, "starost") == 0) indexStarost = i;
		if (strcmp(token, kljuc) == 0) indexKljuc = i;
		token = strtok(NULL, " ");		
		i++;
	}
	// printf("%d %d\n", indexStarost, indexKljuc);

	
	






	
	return 0;
}




