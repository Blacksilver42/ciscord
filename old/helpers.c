#include <ciscord/ciscord.h>
#include <ciscord/internal.h>


char * find_key(int argc, char * argv[])
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
			disC_log_info("Key: \e[1m%s\e[0m\n", argv[i]);
			return argv[i];
		}
	}

	// Nothing in the command line args? Darn.
	// Okay, search the wd for a key file.
	FILE * pipe = popen("ls -a -1 | grep -i key | head -n 1", "r");
	
	if(pipe == NULL){
		// couldn't open :(
		disC_log_warn("Failed to open pipe to search for key file.  :(\n");
		pclose(pipe);
		return NULL;
	}
	
	char fname[256];
	fscanf(pipe, "%s", fname);
	pclose(pipe);
	
	if(access(fname,F_OK) == -1){
		disC_log_warn("No keyfile found.\n");
		return NULL;
	}

	if(access(fname,R_OK) == -1){
		disC_log_warn("Couldn't open \e[4m%s\e[0m for reading, permissions error.\n",fname);
		disC_log_warn("Try \e[1mchmod +r %s\e[0m\n",fname);
		return NULL;
	}
	
	FILE * f = fopen(fname, "r");

	disC_log_info("Keyfile: \e[1m%s\e[0m\n",fname);
	
	
	if(f == NULL){
		disC_log_warn("Failed to open keyfile for reading.\n");
		disC_log_warn("Since I checked if you can open it already, this probably means you're out of memory.\n");
		return NULL;
	}
	
	char * key = malloc(CDIS_SNOWFLAKE_LEN);
	
	fscanf(f, "%s", key);
	
	disC_log_info("Key: \e[1m%s\e[0m\n",key);
	return key;
}



char * mention(user_t * usr, char * buf)
	/* get mentionstring for user.
	 * if buf is null, allocates some memory for you.
	 */
{
	if(buf == NULL)
		buf = calloc(64, sizeof(char));
	
	sprintf(buf, "@%s#%d",usr->name, usr->tag);
	
	return buf;
}


ctx_t *	makectx(ctx_t * buf, guild_t * guild, chan_t * chan){
	if(buf == NULL){
		buf = malloc(sizeof(ctx_t));
		if(buf == NULL){
			// shit. malloc failed.
			disC_log_darn("makectx(NULL, %x, %x): malloc() failed. (%s)",
			guild, chan, strerror(errno));
			return NULL;
		}
		disC_log_warn("makectx(NULL, %x, %x): allocating \e[1mbuf\e[0m for you\n",
			guild, chan);
	}
	buf->chan = chan;
	buf->guild = guild;

	return buf;
}
