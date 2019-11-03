
struct title_basics {
	char *tconst;
	char *primaryTitle;
	};
	
	struct titleInfo {
		int numItems;
		struct title_basics **array;
		struct tree **nConstRoot;
		struct tree **nameRoot;
	};
	
struct titleInfo *get_title(char *);
