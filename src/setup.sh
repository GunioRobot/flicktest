#create the ll object file first
gcc -fPIC -g -c -Wall utl/ll.c
gcc -fPIC -g -c -Wall utl/heap.c

#Now create shared object (library)
gcc -shared -o lib/liblinkedlist.so ll.o 
gcc -shared -o lib/libheap.so heap.o 

#compile any code and link with library
gcc src/llcaller.c -o bin/llcaller -L`pwd`/lib/ -llinkedlist
gcc src/heapcaller.c -o bin/heapcaller -L`pwd`/lib/ -lheap

#Dont forget to keep LIB path in env variable 
export LD_LIBRARY_PATH=/scratch/flicktest/src/lib/

