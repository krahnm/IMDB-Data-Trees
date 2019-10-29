#include <stdio.h>
#include "binary.h"
#include "common.h"
#include "name.h"
#include "principals.h"
#include "title.h"
 

int main(int argc, char *argv[]){
	struct name_basics **ptr = NULL;
	
	/*if(argc<2){
		fprintf( stderr, "Usage:  %s directory\n", argv[0] );
		return -1;
	}*/
	
	ptr = get_name("/home/courses/cis2520"); /*Replace with the input from the terminal*/
	
	int j=0;
	
	while(ptr[j]!=NULL){
		printf("nConst:	%s \tName:	%s\n", ptr[j]->nconst, ptr[j]->primaryName);
		j++;
	}
	
	return 0;	
}
