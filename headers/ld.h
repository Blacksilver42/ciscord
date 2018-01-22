#ifndef __CISCORD_LD_H__
#define __CISCORD_LD_H__



typedef struct {
	char * token;
	char * name;
	char * user_agent;
	char * auth_header;
	char * base_url;
} ld_t;


void ld_init(ld_t * ld, const char * token, const char * botname);

#endif
