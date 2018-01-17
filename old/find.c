// helpers to find what you're looking for

#include <ciscord/ciscord.h>
#include <ciscord/internal.h>

void ciscord_guild_writefunc(char * ptr, size_t size, size_t nmemb, GUILD * buf){

}

// guild_t * Dfind_guild_name(CDIS disC, guild_t * buf, const char * name) {...}
guild_t * Dfind_guild_id(CDIS D, guild_t * buf, SNOWFLAKE id){
	CURL * curl = curl_easy_duphandle(D->curl);
	
	char tmp[SNOWFLAKE_LEN+50];
	
	sprintf(tmp, "https://discordapp.com/api/channels/%s");
	
	curl_easy_setopt(curl, CURLOPT_URL, buf);
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, ciscord_writefunc);

	curl_easy_perform(curl);
	
	curl_easy_cleanup(curl);
}



// chan_t * Dfind_chan_name(CDIS disC, chan_t * buf, const char * name){...}
// chan_t * Dfind_chan_id(CDIS disC, chan_t * buf, char * id){...}
