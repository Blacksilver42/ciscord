#ifndef __CISCORD_CHANNEL_H__
#define __CISCORD_CHANNEL_H__

#define CHANNEL_NAME_MAXLEN 100
#define CHANNEL_TOPIC_MAXLEN 1024

#include <ciscord/ciscord.h>

typedef struct {
	SNOWFLAKE id;
	char type[10];
	int allow, deny;
} ld_overwrite_t;

typedef struct {
	SNOWFLAKE id;
	int type;
	SNOWFLAKE guild_id;
	int position;
	ld_overwrite_t * permission_overwrites;
	char name[CHANNEL_NAME_MAXLEN+1];
	char topic[CHANNEL_TOPIC_MAXLEN+1];
	bool nsfw;
	SNOWFLAKE last_message_id;
	int bitrate; // voice only
	int user_limit; // voice only
	ld_user_t * recipients; // DM only
	char * icon;
	SNOWFLAKE owner_id;
	SNOWFLAKE application_id;
	SNOWFLAKE parent_id;
	struct tm last_pin_timestamp;
	
	int Nrecipients;
} ld_chan_t;


ld_chan_t *		ld_chan_blank(ld_chan_t * buf);
struct tm *		ld_convert_8601(struct tm * buf, char * stamp);
const char *	D_chan_perform(ld_t ld, SNOWFLAKE id){


#endif // ifndef __CISCORD_CHANNEL_H__
// vim: ts=4
