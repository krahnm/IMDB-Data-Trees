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
	char *contents = malloc(256);
	int lines = 0;
	FILE *fp;
	
	strcpy(location, path);
	strcat(location, "/name.basics.tsv");
	
	
	fp = fopen(location, "r");
	while (!feof(fp)){
		fgets(buffer, 256, fp);
		/*if(strcmp(buffer,"NULL") != 0){
			printf("\n BUFFER IS MESSED \n");
		}*/
		get_column(buffer, contents, 4);
		/*printf("Buffer	%s\n", buffer);*/
		printf("Contents:	%s\n", contents);
		if(strstr(contents, "actor")!=NULL){
			printf("actor\n");
			lines++;
			 
		}
		else if(strstr(contents, "actress")!=NULL){
			printf("actress\n");
			lines++;
		}
	}
	
	printf("\n Lines: %d \n",lines);
	
	fclose(fp);
	free(location);
	free(buffer);
	free(contents);
	
	return NULL;
}



