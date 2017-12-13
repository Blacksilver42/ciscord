.PHONY: dev build clean

OBJS = helpers.o msg.o init.o exbot.o

CURLLINK = -L/usr/lib/x86_64-linux-gnu -lcurl
LDFLAGS = $(CURLLINK)

build: exbot

dev: CFLAGS=-g
dev: build


exbot: $(OBJS)
	gcc $(OBJS) -o exbot $(CFLAGS) $(LDFLAGS)


clean:
	rm -f *.o

