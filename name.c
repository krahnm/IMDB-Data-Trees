#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "binary.h"
#include "common.h"
#include "name.h"


struct name_basics **get_name(char *path){
	char *location = malloc(strlen(path) + strlen("/name.basics.tsv") + 1);
	char *buffer = malloc(256);
	char *string1 = malloc(256);
	char *string2 = malloc(256);
	char * nConst = '\0';
	char *name = '\0';
	int lines = 0;
	int i=0;
	FILE *fp;
	
	strcpy(location, path);
	strcat(location, "/name.basics.tsv");
	
	
	fp = fopen(location, "r");
	while (i<=5 /*!feof(fp)*/){
		fgets(buffer, 256, fp);
		/*if(strcmp(buffer,"NULL") != 0){
			printf("\n BUFFER IS MESSED \n");
		}*/
		get_column(buffer, string1, string2, 1);
		printf("Buffer	%s\n", buffer);
		printf("Contents:	%s\t%s\n", string1, string2);
		if(strstr(string2, "actor")!=NULL){
			lines++;
			 
		}
		else if(strstr(string2, "actress")!=NULL){
			lines++;
		}
		i++;
	}
	
	printf("\n Lines: %d \n",lines);
	
	lines = 5; /*TODO	DELETE AFTER TESTING!!!*/
	struct name_basics **nameArray = malloc(sizeof(struct name_basics)*lines);
	fseek(fp, 0, SEEK_SET);
	i=0;
	int k = 0;
	while (i<=5 /*!feof(fp)*/){ 
		
		fgets(buffer, 256, fp);
		get_column(buffer, string1, string2, 1);
		printf("Contents:	%s\t%s\n", string1, string2);
		
		if(strstr(string2, "actor")!=NULL || strstr(string2, "actress")!=NULL){
			nConst = malloc(strlen(string1)+1);
			strcpy(nConst, string1);
			name = malloc(strlen(string2)+1);
			strcpy(name, string2);
			
			nameArray[i] = malloc(sizeof(struct name_basics));
			nameArray[i]->nconst = nConst;
			nameArray[i]->primaryName = name;
			i++;
			 
		}
		k++;
	}
	/*int j=0;
	for(j=0; j<=5; j++){
		printf("nConst:	%s \n", nameArray[j]->nconst);
	}
	
	for(j=0; j<=lines; j++){
		free(nameArray[j]->nconst);
		free(nameArray[j]->primaryName);
		free(nameArray[j]);
	}
	free(nameArray);*/
	
	
	fclose(fp);
	free(location);
	free(buffer);
	free(string1);
	free(string2);
	
	
	return nameArray;
}



