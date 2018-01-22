INCLUDE = /usr/include
LN=ln -f
MKDIR= sudo mkdir

CURLLINK = $(shell curl-config --libs)

i = $(INCLUDE)/ciscord

.PHONY: clean cleano cleanh
.PHONY: install headers dbg


libciscord.a: $i/ src/*.c
	$(MAKE) -C src CFLAGS=$(CFLAGS)
	cp src/libciscord.a .

dbg: CFLAGS=-g
dbg: libciscord.a

headers: $i/

clean: cleano cleanh

test: libciscord.a test.c
	$(CC) $(CFLAGS) test.c -o test -L. -lciscord $(CURLLINK)


$i/: headers/*.h headers/internal/*.h
	sudo cp -r headers $i/


jsmn/jsmn.a:
	git clone http://github.com/zserge/jsmn	
	$(MAKE) -C jsmn/

$i/ciscord/%.h: headers/%.h 
	sudo cp $< $@


cleano:
	@$(MAKE) -C src clean

cleanh:
	sudo rm -rf /usr/include/ciscord/

