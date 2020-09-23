#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "principals.h"
#include "common.h"
#include "binary.h"
#include "title.h"

/*
This file handles everything related to the binary trees
*/

/*Adds nodes on the Title trees*/
void add_tnode(struct tree **root, char *string, struct title_basics *address)
{
	if (*root) /* there's a node here */
  	{
    		if ( strcmp(string,(*root)->key) < 0 ) /*Checks the child branches*/
    		{
      			add_tnode( &((*root)->children[0]), string, address );
    		}
   		else
    		{
      			add_tnode( &((*root)->children[1]), string, address );
    		}
  	}
  	else /* no node here - creates the new child branch and fills */
  	{
    		(*root) = malloc( sizeof( struct tree ) );
    		(*root)->key = string;
    		(*root)->value = address;
    		(*root)->children[0]=NULL;
    		(*root)->children[1]=NULL;
  	}
}

/*Adds nodes for the Name tree*/
void add_nnode(struct tree **root, char *string, struct name_basics *address)
{
	if (*root) /* there's a node here - continues on to find the trees children */
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
  	else /* no node here - creates the new child nodes*/
  	{
    		(*root) = malloc( sizeof( struct tree ) );
    		(*root)->key = string;
    		(*root)->value = address;
    		(*root)->children[0]=NULL;
    		(*root)->children[1]=NULL;
  	}
}

/*Adds nodes to liknk the name and title trees - the title side*/
void add_ptnode(struct tree **root, char *string, struct title_principals *address)
{
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
  	else /* no node here - create children*/
  	{
    		(*root) = malloc( sizeof( struct tree ) );
    		(*root)->key = string;
    		(*root)->value = address;
    		(*root)->children[0]=NULL;
    		(*root)->children[1]=NULL;
  	}	
}
/*Adds nodes to liknk the name and title trees - the name side*/
void add_pnnode(struct tree **root, char *string, struct title_principals *address)
{
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
  	else /* no node here - create children*/
  	{
    		(*root) = malloc( sizeof( struct tree ) );
    		(*root)->key = string;
    		(*root)->value = address;
   		(*root)->children[0]=NULL;
    		(*root)->children[1]=NULL;
  	}
}
/*Finds the specific node in the title tree*/
struct title_basics *find_tnode(struct tree *root, char * toFind)
{
	if (root)
  	{
    		if ( strcmp(toFind,(root)->key) == 0 ) /*Found the node*/
    		{
      			return (struct title_basics *)(root->value);
    		}
    		else
    		{
     			if ( strcmp(toFind,(root)->key) < 0 )/*keep searching for node*/
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
/*Finds the specific node in the name tree*/
struct name_basics *find_nnode(struct tree *root, char * toFind)
{
	if (root)
  	{
    		if ( strcmp(toFind,(root)->key) == 0 )/*found node and returns value*/
    		{
      			return (struct name_basics *)(root->value);
    		}
    		else
    		{
      			if ( strcmp(toFind,(root)->key) < 0 )/*keeps looking for the node*/
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
/*Finds the specific node in linker tree*/
struct title_principals *find_pnode(struct tree *root, char * toFind)
{
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
/*finds the name/title so you can easily list the associated moves/actor list*/
struct tree *find_topNode(struct tree **root, char * toFind)
{
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


 
