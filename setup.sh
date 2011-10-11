#create the ll object file first
gcc -fPIC -g -c -Wall utl/ll.c
gcc -fPIC -g -c -Wall utl/heap.c
gcc -fPIC -g -c -Wall utl/hash.c
gcc -fPIC -g -c -Wall utl/bst.c
gcc -fPIC -g -c -Wall utl/bsearch.c

#Now create shared object (library)
gcc -shared -o lib/liblinkedlist.so ll.o 
gcc -shared -o lib/libheap.so heap.o 
gcc -shared -o lib/libhash.so hash.o 
gcc -shared -o lib/libbst.so bst.o 
gcc -shared -o lib/libbsearch.so bsearch.o 

#compile any code and link with library
gcc -g src/llcaller.c -o  bin/llcaller -L`pwd`/lib/ -llinkedlist
gcc -g src/heapcaller.c -o  bin/heapcaller -L`pwd`/lib/ -lheap -llinkedlist
gcc -g src/hashcaller.c -o  bin/hashcaller -L`pwd`/lib/ -lheap -llinkedlist -lhash -lbst
gcc -g src/bstcaller.c -o  bin/bstcaller -L`pwd`/lib/ -lbst
gcc -g src/bstinorder.c -o  bin/bstinorder -L`pwd`/lib/ -lbst
gcc -g src/bcaller.c -o  bin/bcaller -L`pwd`/lib/ -lbsearch

#random code
gcc -g src/findcomplement.c -o  bin/findcomplement -L`pwd`/lib/ -lhash -lbst -llinkedlist
gcc -g src/countsetbits.c -o  bin/countsetbits  
gcc -g src/startserver.c -o  bin/startserver
gcc -g src/startclient.c -o  bin/startclient
gcc -g src/newchild.c -o  bin/newchild

#Dont forget to keep LIB path in env variable 
export LD_LIBRARY_PATH=/scratch/flicktest/lib/

