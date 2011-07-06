#create the ll object file first
gcc -fPIC -g -c -Wall utl/ll.c
gcc -fPIC -g -c -Wall utl/heap.c
gcc -fPIC -g -c -Wall utl/hash.c
gcc -fPIC -g -c -Wall utl/bst.c

#Now create shared object (library)
gcc -shared -o lib/liblinkedlist.so ll.o 
gcc -shared -o lib/libheap.so heap.o 
gcc -shared -o lib/libhash.so hash.o 
gcc -shared -o lib/libbst.so bst.o 

#compile any code and link with library
gcc -g src/llcaller.c -o  bin/llcaller -L`pwd`/lib/ -llinkedlist
gcc -g src/heapcaller.c -o  bin/heapcaller -L`pwd`/lib/ -lheap -llinkedlist
gcc -g src/hashcaller.c -o  bin/hashcaller -L`pwd`/lib/ -lheap -llinkedlist -lhash -lbst
gcc -g src/bstcaller.c -o  bin/bstcaller -L`pwd`/lib/ -lbst

#Dont forget to keep LIB path in env variable 
export LD_LIBRARY_PATH=/scratch/flicktest/lib/

