
struct title_basics {
	char *tconst;
	char *primaryTitle;
	};
	
	struct titleInfo {
		int numItems;
		struct title_basics **value;
		struct tree *tindex;
		struct tree *nindex;
	};
	
struct titleInfo *get_title(char *);

void build_tindex(struct titleInfo *tInfo);

struct title_basics *find_primary_title(struct titleInfo *tInfo, char * toFind);

void add_tnode(struct tree **e, char *r, struct title_basics *t);
/*struct title_basics *find_tnode(struct tree *q, char * w);
*/
void build_tconstindex(struct titleInfo *tInfo);
struct title_basics *find_tConst(struct titleInfo *tInfo, char * toFind);
struct title_basics *find_tnode(struct tree *root, char * toFind);
