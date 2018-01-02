// helpers to find what you're looking for

#include <ciscord/ciscord.h>
#include <ciscord/internal.h>


// guild_t * Dfind_guild_name(CDIS cdis, guild_t * buf, const char * name) {...}
guild_t * Dfind_guild_id(CDIS cdis, guild_t * buf, const char * id){
	CURL * curl = ciscord_get_curl_handle(cdis);
	
}

// chan_t * Dfind_chan_name(CDIS cdis, chan_t * buf, const char * name){...}
// chan_t * Dfind_chan_id(CDIS cdis, chan_t * buf, char * id){...}
