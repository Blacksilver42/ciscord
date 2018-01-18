#include <time.h>

#include <ciscord/ciscord.h>

// Make a shiny blank channel.
ld_chan_t * ld_chan_make(ld_chan_t * buf){
	if(buf == NULL){
		ld_log_warn("ld_chan_blank(%x): Null buf; allocating for you.", buf);
		buf = malloc(sizeof(ld_chan_t));
	}
	
	
}

// helper to convert ISO 1801 (as returned by the API) to struct tm.
struct tm * ld_convert_8601(struct tm * buf, char * stamp){
	char * rc = strptime(stamp, "%Y-%m-%d %H:%M", buf);
	
	if(rc == NULL){
		return NULL;
	} else {
		return buf;
	}
}

const char * D_chan_perform(ld_t ld, SNOWFLAKE id){
	// actually do the curl call; return the raw string.
	CURL * handle = ld_get_curl_handle(ld);
	
	char url[256] = sprintf("%s/channels/%s/", ld->base_url, id);
	
	curl_easy_setopt(handle, CURLOPT_URL, url);
	
	curl_easy_perform(handle);
	curl_easy_cleanup(handle);
}

ld_chan_t * D_chan_get(LD ld, SNOWFLAKE id){
	
}

