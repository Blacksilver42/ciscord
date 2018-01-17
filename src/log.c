#include <ciscord/internal.h>

FILE * ld_log_file = stderr;

extern void ld_log_stream(FILE * stream){
	ld_log_file = stream;
}


extern void ld_log_info(const char * format, ...){
	va_list ap;
	va_start(format, ap);
	fprintf(ld_log_file, "[LD/INFO] ");
	vfprintf(ld_log_file, ap);
	va_end ap;
}

extern void ld_log_warn(const char * format, ...){
	va_list ap;
	va_start(format, ap);
	fprintf(ld_log_file, "[LD/WARN] ");
	vfprintf(ld_log_file, ap);
	va_end ap;
}

extern void ld_log_fuck(const char * format, ...){
	va_list ap;
	va_start(format, ap);
	fprintf(ld_log_file, "[LD/FUCK] ");
	vfprintf(ld_log_file, ap);
	va_end ap;
}

