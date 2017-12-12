#include "ciscord.h"


char * Dfind_key(int argc, char * argv[])
	/**
	 * Search args for an API key passed with -k <KEY>.
	 * If none found, searches current working dir for a file matching /key/i, and tries the first one.
	 *
	 * Return pointer to null-terminated string if found.
	 * Return NULL if none found.
	 */
{
	int i;
	int next_is_key = 0;
	for(i=0;i<argc;i++){
		if(strcmp(argv[i],"-k") == 0){
			next_is_key = 1;
			continue;
		}
		if(next_is_key == 1){
			printf("key: %s", argv[i]);
			return argv[i];
		}
	}

	// Nothing in the command line args? Darn.
	// Okay, search the wd for a key file.
	FILE * f = popen("ls -a -1 | grep -i key | head -n 1", "r");
	if(!f){
		// couldn't open :(
		fprintf(stderr, "[WARN] Failed to open pipe to search for key file.  :(\n");
		fprintf(stderr, "[WARN] This probably means:\n");
		fprintf(stderr, "       * You're out of memory          ([DIETY] help you)\n");
		fprintf(stderr, "       * You don't have sh or bash     ([DIETY] help you)\n");
		fprintf(stderr, "       * Your os doesn't support pipes ([DIETY] help you)\n");
	}
	
	char buf[256];
	
	fscanf(f, "%s", buf);
	
	fprintf(stderr, "%s",buf);
	
	pclose(f);
}
