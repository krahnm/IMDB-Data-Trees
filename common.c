#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "binary.h"
#include "common.h"
#include "name.h"

void get_column(char *buffer, char *string, int colNum){
	char *ptr;
	char holder; /*Holds characters to copy over*/
	int i=0;
	int len=0;
	ptr = buffer;
	string[0] = '\0';
	
	
	while((*ptr)!='\0' && i!=colNum){
		if((*ptr)=='\t'){
			i++;
		}
		
		(ptr)++;
	}
	
	len=0;
	string[0] = '\0';
	
	while((*ptr)!='\0' && (*ptr)!='\t'){ /*Get specified comumn*/
		
		holder = *ptr;
		len = strlen(string);
		string[len] = holder;
		string[len+1] = '\0';
		
			
		(ptr)++;
	}
}
