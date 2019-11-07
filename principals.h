struct title_principals {
	char *tconst;
	char *nconst;
	char *characters;
	};
	
struct principalsInfo {
		int numItems;
		struct title_principals **value;
		struct tree *tindex;
		struct tree *nindex;
	};	

struct principalsInfo *get_principals(char *);
void build_tindex_tp(struct principalsInfo *nInfo);
struct title_principals *find_tconst_tp(struct principalsInfo *nInfo, char * toFind);
void build_nindex_tp(struct principalsInfo *nInfo);
struct title_principals *find_nconst_tp(struct principalsInfo *nInfo, char * toFind);
struct name_basics *find_nnode(struct tree *q, char * w);

void add_pnnode(struct tree **root, char *string, struct title_principals *address);
void add_ptnode(struct tree **root, char *string, struct title_principals *address);
