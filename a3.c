#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary.h"
#include "common.h"
#include "name.h"
#include "principals.h"
#include "title.h"
 
 
 void print_ntree( struct tree *root, struct titleInfo *tInfo, struct principalsInfo *pInfo, struct name_basics *name)
{
	struct title_basics *title;
	struct title_principals *tprincipals;
	printf("SHOULD PRINT ITTTT\n");
	/*struct title_principals *temp = (struct title_principals *)(root->value);
	char *buff = (temp->nconst);
	printf("BUFF: %s \n", buff);
	printf("nconst: %s \n", nConst);
	int compare = strcmp(buff, nConst);
	struct title_basics *title = find_primary_title(tInfo, root->key);
	  */
  if (root == NULL)
  {
	  printf("ROOT IS NULL\n");
	  return;
  }
  else{
	  
	  tprincipals = root->value;
	  
	  if((strcmp(tprincipals->nconst, name->nconst) == 0) && (find_nconst_tp(pInfo, name->nconst) != NULL)){
	  printf("TCONST: %s/n", tprincipals->tconst);
		  title = find_primary_title(tInfo, tprincipals->tconst);
		 if(title != NULL){
		  printf("ENTRY IS GOOD! \n");
		printf( "%s\n", title->primaryTitle );
		printf( "%s\n", tprincipals->characters );
		}
		
		title = find_tConst(tInfo, tprincipals->tconst);
		 if(title != NULL){
		  printf("ENTRY IS GOOD! \n");
		printf( "%s : %s\n", title->primaryTitle, tprincipals->characters);
		}
	}
		print_ntree( root->children[0], tInfo, pInfo, name);

		print_ntree( root->children[1], tInfo, pInfo, name);
	}
  }

 void print_ttree( struct tree *root, struct nameInfo *nInfo, struct principalsInfo *pInfo, struct title_basics *title)
{
	struct name_basics *name;
	struct title_principals *tprincipals;
	printf("SHOULD PRINT ITTTT\n");
	/*struct title_principals *temp = (struct title_principals *)(root->value);
	char *buff = (temp->nconst);
	printf("BUFF: %s \n", buff);
	printf("nconst: %s \n", nConst);
	int compare = strcmp(buff, nConst);
	struct title_basics *title = find_primary_title(tInfo, root->key);
	  */
  if (root == NULL)
  {
	  printf("ROOT IS NULL\n");
	  return;
  }
  else{
	  
	  tprincipals = root->value;
	  
	  if((strcmp(tprincipals->tconst, title->tconst) == 0) && (find_tconst_tp(pInfo, title->tconst) != NULL)){
	  printf("NCONST: %s/n", tprincipals->nconst);
		  name = find_primary_name(nInfo, tprincipals->nconst);
		 if(title != NULL){
		  printf("ENTRY IS GOOD! \n");
		printf( "%s\n", name->primaryName );
		printf( "%s\n", tprincipals->characters );
		}
		
		name = find_nConst(nInfo, tprincipals->nconst);
		 if(name != NULL){
		  printf("ENTRY IS GOOD! \n");
		printf( "%s : %s\n", name->primaryName, tprincipals->characters);
		}
	}
		print_ttree( root->children[0], nInfo, pInfo, title);

		print_ttree( root->children[1], nInfo, pInfo, title);
	}
  }
 
 
 
