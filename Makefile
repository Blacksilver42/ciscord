INCLUDE = /usr/include
MAKE+= --no-print-directory
LN=ln -f

includedir = $(INCLUDE)/ciscord

.PHONY: install include doth
.ONESHELL: include


ciscord.o: doth
	make -C src
	cp src/ciscord.o .

doth: src/*.h
	@if [ `whoami` = root ]; then 
	mkdir -p $(includedir)
	$(LN) src/*.h $(includedir)/
	@else echo "Only root can do that."
	@#Seriously, you can try; it won't work.
	@exit 1; fi

jsmn/jsmn.a:
	git clone http://github.com/zserge/jsmn	
	make -C jsmn/
