#include <ciscord/internal/curl_helpers.h>

CURL * ld_get_curl_handle(ld_t * ld) {
	CURL * handle = curl_easy_init();
	
	curl_easy_setopt(handle, CURLOPT_USERAGENT,ld->user_agent);
	
	// Add authorization header
	
	// Other ****
	
	return handle;
}
