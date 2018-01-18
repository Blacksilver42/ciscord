INCLUDE = /usr/include
LN=ln -f
MKDIR= sudo mkdir

i = $(INCLUDE)/ciscord

.PHONY: hdrs cleanh


headers = $i/exit.h $i/guild.h $i/channel.h $i/simples.h $i/internal.h $i/internal/
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

.ONESHELL:
$i/:
	$(MKDIR) -p $@
	$(MAKE) $(headers)

$i/internal/:
	$(MKDIR) -p $@
	$(MAKE) $(internalh)

/usr/include/ciscord/%.h: src/%.h
	sudo cp $< $@

jsmn/jsmn.a:
	git clone http://github.com/zserge/jsmn	
	$(MAKE) -C jsmn/
