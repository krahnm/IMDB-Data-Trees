#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "binary.h"
#include "common.h"
#include "title.h"


struct titleInfo *get_title(char *path){
	struct titleInfo *treeInfo;
	struct title_basics **nameArray = NULL;
	
	char *location = malloc(strlen(path) + strlen("/title.basics.tsv") + 1);
	char *buffer = malloc(256);
	char *string1 = malloc(256);
	char *string2 = malloc(256);
	char * tConst = '\0';
	char *name = '\0';
	int lines = 0;
	int i=0;
	int k = 0;
	FILE *fp;
	
	treeInfo = malloc(sizeof(struct titleInfo));
	strcpy(location, path);
	strcat(location, "/title.basics.tsv");
	
	
	fp = fopen(location, "r");
	while (/*i<=700*/ !feof(fp)){
		fgets(buffer, 256, fp);
		/*if(strcmp(buffer,"NULL") != 0){
			printf("\n BUFFER IS MESSED \n");
		}*/
		get_column(buffer, string1, 1);
		get_column(buffer, string2, 4);
		/*printf("Buffer	%s\n", buffer);
		printf("Contents:	[%s]\n", string1);*/
		if(strstr(string1, "movie")!=NULL && strstr(string2, "0")!=NULL){
			lines++;
			/*printf("LINES %d \n",lines);
			 */
		}
		i++;
		
	}
	
	printf("\n Lines: %d \n",lines);
	
	nameArray = malloc(sizeof(struct title_basics)*lines);
	treeInfo->numItems = lines;
	treeInfo->value = nameArray;
	treeInfo->nindex = 0;
	treeInfo->tindex = 0;
	fseek(fp, 0, SEEK_SET);
	i=0;
	k = 0;
	while (/*k<=700*/ !feof(fp)){ 
		
		fgets(buffer, 256, fp);
		get_column(buffer, string1, 1);
		get_column(buffer, string2, 4);
		/*printf("Contents:	[%s]\n", string2);
		*/
		if(strstr(string1, "movie")!=NULL && strstr(string2, "0")!=NULL){
			get_column(buffer, string1, 0);
			tConst = malloc(strlen(string1)+1);
			strcpy(tConst, string1);
			
			get_column(buffer, string1, 2);
			name = malloc(strlen(string1)+1);
			strcpy(name, string1);
			
			
			nameArray[i] = malloc(sizeof(struct title_basics));
			nameArray[i]->tconst = tConst;
			nameArray[i]->primaryTitle = name;
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
	
	
	return treeInfo;
}



 void build_tindex(struct titleInfo *tInfo){
	 int j = 0;
	
	for(j =0; j < tInfo->numItems; j++){
		 add_tnode(&tInfo->tindex, tInfo->value[j]->primaryTitle, tInfo->value[j]);
	 }
	
 }
 
 
struct title_basics *find_primary_title(struct titleInfo *tInfo, char * toFind){
	return find_tnode(tInfo->tindex, toFind);
}

 void build_tconstindex(struct titleInfo *tInfo){
	 int j = 0;
	for(j =0; j < tInfo->numItems; j++){
		 add_tnode(&tInfo->nindex, reverse(tInfo->value[j]->tconst), tInfo->value[j]);
	 }
	
 }
 
 
struct title_basics *find_tConst(struct titleInfo *tInfo, char * toFind){
	return find_tnode(tInfo->nindex, reverse(toFind));
}
 


