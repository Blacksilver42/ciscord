#define _XOPEN_SOURCE // strptime, struct tm
#include <ciscord/ciscord.h>
#include <ciscord/internal.h>

// Allocate a channel
ld_chan_t * ld_chan_alloc(ld_chan_t * buf){
	if(buf == NULL){
		ld_log_warn("ld_chan_alloc(%x): Null buf; allocating for you.", buf);
		buf = malloc(sizeof(ld_chan_t));
	}
	return buf;
}

// Make a shiny blank channel.
ld_chan_t * ld_chan_make(ld_chan_t * buf){
	buf = ld_chan_alloc(buf);
	
	// Allocate other variables
	
	return buf;
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

char * D_chan_perform(ld_t * ld, SNOWFLAKE id){
	// actually do the curl call; return the raw string.
	CURL * handle = ld_get_curl_handle(ld);
	
	char url[256];
	sprintf(url, "%s/channels/%s/", ld->base_url, id);
	ld_log_info("D_chan_perform(%x,%x): url: '%s'", ld, &id, url);
	
	curl_easy_setopt(handle, CURLOPT_URL, url);
	
	curl_easy_perform(handle);
	curl_easy_cleanup(handle);
	
	return NULL;
}

ld_chan_t * D_chan_get(ld_t * ld, ld_chan_t * buf, SNOWFLAKE id){
	
	//char * result;
	
	/*result = */D_chan_perform(ld, id);

	// Parse
	
	buf = NULL;
	return buf;
}

