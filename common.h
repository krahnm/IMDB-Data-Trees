
struct tree
{
  void *data;
  char *key;
  struct tree *children[2];
};


void get_column(char*, char*, int); /*string1 holds first column(nconst). string2 holds specified column*/
