.PHONY: dev build clean

objs = helpers.o msg.o

build: ciscord.o

dev: CFLAGS=-g
dev: build

ciscord.o: $(objs)
	ld    -r -o ciscord.o $(objs)



helpers.o:	*.h  helpers.c
msg.o:		*.h  msg.c


clean:
	rm -f *.o
