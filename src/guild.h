#ifndef __CISCORD_GUILD_H__
#define __CISCORD_GUILD_H__

typedef struct {
	const char * name;
	const char * icon;
	const char * splash;
	const char * region;
	const char * afk_timeout;

	SNOWFLAKE id;
	SNOWFLAKE afk_chan;
	SNOWFLAKE owner_id;
	SNOWFLAKE embed_channel_id;
	
	PERMISSIONS permissions;
	ROLE * roles;
	
	bool owner;
	bool embed_enabled;
	bool default_message_notifications;
	
	int verification_level;
} guild_t;

#define GUILD guild_t

#endif
