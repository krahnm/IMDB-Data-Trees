#include <stdio.h>
#include "binary.h"
#include "common.h"
#include "name.h"
#include "principals.h"
#include "title.h"
 

int main(int argc, char *argv[]){
	struct name_basics *ptr = NULL;
	
	/*if(argc<2){
		fprintf( stderr, "Usage:  %s directory\n", argv[0] );
		return -1;
	}*/
	
	ptr = get_name("/home/courses/cis2520"); /*Replace with the input from the terminal*/
	
	return 0;	
}
