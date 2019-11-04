
struct name_basics {
	char *nconst;
	char *primaryName;
	};
	
struct nameInfo {
		int numItems;
		struct name_basics **value;
		struct tree *tindex;
		struct tree *nindex;
	};		

struct nameInfo *get_name(char *);

void build_nindex(struct nameInfo *nInfo);
void build_nconstindex(struct nameInfo *nInfo);
struct name_basics *find_primary_name(struct nameInfo *nInfo, char * toFind);

void add_nnode(struct tree **e, char *r, struct name_basics *t);
struct name_basics *find_nnode(struct tree *q, char * w);
struct name_basics *find_nConst(struct nameInfo *nInfo, char * toFind);
