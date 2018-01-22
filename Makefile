INCLUDE = /usr/include
LN=ln -f
MKDIR= sudo mkdir

i = $(INCLUDE)/ciscord

.PHONY: clean cleano cleanh
.PHONY: install include headers


ciscord.a: $i/
	$(MAKE) -C src
	cp src/libciscord.a .

headers: $i/

clean: cleano cleanh

test: libciscord.a test.c
	$(CC) test.c -o test -L. -lciscord $(CFLAGS)


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

