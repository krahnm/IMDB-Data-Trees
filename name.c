#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "binary.h"
#include "common.h"
#include "name.h"


struct name_basics *get_name(char *path){
	char *location = malloc(strlen(path) + strlen("/name.basics.tsv") + 1);
	char *buffer = malloc(256);
	FILE *fp;
	
	strcpy(location, path);
	strcat(location, "/name.basics.tsv");
	
	
	printf(" We INN\n");
	fp = fopen(location, "r");
	while (!feof(fp)){
		fgets(buffer, 256, fp);
		if(strcmp(buffer,"NULL") != 0){
			printf("\n BUFFER IS MESSED \n");
		}
		
		printf("%s We INN\n", buffer);
	}
	
	fclose(fp);
	free(location);
	free(buffer);
	
	return NULL;
}
