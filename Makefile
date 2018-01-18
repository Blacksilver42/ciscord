INCLUDE = /usr/include
LN=ln -f
MKDIR= sudo mkdir

i = $(INCLUDE)/ciscord

.PHONY: hdrs cleanh


internalh = $i/internal/log.h $i/internal/curl_helpers.h

.PHONY: install include doth
.ONESHELL: include


ciscord.a: $i/
	$(MAKE) -C src
	cp src/ciscord.a .

clean: cleano cleanh

cleano:
	$(MAKE) -C src clean

cleanh:
	sudo rm -rf /usr/include/ciscord/

$i/: headers/* headers/internal/*
	sudo cp -r headers $i/

/usr/include/ciscord/%.h: src/%.h
	sudo cp $< $@

jsmn/jsmn.a:
	git clone http://github.com/zserge/jsmn	
	$(MAKE) -C jsmn/
