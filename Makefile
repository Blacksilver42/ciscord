: ciscord.o

dev: ciscord-dev.o

exbot:
	gcc exbot/*.c -o exbot 

clean:
	rm -rf *.o 

ciscord.o: src/*.c src/*.h
	gcc src/*.c -c -o ciscord.o

ciscord-dev.o:
	gcc src/*.c -c -o ciscord-dev.o -DCISCORD_DEV
	
