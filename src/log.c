#include <ciscord/internal.h>
#include <stdio.h>
#include <stdarg.h>

FILE * ld_log_file = NULL;

extern void ld_log_stream(FILE * stream){
	ld_log_file = stream;
}


extern void ld_log_info(const char * format, ...){
	if(ld_log_file == NULL) ld_log_file = stdout;
	va_list ap;
	va_start(ap, format);
	fprintf(ld_log_file, "[LD/INFO] ");
	vfprintf(ld_log_file, format, ap);
	va_end(ap);
}

extern void ld_log_warn(const char * format, ...){
	if(ld_log_file == NULL) ld_log_file = stdout;
	va_list ap;
	va_start(ap, format);
	fprintf(ld_log_file, "[LD/WARN] ");
	vfprintf(ld_log_file, format, ap);
	va_end(ap);
}

extern void ld_log_fuck(const char * format, ...){
	if(ld_log_file == NULL) ld_log_file = stdout;
	va_list ap;
	va_start(ap, format);
	fprintf(ld_log_file, "[LD/FUCK] ");
	vfprintf(ld_log_file, format, ap);
	va_end(ap);
}

