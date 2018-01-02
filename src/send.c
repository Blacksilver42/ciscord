#include "ciscord.h"


int Dsend(CDIS cdis, ctx_t * ctx, DMSG msg){
	printf("[%s] #%s\t> %s\n",ctx->guild->name, ctx->chan->name, msg);
}
