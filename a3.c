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
	pInfo = get_titlePrinciples("/home/courses/cis2520");
	/*ptrPrincipals = get_titlePrinciples("/home/courses/cis2520"); 
	*/
	int j=0;
	ptrPrincipals = (pInfo->array);
	/*CODE FOR TESTING THE title
	  while(ptr[j] != NULL){
		printf("nConst:	%s \tName:	%s\n", ptr[j]->tconst, ptr[j]->primaryTitle);
		j++;
	}*/
	
	/*while(ptr[j] != NULL){
		printf("tConst:	%s \t nConst: %s \t Character: %s\n", ptr[j]->tconst, ptr[j]->nconst, ptr[j]->characters);
		j++;
	}*/
	
	/*printf("NUMBERR: %d", tInfo->numItems);
	int i = 0;
	for (i=0;i<10;i++)

  {

    printf( "%s %s\n", ptrTitle[i]->tconst, ptrTitle[i]->primaryTitle );

  }
 

  printf( "\n" );

  for (i=524595;i<524605;i++)

  {

    printf( "%s %s\n", ptrTitle[i]->tconst, ptrTitle[i]->primaryTitle );

  }
	*/
	
	
	int i = 0;
	 for (i=0;i<10;i++)

  {

    printf( "%s %s %s\n", ptrPrincipals[i]->tconst,

                          ptrPrincipals[i]->nconst,

                          ptrPrincipals[i]->characters );

  }

  printf( "\n" );

  for (i=14627307;i<14627317;i++)

  {

    printf( "%s %s %s\n", ptrPrincipals[i]->tconst,

                          ptrPrincipals[i]->nconst,

                          ptrPrincipals[i]->characters );

  }
	
	
	
	return 0;	
}
