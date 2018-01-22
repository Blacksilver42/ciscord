.PHONY: dev build clean

OBJS = log.o channel.o ld.o internal/curl_helpers.o

CURLLINK = $(shell curl-config --libs)
LDFLAGS = $(CURLLINK) -L../jsmn -ljsmn
CFLAGS = -Wall -Wextra -Wpedantic

libciscord.a: $(OBJS)
	$(AR) rc $@ $^
	

dev: CFLAGS+=-g
dev: libciscord.a


clean:
	rm -rf *.o internal/*.o
	rm -rf *.a

channel.c: internal/curl_helpers.c
