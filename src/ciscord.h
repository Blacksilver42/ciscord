#ifdef __CISCORD_H__

//#warn "ciscord.h included multiple times. DON'T PANIC -- we used an include gaurd"

#else

#define __CISCORD_H__

///////////////////////////////////////////////// MACROS

#ifndef MAXLSTN
#define MAXLSTN 32
#endif

#define CDIS_VSTRING "v0.01"
#define CDIS_VNOTE   "(NON-FUNCTIONAL)"

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

#include "typedef.h"





///////////////////////////////////////////////// FUNCTIONS


void		Dinit(void);
char *		Dfind_key(int argc, char * argv[]);

guild_t *	Dfindguild_name(guild_t * buf, const char * name);
guild_t *	Dfindguild_id(guild_t * buf, const char * id);

chan_t *	Dfindchan_name(chan_t * buf, const char * name);
chan_t *	Dfindchan_id(chan_t * buf, char * id);


// Various send-message commands: ---------------------------------------------
//			func		context,		user,		content
extern int	Dsend(		ctx_t * ctx,				msg_t msg );
extern int 	Dreply(		ctx_t * ctx, 	user_t usr,	msg_t msg );
extern int	Dsendf(		ctx_t * ctx,				const char * format, ... );
extern int 	Dreplyf(	ctx_t * ctx,	user_t usr,	const char * format, ... );
extern int	Dsend_embed(ctx_t * ctx,				const embed_t * embed );

// event-listner-adders -------------------------------------------------------
void		Donrecv_any(listen_f L);
void 		Donrecv_rgx(char * regex, listen_f L);

// helper functions -----------------------------------------------------------
char *		Dfind_key(int argc, char * argv[]);





///////////////////////////////////////////////// VARS


listen_f * LISTENERS[MAXLSTN];




#endif // ifndef __CISCORD_H__
