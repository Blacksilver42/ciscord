
#ifdef __CISCORD_H__

//#warn "ciscord.h included multiple times. DON'T PANIC -- we used an include gaurd"

#else

#define __CISCORD_H__

///////////////////////////////////////////////// MACROS


#define CDIS_STR_LEN (sizeof(char)*64)

#define CDIS_SNOWFLAKE_LEN (sizeof(char)*64)

#ifndef CDIS_MAX_LISTEN
#define CDIS_MAX_LISTEN 32
#endif


#define CDIS_VSTRING "v0.01"
#define CDIS_VNOTE   "(NON-FUNCTIONAL)"

#define CDIS ciscord_t*

///////////////////////////////////////////////// <INCLUDES>

#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <curl/curl.h>
#include <errno.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>

///////////////////////////////////////////////// "INCLUDES"

#include <ciscord/simples.h>
#include <ciscord/channel.h>
#include <ciscord/guild.h>
#include <ciscord/exit.h>

#include <ciscord/typedef.h>



/******************************************************************************
                                   FUNCTIONS
 *****************************************************************************/


CDIS		ld_init(CDIS disC);
char *		ld_find_key(int argc, char * argv[]);
ctx_t *		ld_makectx(ctx_t * buf, guild_t * guild, chan_t * chan);



// D_series functions =========================================================
//			func			CDIS	context,		user,		content
int			D_send(			CDIS D,	ctx_t * ctx,				DMSG msg );
int			D_sendf(		CDIS D,	ctx_t * ctx,				const char* format, ... );
int 		D_reply(		CDIS D,	ctx_t * ctx,	user_t usr,	DMSG msg );
int 		D_replyf(		CDIS D,	ctx_t * ctx,	user_t usr,	const char * format, ... );
int			D_send_embed(	CDIS D,	ctx_t * ctx,				const embed_t * embed );
// event-listner-adders
void		D_onrecv_any(	CDIS D,	listen_f L);
void 		D_onrecv_rgx(	CDIS D, const char * regex, listen_f L);
void		D_onrecv_sls(	CDIS D, listen_f L);
// control functions
char *		D_key(			CDIS D, char * key);
// finders
guild_t *	D_get_guild(	CDIS D,	guild_t * buf,	const char * id);
chan_t *	D_get_chan(		CDIS D,	chan_t * buf,	const char * name);





#endif // ifndef __CISCORD_H__

// vim: syntax=c ts=4
