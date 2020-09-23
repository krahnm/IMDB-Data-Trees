#include <stdio.h>
#include "binary.h"
#include "common.h"
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "binary.h"
#include "principals.h"
#include "name.h"
#include "title.h"

/*This file Handles the array that connects the names to the titles*/

struct principalsInfo *get_principals(char *path)
{
	struct principalsInfo *treeInfo;
	struct title_principals **nameArray = NULL;
	
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
	int k = 0;
	
	FILE *fp;
	treeInfo = malloc(sizeof(struct principalsInfo));
	strcpy(location, path);
	strcat(location, "/title.principals.tsv");
	
	/*Calculates number of entries needed and creates their structs*/
	fp = fopen(location, "r");
	while (!feof(fp))
	{
		fgets(buffer, 256, fp);
		get_column(buffer, string1, 3);
		if(strstr(string1, "actor")!=NULL)
		{
			lines++; 
		}
		else if(strstr(string1, "actress")!=NULL)
		{
			lines++;
		}
		i++;
	}
	
	nameArray = malloc(sizeof(struct title_principals)*lines);
	treeInfo->numItems = lines;
	treeInfo->value = nameArray;
	treeInfo->tindex = 0;
	treeInfo->nindex = 0;
	
	/*Reads in the actors nConst and tConst values to enter into the linking trees*/
	fseek(fp, 0, SEEK_SET);
	i=0;
	k = 0;
	while (!feof(fp))
	{ 
		fgets(buffer, 256, fp);
		get_column(buffer, string1, 3);
		
		if(strstr(string1, "actor")!=NULL || strstr(string1, "actress")!=NULL)
		{
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
	
	fclose(fp);
	free(location);
	free(buffer);
	free(string1);
	free(string2);
	free(string3);
	
	return treeInfo;
}

/*Creates the trees - the tConst*/
 void build_tindex_tp(struct principalsInfo *nInfo)
 {
	 int j = 0;
	 for(j =0; j < nInfo->numItems; j++)
	 {
		 add_ptnode(&nInfo->tindex, reverse(nInfo->value[j]->tconst), nInfo->value[j]);
	 }
 }
 
/*given the name info, finds the associated tConst*/
struct title_principals *find_tconst_tp(struct principalsInfo *nInfo, char * toFind)
{
	return find_pnode(nInfo->tindex, toFind);
}

/*Creates the trees - the tConst*/
void build_nindex_tp(struct principalsInfo *nInfo)
{
	 int j = 0;
	 for(j =0; j < nInfo->numItems; j++)
	 {
		 add_pnnode(&nInfo->nindex, nInfo->value[j]->nconst, nInfo->value[j]);
	 }
 }
 
/*returns the node with the matching nConst*/
struct title_principals *find_nconst_tp(struct principalsInfo *nInfo, char * toFind)
{
	return find_pnode(nInfo->nindex, toFind);
}




