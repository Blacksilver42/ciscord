#include "ciscord.h"


int Dsend(ctx_t * ctx, msg_t msg){
	printf("[%s] #%s\t> %s\n",ctx->guild.name, ctx->chan.name, msg);
}
