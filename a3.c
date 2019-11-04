#include <stdio.h>
#include <stdlib.h>

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
	/*if(argc<2){
		fprintf( stderr, "Usage:  %s directory\n", argv[0] );
		return -1;
	}*/
	/*ptrName = get_name("/home/courses/cis2520");*/
	/*pInfo = get_titlePrinciples("/home/courses/cis2520");
	ptrPrincipals = get_titlePrinciples("/home/courses/cis2520"); 
	*/
	int j=0;
	/*struct titleInfo *titleBasics = NULL;
	  titleBasics = get_title("/home/courses/cis2520");

  build_tindex( titleBasics );

 
struct title_basics *title = NULL;
  title = find_primary_title( titleBasics, 

                            "Star Wars: Episode V - The Empire Strikes Back" );

 

  printf( "%p\n", (void *)title );

  printf( "%s\n", title->tconst );

  printf( "%s\n", title->primaryTitle );
	*/
	
	
	struct nameInfo *titleBasics = NULL;
	
	titleBasics = get_name("/home/courses/cis2520");
 

  build_nindex( titleBasics );

 
struct name_basics *title = NULL;
  title = find_primary_name( titleBasics, 

                            "Anthony Daniels" );

 

  printf( "%p\n", (void *)title );

  printf( "%s\n", title->nconst );

  printf( "%s\n", title->primaryName );
	
	
	/*CODE FOR TESTING THE title
	  while(ptr[j] != NULL){
		printf("nConst:	%s \tName:	%s\n", ptr[j]->tconst, ptr[j]->primaryTitle);
		j++;
	}*/
	
free_tree( titleBasics->nindex );	
	
	return 0;	
}
