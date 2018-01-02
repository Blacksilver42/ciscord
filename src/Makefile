.PHONY: dev build clean

OBJS = helpers.o log.o control.o find.o send.o recv.o init.o exbot.o

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

