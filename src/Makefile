all: common llcaller

common: 
	    gcc -c ll.o src/ll.c 
	    gcc -shared -o lib/libmylib.so  ll.o


llcaller: 
	    gcc -c llcaller.o src/llcaller.c 
	    gcc -o bin/llcaller src/llcaller.o -L./lib/ -lmylib 








