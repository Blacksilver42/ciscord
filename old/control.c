// Functions for fooling with the CDIS struct

#include <ciscord/ciscord.h>
#include <ciscord/internal.h>


char * Dkey(CDIS disC, char * key) {
	if(key == NULL){
		disC_log_warn("Dkey: No, \e[1myou\e[0m deal with this. (key==NULL)\n");
		return NULL;
	}
	// What if the key is already allocated?
	// There'd be a memory leak.
	// Uhhh... TODO: A way to check this.
	
	disC->key = malloc(CDIS_SNOWFLAKE_LEN);
	
	strcpy(disC->key, key);
	
	return key;
}

