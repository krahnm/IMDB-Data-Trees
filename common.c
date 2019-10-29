#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "binary.h"
#include "common.h"
#include "name.h"

void get_column(char *buffer, char *contents, int colNum){
	char *ptr;
	char holder; /*Holds characters to copy over*/
	int i=0;
	int len=0;
	ptr = buffer;
	contents[0] = '\0';
	
	while((*ptr)!='\0' && i!=colNum){
		if((*ptr)=='\t'){
			i++;
		}
		
		(ptr)++;
	}
	
	while((*ptr)!='\0' && (*ptr)!='\t'){
		
		holder = *ptr;
		len = strlen(contents);
		contents[len] = holder;
		contents[len+1] = '\0';
		
			
		(ptr)++;
	}
}
