#include "ciscord.h"
#include "cdis_internal.h"

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
			cdis_log_info("Command-line key: ``%s''\n", argv[i]);
			return argv[i];
		}
	}

	// Nothing in the command line args? Darn.
	// Okay, search the wd for a key file.
	FILE * pipe = popen("ls -a -1 | grep -i key | head -n 1", "r");
	
	if(pipe == NULL){
		// couldn't open :(
		cdis_log_warn("Failed to open pipe to search for key file.  :(\n");
		pclose(pipe);
		return NULL;
	}
	
	char fname[256];
	fscanf(pipe, "%s", fname);
	pclose(pipe);
	
	if(access(fname,F_OK) == -1){
		cdis_log_warn("No keyfile found.\n");
		return NULL;
	}

	if(access(fname,R_OK) == -1){
		cdis_log_warn("Couldn't open \e[4m%s\e[0m for reading, permissions error.\n",fname);
		cdis_log_warn("Try \e[1mchmod +r %s\e[0m\n",fname);
		return NULL;
	}
	
	FILE * f = fopen(fname, "r");

	cdis_log_info("Keyfile: \e[1m%s\e[0m\n",fname);
	
	
	if(f == NULL){
		cdis_log_warn("Failed to open keyfile for reading.\n");
		cdis_log_warn("Since I checked if you can open it already, this probably means you're out of memory.\n");
		return NULL;
	}
	
	char key[256];
	
	fscanf(f, "%s", key);
	
	cdis_log_info("Key: \e[1m%s\e[0m\n",key);
}
