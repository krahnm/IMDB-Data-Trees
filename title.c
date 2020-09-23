#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "binary.h"
#include "common.h"
#include "title.h"

/*Handles the array of movie title information*/

struct titleInfo *get_title(char *path)
{
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
	
	/*Counts for only films labled Movie and creates the struct for the entry*/
	fp = fopen(location, "r");
	while (!feof(fp))
	{
		fgets(buffer, 256, fp);
		get_column(buffer, string1, 1);
		get_column(buffer, string2, 4);
		if(strstr(string1, "movie")!=NULL && strstr(string2, "0")!=NULL){
			lines++;
		}
		i++;
	}
	
	nameArray = malloc(sizeof(struct title_basics)*lines);
	treeInfo->numItems = lines;
	treeInfo->value = nameArray;
	treeInfo->nindex = 0;
	treeInfo->tindex = 0;
	fseek(fp, 0, SEEK_SET);
	i=0;
	k = 0;
	while (!feof(fp))/*Copies the info from the file into the struct*/
	{ 
		fgets(buffer, 256, fp);
		get_column(buffer, string1, 1);
		get_column(buffer, string2, 4);
	
		if(strstr(string1, "movie")!=NULL && strstr(string2, "0")!=NULL)
		{
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
	
	fclose(fp);
	free(location);
	free(buffer);
	free(string1);
	free(string2);
	
	return treeInfo;
}

/*builds the title name tree*/
 void build_tindex(struct titleInfo *tInfo)
 {
	 int j = 0;
	
	for(j =0; j < tInfo->numItems; j++)
	{
		 add_tnode(&tInfo->tindex, tInfo->value[j]->primaryTitle, tInfo->value[j]);
	}
	
 }
 
/*Returns the title node*/ 
struct title_basics *find_primary_title(struct titleInfo *tInfo, char * toFind)
{
	return find_tnode(tInfo->tindex, toFind);
}

/*Builds the tConst tree*/
 void build_tconstindex(struct titleInfo *tInfo)
 {
	int j = 0;
	for(j =0; j < tInfo->numItems; j++)
	{
		 add_tnode(&tInfo->nindex, reverse(tInfo->value[j]->tconst), tInfo->value[j]);
	}
	
 }
 
/*finds the matching tConst node*/
struct title_basics *find_tConst(struct titleInfo *tInfo, char * toFind)
{
	return find_tnode(tInfo->nindex, reverse(toFind));
}
 


