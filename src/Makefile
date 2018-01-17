.PHONY: dev build clean

OBJS = log.o

CURLLINK = -L/usr/lib/x86_64-linux-gnu -lcurl
LDFLAGS = $(CURLLINK) -ljsmn
CFLAGS = -Wall 

build: $(OBJS)

dev: CFLAGS+=-g
dev: build


clean:
	rm -f *.o

