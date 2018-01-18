#ifdef __CISCORD_USER_H__
#warning user.h doubleinclude
#else
#define __CISCORD_USER_H__

typedef struct {
	SNOWFLAKE id;
	char * username;
	int discriminator;
	char * avatar;
	bool bot;
	bool mfa_enabled;
	bool verified;
	char * email;
} ld_user_t;

#endif
