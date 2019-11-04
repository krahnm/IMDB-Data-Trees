#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary.h"
#include "common.h"
#include "name.h"
#include "principals.h"
#include "title.h"
 

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
	fgets(string, 256, stdin);
	
	
	printf(string);
	strcpy(string1, string);
	
	ptr = string1;
	while((*ptr)!='\0' && i!=colNum){/*moves to specific column*/
		if((*ptr)==' '){
			i++;
		}
		
		(ptr)++;
	}
	printf("%s \n", ptr);
	if(strstr(string, "name")!=NULL){
		printf("name\n");
		printf("use %s \n", ptr);
		struct nameInfo *titleBasics = NULL;
	
		titleBasics = get_name(argv[1]);
 

		build_nindex( titleBasics );

 
		struct name_basics *title = NULL;
		title = find_primary_name( titleBasics, ptr );
	}
	else if(strstr(string, "title")!=NULL){
		printf("title\n");
		printf("use %s \n", ptr);
	}
	else {
		printf("ERROR");
		
	}
	
/*"/home/courses/cis2520"
 */
/*
struct title_basics *title = NULL;
 struct name_basics *name = NULL;
  struct title_principals *principals = NULL;
 
 struct titleInfo *titleBasics = NULL;
   titleBasics = get_title( argv[1] );

  build_tconstindex( titleBasics );

  build_tindex( titleBasics );


struct nameInfo *nameBasics = NULL;
  nameBasics = get_name( argv[1] );

  build_nconstindex( nameBasics );
*//*
  build_nindex( nameBasics );

 
struct principalsInfo *titlePrincipals = NULL;
  titlePrincipals = get_principals(argv[1] );

  build_tindex_tp( titlePrincipals );

  build_nindex_tp( titlePrincipals );

 

  printf( "Ready\n" );
  
  */ /*name = find_nConst( nameBasics, principals->nconst );
  printf("%s\n", name->primaryName);

  title = find_primary_title( titleBasics, "Blade Runner" );

 principals = find_tconst_tp( titlePrincipals, title->tconst );

  name = find_nConst( nameBasics, principals->nconst );

 
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
