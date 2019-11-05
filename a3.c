#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary.h"
#include "common.h"
#include "name.h"
#include "principals.h"
#include "title.h"
 
/*TESTINGGGGGGGG*/
int main(int argc, char *argv[]){
	struct name_basics **ptrName = NULL;
	struct title_basics **ptrTitle = NULL;
	struct title_principals **ptrPrincipals = NULL;
	struct titleInfo *tInfo = NULL;
	struct principalsInfo *pInfo = NULL;
	if(argc<2){
		fprintf( stderr, "Usage:  %s directory\n", argv[0] );
		return -1;
	}
	/*ptrName = get_name("/home/courses/cis2520");*/
	/*pInfo = get_titlePrinciples("/home/courses/cis2520");
	ptrPrincipals = get_titlePrinciples("/home/courses/cis2520"); 
	*/
	int j=0;
	int i =0;
	char* ptr;
	char* string = malloc(256);
	char* string1 = malloc(256);
	int colNum = 1;
	char holder; /*Holds characters to copy over*/
	int len=0;
	char *buffer = malloc(256);
	
	string[0] = '\0';
	/*fgets(string, 256, stdin);
	
	
	printf(string);
	strcpy(string1, string);
	
	ptr = string1;*/ /*moves to specific column*/
		/*while((*ptr)!='\0' && i!=colNum && ((*ptr)+1)!='\n'){
		if((*ptr)==' '){
			i++;
		}
		
		(ptr)++;
	}
	ptr[strlen(ptr)-1] = '\0';
	printf("found worrddd %s \n", ptr);
	
	
if(strstr(string, "name")!=NULL){
		printf("name\n");
		printf("use %s \n", ptr);
		struct nameInfo *titleBasics = NULL;
		printf("%s \n", argv[1]);
		titleBasics = get_name(argv[1]);
 

		build_nindex( titleBasics );

 
		struct name_basics *title = NULL;
		title = find_primary_name( titleBasics, ptr );
		
		printf( "%p\n", (void *)title );

		printf( "%s\n", title->nconst );

		printf( "%s\n", title->primaryName );
	
	
	
	}
	else if(strstr(string, "title")!=NULL){
		printf("title\n");
		printf("use [%s] \n", ptr);
		
		struct titleInfo *titleBasics = NULL;
		struct title_basics *title = NULL;
		titleBasics = get_title( argv[1] );

		build_tindex( titleBasics );

		title = find_primary_title( titleBasics, ptr );

	  printf( "%p\n", (void *)title );

	  printf( "%s\n", title->tconst );

	  printf( "%s\n", title->primaryTitle );
		
	}
	else {
		printf("ERROR");
		
	}*/
	
/*"/home/courses/cis2520"
 */
printf("HELLOOOO %s \n", argv[1]);
struct title_basics *title = NULL;
 struct name_basics *name = NULL;
 struct name_basics *name2 = NULL;
  struct title_principals *principals = NULL;
 
 struct titleInfo *titleBasics = NULL;
   titleBasics = get_title( argv[1] );

  build_tconstindex( titleBasics );
build_tindex( titleBasics );
  
/*
title = find_primary_title(titleBasics, "Star Wars: Episode V - The Empire Strikes Back")
printf("");
title = find_tConst(titleBasics, reverse("tt0080684"));
printf( "%p\n", (void *)title );
printf( "%s\n", title->tconst );
printf( "%s\n", title->primaryTitle );
*/
struct nameInfo *nameBasics = NULL;
  nameBasics = get_name( argv[1] );

  build_nconstindex( nameBasics );

  build_nindex( nameBasics );
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

struct principalsInfo *titlePrincipals = NULL;
  titlePrincipals = get_principals(argv[1] );

  build_tindex_tp( titlePrincipals );

  build_nindex_tp( titlePrincipals );
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
  
  title = find_primary_title( titleBasics, "Blade Runner" );
printf( "%p\n", (void *)title );
printf( "%s\n", title->tconst );
printf( "%s\n", title->primaryTitle );					

 principals = find_tconst_tp( titlePrincipals,  reverse(title->tconst));
  printf( "%p\n", (void *)principals );
printf( "%s\n", principals->nconst);
printf( "%s\n", principals->tconst );
printf( "%s\n", principals->characters );

  name = find_nConst( nameBasics, reverse(principals->nconst) );
  printf( "%p\n", (void *)name );
printf( "%s\n", name->nconst);
printf( "%s\n", name->primaryName );

printf("%s\n", name->primaryName);
 
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
