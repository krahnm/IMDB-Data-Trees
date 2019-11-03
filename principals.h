struct title_principals {
	char *tconst;
	char *nconst;
	char *characters;
	};
	
struct principalsInfo {
		int numItems;
		struct title_principals **array;
		struct tree **nConstRoot;
		struct tree **tConstRoot;
	};	

struct principalsInfo *get_titlePrinciples(char *);
