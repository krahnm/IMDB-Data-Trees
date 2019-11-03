#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "common.h"
#include "binary.h"
#include "title.h"


void add_node(struct tree **root, char *string, struct title_basics *address){
	if (*root) /* there's a node here */
  {
    /*if ( tree_cmp(number,(*root)->number) < 0 )
    {
      strcat( path, "0" ); 
      add_node( &((*root)->children[0]), number, path );
    }
    else
    {
      strcat( path, "1" ); 
      add_node( &((*root)->children[1]), number, path );
    }*/
  }
  else /* no node here */
  {
	  printf("NO ROOT\n");
    (*root) = malloc( sizeof( struct tree ) );
    (*root)->key = string;
    (*root)->value = address;
    (*root)->children[0]=NULL;
    (*root)->children[1]=NULL;
  }
}
 
