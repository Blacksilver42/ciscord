#ifndef __CISCORD_H__
#define __CISCORD_H__

///////////////////////////////////////////////// MACROS


#define LD_VSTRING "v0.01"
#define LD_VNOTE   "(NON-FUNCTIONAL)"

///////////////////////////////////////////////// <INCLUDES>

#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <curl/curl.h>
#include <errno.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#define _XOPEN_SOURCE //strptime, struct tm
#include <time.h>


#include <ciscord/simples.h>

#include <ciscord/ld.h>
#include <ciscord/user.h>
#include <ciscord/channel.h>
#include <ciscord/guild.h>
#include <ciscord/exit.h>




#endif // ifndef __CISCORD_H__

// vim: syntax=c ts=4
