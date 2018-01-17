#include <ciscord/ciscord.h>
#include <ciscord/internal.h>


void disC_log_info(const char * format, ...){
	va_list ap;
	va_start(ap,format);
	fprintf(stderr, "[CDIS/\e[2mINFO\e[0m] ");
	vfprintf(stderr, format, ap);
	va_end(ap);
}

void disC_log_warn(const char * format, ...){
	va_list ap;
	va_start(ap,format);
	fprintf(stderr, "[CDIS/\e[33mWARN\e[0m] ");
	vfprintf(stderr, format, ap);
	va_end(ap);
}

void disC_log_darn(const char * format, ...){
	va_list ap;
	va_start(ap,format);
	fprintf(stderr, "[CDIS/\e[31mDARN\e[0m] ");
	vfprintf(stderr, format, ap);
	va_end(ap);
}
