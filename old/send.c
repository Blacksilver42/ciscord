#include "ciscord.h"


int Dsend(CDIS disC, ctx_t * ctx, DMSG msg){
	printf("[%s] #%s\t> %s\n",ctx->guild->name, ctx->chan->name, msg);
}
