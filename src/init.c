#include "ciscord.h"
#include "cdis_internal.h"

void Dinit(){
	curl_version_info_data curl_version;
	curl_version = *curl_version_info(CURLVERSION_NOW);
	
	cdis_log_info("cdis version: \e[1m%s %s\n\e[0m", CDIS_VSTRING, CDIS_VNOTE);
	
	if(curl_version.age >= 0){
		cdis_log_info("curl version: \e[1m%s\e[0m\n",curl_version.version);
	} else {
		cdis_log_warn("curl_version.age<0 ?!\n");
	}
}
