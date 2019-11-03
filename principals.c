#include <stdio.h>
#include "binary.h"
#include "common.h"
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "binary.h"
#include "principals.h"


struct principalsInfo *get_titlePrinciples(char *path){
	struct principalsInfo *treeInfo;
	treeInfo = malloc(sizeof(struct principalsInfo));
	char *location = malloc(strlen(path) + strlen("/title.principals.tsv") + 1);
	char *buffer = malloc(256);
	char *string1 = malloc(256);
	char *string2 = malloc(256);
	char *string3 = malloc(256);
	char * nConst = '\0';
	char *name = '\0';
	char *tConst = '\0';
	int lines = 0;
	int i=0;
	FILE *fp;
	
	strcpy(location, path);
	strcat(location, "/title.principals.tsv");
	
	
	fp = fopen(location, "r");
	while (/*i<=700 */ !feof(fp)){
		fgets(buffer, 256, fp);
		/*if(strcmp(buffer,"NULL") != 0){
			printf("\n BUFFER IS MESSED \n");
		}*/
		get_column(buffer, string1, 3);
		/*printf("Buffer	%s\n", buffer);
		printf("Contents:	[%s]\n", string1);*/
		if(strstr(string1, "actor")!=NULL){
			lines++;
			 
		}
		else if(strstr(string1, "actress")!=NULL){
			lines++;
		}
		i++;
	}
	
	printf("\n Lines: %d \n",lines);
	
	/*lines = 5; TODO	DELETE AFTER TESTING!!!*/
	struct title_principals **nameArray = malloc(sizeof(struct title_principals)*lines);
	treeInfo->numItems = lines;
	treeInfo->array = nameArray;
	treeInfo->tConstRoot = 0;
	treeInfo->nConstRoot = 0;
	
	fseek(fp, 0, SEEK_SET);
	i=0;
	int k = 0;
	while (/*k<=700*/ !feof(fp)){ 
		
		fgets(buffer, 256, fp);
		get_column(buffer, string1, 3);
		
		if(strstr(string1, "actor")!=NULL || strstr(string1, "actress")!=NULL){
			get_column(buffer, string1, 2);
			nConst = malloc(strlen(string1)+1);
			strcpy(nConst, string1);
			
			get_column(buffer, string1, 0);
			tConst = malloc(strlen(string1)+1);
			strcpy(tConst, string1);
			
			get_column(buffer, string1, 5);
			name = malloc(strlen(string1)+1);
			strcpy(name, string1);
			
			nameArray[i] = malloc(sizeof(struct title_principals));
			nameArray[i]->nconst = nConst;
			nameArray[i]->tconst = tConst;
			nameArray[i]->characters = name;
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
	free(string3);
	
	
	return treeInfo;
}



