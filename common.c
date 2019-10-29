#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "binary.h"
#include "common.h"
#include "name.h"

void get_column(char *buffer, char *string1, char *string2, char *string3, int colNum){
	char *ptr;
	char holder; /*Holds characters to copy over*/
	int i=0;
	int len=0;
	ptr = buffer;
	string1[0] = '\0';
	
	while((*ptr)!='\0' && (*ptr)!='\t'){ /*Get first entry eg. nconst*/
		
		holder = *ptr;
		len = strlen(string1);
		string1[len] = holder;
		string1[len+1] = '\0';
		
			
		(ptr)++;
	}
	
	while((*ptr)!='\0' && i!=colNum){
		if((*ptr)=='\t'){
			i++;
		}
		
		(ptr)++;
	}
	
	len=0;
	string2[0] = '\0';
	
	while((*ptr)!='\0' && (*ptr)!='\t'){ /*Get specified comumn*/
		
		holder = *ptr;
		len = strlen(string2);
		string2[len] = holder;
		string2[len+1] = '\0';
		
			
		(ptr)++;
	}
}
