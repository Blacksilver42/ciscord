#include <ciscord/ciscord.h>
#include <ciscord/internal.h>

void ld_init(ld_t * ld, const char * token, const char * botname){
	
	char * base_url = "https://discordapp.com/api/v6";
	
	ld->token = malloc(strlen(token)+1);
	ld->name = malloc(strlen(botname)+1);
	ld->base_url = malloc(strlen(base_url));
	
	strcpy(ld->token, token);
	strcpy(ld->name, botname);
	strcpy(ld->base_url,base_url);
	
	char * agent_format = "%s (Ciscord, " LD_VSTRING ")";
	char * auth_format = "Authorization: Bot %s";
	
	ld->auth_header = calloc(strlen(auth_format)  + strlen(token)   + 1, sizeof(char));
	ld->user_agent  = calloc(strlen(agent_format) + strlen(botname) + 1, sizeof(char));
	
	sprintf(ld->auth_header, auth_format,  token);
	sprintf(ld->user_agent,  agent_format, botname);
	
	
	ld_log_info("ld_t init at %x complete.\n", ld);
}
