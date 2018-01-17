.PHONY: dev build clean

OBJS = 

CURLLINK = -L/usr/lib/x86_64-linux-gnu -lcurl
LDFLAGS = $(CURLLINK) -ljsmn
CFLAGS = -Wall 

build: exbot

dev: CFLAGS+=-g
dev: build


exbot: $(OBJS) *.h
	gcc $(OBJS) -o exbot $(CFLAGS) $(LDFLAGS)


clean:
	rm -f *.o

