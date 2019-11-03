
struct name_basics {
	char *nconst;
	char *primaryName;
	};
	
struct nameInfo {
		int numItems;
		struct name_basics**array;
		struct tree **nConstRoot;
		struct tree **nameRoot;
	};		

struct nameInfo *get_name(char *);
