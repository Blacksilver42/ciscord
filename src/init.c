#include <ciscord/ciscord.h>
#include <ciscord/internal.h>


ciscord_t * cdis_init(CDIS cdis, char * key){
	if(cdis == NULL){
		cdis_log_warn("Allocating \e[1mD\e[0m struct for you.\n");
		cdis = malloc(sizeof(ciscord_t));
	}
	
	
	ciscord_t D = *cdis;
	
	cdis_log_info("D: \e[1m%s %s\n\e[0m", CDIS_VSTRING, CDIS_VNOTE);
	
	
	curl_version_info_data curl_version;
	curl_version = *curl_version_info(CURLVERSION_NOW);
	
	
	if(curl_version.age >= 0){
		cdis_log_info("Curl: \e[1m%s\e[0m\n",curl_version.version);
	} else {
		// God help you
	}
	
	CURLcode curlcode = curl_global_init(CURL_GLOBAL_ALL);
	
	if(curlcode != 0){
		cdis_log_darn("\e[1mcurl_global_init()\e[0m failed. %s",curl_easy_strerror(curlcode));
		exit(CDIS_E_CURLGLOBALINIT);
	}

	D.curl = curl_easy_init();

	if(D.curl == NULL) {
		cdis_log_darn("\e[1mcurl_easy_init()\e[0m failed. Memory?\n");
		exit(CDIS_E_CURLEASYINIT);
	} else {
		cdis_log_info("Curl: ready!\n");
		
	}

	curl_easy_setopt(D.curl, CURLOPT_USERAGENT, D.user_agent);
	
	struct curl_slist * chunk = NULL;
	chunk = curl_slist_append(chunk, D.auth_header);
	
	curl_easy_setopt(D.curl, CURLOPT_HTTPHEADER, chunk);
	
	return cdis;
}

