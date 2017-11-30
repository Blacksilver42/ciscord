#ifdef __CISCORD_H__

#warn "ciscord.h included multiple times. DON'T PANIC -- we used an include gaurd"

#else

#define __CISCORD_H__


///////////////////////////////////////////////// <INCLUDES>

#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <curl/curl.h>
#include <errno.h>
#include <stdbool.h>

///////////////////////////////////////////////// "INCLUDES"

#include "typedef.h"





///////////////////////////////////////////////// FUNCTIONS



guild_t *	findguild_name(guild_t * buf, const char * name);
guild_t *	findguild_id(guild_t * buf, const char * id);

chan_t *	findchan_name(chan_t * buf, const char * name);
chan_t *	findchan_id(chan_t * buf, char * id);


// Various send-message commands: ---------------------------------------------
//			func		context,		user,		content
extern int	send(		ctx_t * ctx,				msg_t msg );
extern int 	reply(		ctx_t * ctx, 	user_t usr,	msg_t msg );
extern int	sendf(		ctx_t * ctx,				const char * format, ... );
extern int 	replyf(		ctx_t * ctx,	user_t usr,	const char * format, ... );
extern int	send_embed(	ctx_t * ctx,				const embed_t * embed );

// event-listner-adders -------------------------------------------------------
void		onrecv_any(listener_t listener);
void 		onrecv_rgx(char * regex, listener_t listener);

// helper functions -----------------------------------------------------------
char *		find_key(int argc, char * argv[]);





///////////////////////////////////////////////// VARS


listen_t * LISTENERS[];




#endif // ifndef __CISCORD_H__
