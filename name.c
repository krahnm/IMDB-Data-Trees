#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "binary.h"
#include "common.h"
#include "name.h"


struct nameInfo *get_name(char *path){
	struct nameInfo *treeInfo = NULL;
	struct name_basics **nameArray = NULL;
	char *location = NULL;
	char *buffer = malloc(256);
	char *string = malloc(256);
	char * nConst = '\0';
	char *name = '\0';
	int lines = 0;
	int i=0;
	int k = 0;
	FILE *fp;
	
	treeInfo = malloc(sizeof(struct nameInfo));
	location = malloc(strlen(path) + strlen("/name.basics.tsv") + 1);
	
	strcpy(location, path);
	strcat(location, "/name.basics.tsv");
	
	
	fp = fopen(location, "r");
	while (/*i<=5*/ !feof(fp)){
		fgets(buffer, 256, fp);
		/*if(strcmp(buffer,"NULL") != 0){
			printf("\n BUFFER IS MESSED \n");
		}*/
		get_column(buffer, string, 4);
		/*printf("Buffer	%s\n", buffer);
		printf("Contents:	[%s]\n", string);*/
		if(strstr(string, "actor")!=NULL){
			lines++;
			 
		}
		else if(strstr(string, "actress")!=NULL){
			lines++;
		}
		i++;
	}
	
	/*printf("\n Lines: %d \n",lines);
	*/
	
	nameArray = malloc(sizeof(struct name_basics)*lines);
	treeInfo->numItems = lines;
	treeInfo->value = nameArray;
	treeInfo->nindex = 0;
	treeInfo->tindex = 0;
	
	fseek(fp, 0, SEEK_SET);
	i=0;
	k = 0;
	while (/*k<=5*/ !feof(fp)){ 
		
		fgets(buffer, 256, fp);
		get_column(buffer, string, 4);
		/*printf("Contents:	[%s]\n", string);*/
		
		if(strstr(string, "actor")!=NULL || strstr(string, "actress")!=NULL){
			get_column(buffer, string, 0);
			nConst = malloc(strlen(string)+1);
			strcpy(nConst, string);
			
			get_column(buffer, string, 1);
			name = malloc(strlen(string)+1);
			strcpy(name, string);
			
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
	free(string);
	
	
	return treeInfo;
}

 void build_nindex(struct nameInfo *nInfo){
	 int j = 0;
	 for(j =0; j < nInfo->numItems; j++){
		 add_nnode(&nInfo->nindex, nInfo->value[j]->primaryName, nInfo->value[j]);
	 }
 }
 
 
struct name_basics *find_primary_name(struct nameInfo *nInfo, char * toFind){
	return find_nnode(nInfo->nindex, toFind);
}

void build_nconstindex(struct nameInfo *nInfo){
	 int j = 0;
	 for(j =0; j < nInfo->numItems; j++){
		 add_nnode(&nInfo->tindex, reverse(nInfo->value[j]->nconst), nInfo->value[j]);
	 }
 }
 
 
struct name_basics *find_nConst(struct nameInfo *nInfo, char * toFind){
	return find_nnode(nInfo->tindex, toFind);
}