/*TESTINGGGGGGGG*/
int main(int argc, char *argv[]){
	char* ptr;
	char* string = malloc(256);
	char* string1 = malloc(256);
	int colNum = 1;
	struct title_basics *title = NULL;
	struct name_basics *name = NULL;
	struct title_principals *principals = NULL;
	
	struct titleInfo *titleBasics = NULL;
	struct nameInfo *nameBasics = NULL;
	struct principalsInfo *titlePrincipals = NULL;
	int i =0;
	
	
	if(argc<2){
		fprintf( stderr, "Usage:  %s directory\n", argv[0] );
		return -1;
	}
	/*ptrName = get_name("/home/courses/cis2520");*/
	/*pInfo = get_titlePrinciples("/home/courses/cis2520");
	ptrPrincipals = get_titlePrinciples("/home/courses/cis2520"); 
	*/
	
	
	
	string[0] = '\0';
	printf("> ");
	fgets(string, 256, stdin);
	
	
	strcpy(string1, string);
	
	ptr = string1; /*moves to specific column*/
		while((*ptr)!='\0' && i!=colNum && ((*ptr)+1)!='\n'){
		if((*ptr)==' '){
			i++;
		}
		
		(ptr)++;
	}
	ptr[strlen(ptr)-1] = '\0';
	
	
	
	
	titleBasics = get_title( argv[1] );
	build_tconstindex( titleBasics );
	build_tindex( titleBasics );
	
	
	/*print_tree((struct tree *)titleBasics->tindex);
	print_tree((struct tree *)titleBasics->nindex);
	*/
	
	nameBasics = get_name( argv[1] );
	build_nconstindex( nameBasics );
	build_nindex( nameBasics );
	
	/*print_tree((struct tree *)nameBasics->nindex);
	print_tree((struct tree *)nameBasics->nindex);
	*/
	
	titlePrincipals = get_principals(argv[1] );
	build_tindex_tp( titlePrincipals );
	build_nindex_tp( titlePrincipals );
	
	/*print_tree((struct tree *)nameBasics->nindex);
	print_tree((struct tree *)nameBasics->nindex);
	*/
if(strstr(string, "name")!=NULL){;
		
		name = find_primary_name( nameBasics, ptr );
		if(name != NULL){
			printf( "%p\n", (void *)name );
			printf( "%s\n", name->nconst);
			printf( "%s\n", name->primaryName );
	

			principals = find_nconst_tp( titlePrincipals, name->nconst );
			if(principals != NULL){
				
				struct tree *groot = find_topNode(&(titlePrincipals->nindex), name->nconst);
				
				printf( "%p\n", (void *)principals );
				printf( "%s\n", principals->nconst);
				printf( "%s\n", principals->tconst );
				printf( "%s\n", principals->characters );
				
				printf("PRINT TREES \n");
				print_ntree(groot, titleBasics, titlePrincipals, name);
					printf("AFTER TREES \n");
					
				printf("titleB: %p\n", (void *)titleBasics);	
				printf("tConst: %s \n", principals->tconst);
				title = find_tConst( titleBasics, principals->tconst );
					
				if(title != NULL){
					printf( "%p\n", (void *)title );
					printf( "%s\n", title->tconst );
					printf( "%s\n", title->primaryTitle );
					/*printf("%s : %s\n", title->primaryTitle, );*/
				}
				
			/*	title = find_primary_title( titleBasics, principals->tconst );
				if(title != NULL){
					printf( "%p\n", (void *)title );
					printf( "%s\n", title->tconst );
					printf( "%s\n", title->primaryTitle );
				}*/
			}
		}
	
	}
	else if(strstr(string, "title")!=NULL){
			
		title = find_primary_title( titleBasics, ptr );
		if(title != NULL){
			printf( "%p\n", (void *)name );
			printf( "%s\n", title->tconst);
			printf( "%s\n", title->primaryTitle );
	

			principals = find_tconst_tp( titlePrincipals, reverse(title->tconst) );
			if(principals != NULL){
				
				struct tree *groot = find_topNode(&(titlePrincipals->tindex), reverse(title->tconst));
				
				printf( "%p\n", (void *)principals );
				printf( "%s\n", principals->nconst);
				printf( "%s\n", principals->tconst );
				printf( "%s\n", principals->characters );
				
				printf("PRINT TREES \n");
				print_ttree(groot, nameBasics, titlePrincipals, title);
					printf("AFTER TREES \n");
					
				printf("titleB: %p\n", (void *)nameBasics);	
				printf("tConst: %s \n", principals->nconst);
				name = find_nConst( nameBasics, reverse(principals->nconst) );
					
				if(name != NULL){
					printf( "%p\n", (void *)name );
					printf( "%s\n", name->nconst );
					printf( "%s\n", name->primaryName );
				}
			}
		}
		/*title = find_primary_title( titleBasics, ptr );
		printf( "%p\n", (void *)title );
		printf( "%s\n", title->tconst );
		printf( "%s\n", title->primaryTitle );	
					

		principals = find_tconst_tp( titlePrincipals,  reverse(title->tconst));
		printf( "%p\n", (void *)principals );
		printf( "%s\n", principals->nconst);
		printf( "%s\n", principals->tconst );
		printf( "%s\n", principals->characters );


		struct tree *top = find_topNode(&(titlePrincipals->tindex), reverse(title->tconst));
		
		print_ttree(top);
		name = find_nConst( nameBasics, reverse(principals->nconst) );
		if(name != NULL){
			printf( "%p\n", (void *)name );
			printf( "%s\n", name->nconst);
			printf( "%s\n", name->primaryName );
		}
		else{
			printf("Broke \n");
		}*/
		
	}
	else {
		printf("ERROR");
		
	}
	
	
	
	
/*"/home/courses/cis2520"
 */
printf("HELLOOOO %s \n", argv[1]);

 
 
  
/*
title = find_primary_title(titleBasics, "Star Wars: Episode V - The Empire Strikes Back")
printf("");
title = find_tConst(titleBasics, reverse("tt0080684"));
printf( "%p\n", (void *)title );
printf( "%s\n", title->tconst );
printf( "%s\n", title->primaryTitle );
*/

 /* 
  name = find_nConst( nameBasics, reverse("nm0000001") );
  printf( "%p\n", (void *)name );
printf( "%s\n", name->nconst);
printf( "%s\n", name->primaryName );

name = find_primary_name(nameBasics, "John Belushi");
printf( "%p\n", (void *)name );
printf( "%s\n", name->nconst);
printf( "%s\n", name->primaryName );
*/


/*
principals = find_tconst_tp( titlePrincipals, reverse("tt0000005") );
  printf( "%p\n", (void *)principals );
printf( "%s\n", principals->nconst);
printf( "%s\n", principals->tconst );
printf( "%s\n", principals->characters );


principals = find_nconst_tp( titlePrincipals, "nm0653028" );
  printf( "%p\n", (void *)principals );
printf( "%s\n", principals->nconst);
printf( "%s\n", principals->tconst );
printf( "%s\n", principals->characters );
 */

  printf( "Ready\n" );
  
 /* 

printf("%s\n", name->primaryName);*/





 
/*
  printf( "%s\n", name->primaryName );
	*/
	
	

/*
 

  printf( "%p\n", (void *)title );

  printf( "%s\n", title->nconst );

  printf( "%s\n", title->primaryName );
	
	
free_tree( titleBasics->nindex );	
*/	
	return 0;	
}
