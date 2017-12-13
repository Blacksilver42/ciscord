#include "ciscord.h"


void Dinit(){
	curl_version_info_data curlV;
	curlV = *curl_version_info(CURLVERSION_NOW);
	
	if(curlV.age >= 0){
		fprintf(stderr, "[CDIS/INFO] curl version: %s\n",curlV.version);
	} else {
		fprintf(stderr, "[CDIS/WARN] curl_version.age < 0 ?!\n");
	}
}
