#ifndef __CISCORD_CHANNEL_H__
#define __CISCORD_CHANNEL_H__

#define CHANNEL_NAME_MAXLEN 100
#define CHANNEL_TOPIC_MAXLEN 1024

typedef struct {
	SNOWFLAKE id;
	char type[10];
	int allow, deny;
} D_overwrite_t

typedef struct {
	SNOWFLAKE id;
	int type;
	SNOWFLAKE guild_id;
	int position;
	D_overwrite_t * permission_overwrites;
	char name[CHANNEL_NAME_MAXLEN+1];
	char topic[CHANNEL_TOPIC_MAXLEN+1];
	bool nsfw;
	SNOWFLAKE last_message_id;
	int bitrate; // voice only
	int user_limit; // voice only
	D_user_t * recipients;
	char * icon;
	SNOWFLAKE owner_id;
	SNOWFLAKE application_id;
	SNOWFLAKE parent_id;
	
	int Nrecipients;
} ld_chan_t;

#endif // ifndef __CISCORD_CHANNEL_H__
