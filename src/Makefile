.PHONY: dev build clean

OBJS = log.o channel.o curl_helpers.o

CURLLINK = $(shell curl-config --libs)
LDFLAGS = $(CURLLINK) -L../jsmn -ljsmn
CFLAGS = -Wall -Wextra -Wpedantic

libciscord.a: $(OBJS)
	$(AR) rc $@ $^
	

dev: CFLAGS+=-g
def: libciscord.a


clean:
	rm -rf *.o
	rm -rf *.a

channel.c: curl_helpers.c
