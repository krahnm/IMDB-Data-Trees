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
	
	
	while((*ptr)!='\0' && i!=colNum){/*moves to specific column*/
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

char *reverse(char* string){
	 char *revString = NULL;
	 char *ptr = string;
	 char holder;
	 int start = 0;
	 int end = 0;
	 int length = strlen(string);
	 int i = 0;
	 revString = malloc(strlen(string) + 1);
	 
	 
	 
	 for(i = 0; i < length; i++){
		 holder = ptr[length - i - 1];
		 revString[i] = holder;
	 }
	 revString[length] = '\0';
	 string = revString;
	 free(revString);
	 return (char*)string;
	 
}

void free_tree( struct tree *root )
{
  if (root)
  {
    free_tree( root->children[0] );
    free_tree( root->children[1] );
    free( root );
  }
}
