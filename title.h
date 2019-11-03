
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
