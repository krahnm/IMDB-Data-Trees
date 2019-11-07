#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "principals.h"
#include "common.h"
#include "binary.h"
#include "title.h"


void add_tnode(struct tree **root, char *string, struct title_basics *address){
	if (*root) /* there's a node here */
  {
    if ( strcmp(string,(*root)->key) < 0 )
    {
      add_tnode( &((*root)->children[0]), string, address );
    }
    else
    {
      add_tnode( &((*root)->children[1]), string, address );
    }
  }
  else /* no node here */
  {
    (*root) = malloc( sizeof( struct tree ) );
    (*root)->key = string;
    (*root)->value = address;
    (*root)->children[0]=NULL;
    (*root)->children[1]=NULL;
  }
}

void add_nnode(struct tree **root, char *string, struct name_basics *address){
	if (*root) /* there's a node here */
  {
    if ( strcmp(string,(*root)->key) < 0 )
    {
      add_nnode( &((*root)->children[0]), string, address );
    }
    else
    {
      add_nnode( &((*root)->children[1]), string, address );
    }
  }
  else /* no node here */
  {
    (*root) = malloc( sizeof( struct tree ) );
    (*root)->key = string;
    (*root)->value = address;
    (*root)->children[0]=NULL;
    (*root)->children[1]=NULL;
  }
}

void add_ptnode(struct tree **root, char *string, struct title_principals *address){
	if (*root) /* there's a node here */
  {
    if ( strcmp(string,(*root)->key) < 0 )
    {
      add_ptnode( &((*root)->children[0]), string, address );
    }
    else
    {
      add_ptnode( &((*root)->children[1]), string, address );
    }
  }
  else /* no node here */
  {
    (*root) = malloc( sizeof( struct tree ) );
    (*root)->key = string;
    (*root)->value = address;
    (*root)->children[0]=NULL;
    (*root)->children[1]=NULL;
  }
}

void add_pnnode(struct tree **root, char *string, struct title_principals *address){
	if (*root) /* there's a node here */
  {
    if ( strcmp(string,(*root)->key) < 0 )
    {
      add_pnnode( &((*root)->children[0]), string, address );
    }
    else
    {
      add_pnnode( &((*root)->children[1]), string, address );
    }
  }
  else /* no node here */
  {
    (*root) = malloc( sizeof( struct tree ) );
    (*root)->key = string;
    (*root)->value = address;
    (*root)->children[0]=NULL;
    (*root)->children[1]=NULL;
  }
}

struct title_basics *find_tnode(struct tree *root, char * toFind){
	if (root)
  {
    if ( strcmp(toFind,(root)->key) == 0 )
    {
      return (struct title_basics *)(root->value);
    }
    else
    {
      if ( strcmp(toFind,(root)->key) < 0 )
      {
        return find_tnode( root->children[0], toFind );
      }
      else /* value>=(root)->number */
      {
        return find_tnode( root->children[1], toFind );
      }
    }

  }
  else 
  {
    return NULL;
  }
}

struct name_basics *find_nnode(struct tree *root, char * toFind){
	if (root)
  {
    if ( strcmp(toFind,(root)->key) == 0 )
    {
      return (struct name_basics *)(root->value);
    }
    else
    {
      if ( strcmp(toFind,(root)->key) < 0 )
      {
        return find_nnode( root->children[0], toFind );
      }
      else /* value>=(root)->number */
      {
        return find_nnode( root->children[1], toFind );
      }
    }

  }
  else 
  {
    return NULL;
  }
}

struct title_principals *find_pnode(struct tree *root, char * toFind){
	if (root)
  {
    if ( strcmp(toFind,(root)->key) == 0 )
    {
      return (struct title_principals *)(root->value);
    }
    else
    {
      if ( strcmp(toFind,(root)->key) < 0 )
      {
        return find_pnode( root->children[0], toFind );
      }
      else /* value>=(root)->number */
      {
        return find_pnode( root->children[1], toFind );
      }
    }

  }
  else 
  {
    return NULL;
  }
}

struct tree *find_topNode(struct tree **root, char * toFind){
	
	
	if (*root)
  {
	 
    if ( strcmp(toFind,(*root)->key) == 0 )
    {
      return (*root);
    }
    else
    {
      if ( strcmp(toFind,(*root)->key) < 0 )
      {
        return find_topNode( &((*root)->children[0]), toFind );
      }
      else /* value>=(root)->number */
      {
        return find_topNode( &((*root)->children[1]), toFind );
      }
    }

  }
  else 
  {
    return NULL;
  }
}


 
