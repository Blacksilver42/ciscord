// vim: ts=4

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


CDIS		cdis_init(CDIS cdis);

guild_t *	Dfind_guild_name(CDIS cdis,	guild_t * buf, const char * name);
guild_t *	Dfind_guild_id(	CDIS cdis,	guild_t * buf, const char * id);

chan_t *	Dfind_chan_name(	CDIS cdis,	chan_t * buf, const char * name);
chan_t *	Dfind_chan_id(	CDIS cdis,	chan_t * buf, char * id);


// Various send-message commands ----------------------------------------------
//		func		cdis		context,		user,		content
int		Dsend(		CDIS cdis,	ctx_t * ctx,				DMSG msg );
int		Dsendf(		CDIS cdis,	ctx_t * ctx,				const char * format, ... );

int 	Dreply(		CDIS cdis,	ctx_t * ctx, 	user_t usr,	DMSG msg );
int 	Dreplyf(	CDIS cdis,	ctx_t * ctx,	user_t usr,	const char * format, ... );

int		Dsend_embed(CDIS cdis,	ctx_t * ctx,				const embed_t * embed );


// event-listner-adders -------------------------------------------------------
void	Donrecv_any(listen_f L);
void 	Donrecv_rgx(char * regex, listen_f L);


// helper functions -----------------------------------------------------------
char *	find_key(int argc, char * argv[]);
ctx_t *	makectx(ctx_t * buf, guild_t * guild, chan_t * chan);
CURL *	ciscord_get_curl_handle(CDIS cdis);

// control functions ----------------------------------------------------------
char *	Dkey(CDIS cdis, char * buf);

/******************************************************************************
                                     VARS
 *****************************************************************************/


extern listen_f * LISTENERS[CDIS_MAX_LISTEN];



#endif // ifndef __CISCORD_H__
