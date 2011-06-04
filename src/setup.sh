#create the ll object file first
gcc -fPIC -g -c -Wall src/ll.c

#Now create shared object (library)
gcc -shared -o lib/liblinkedlist.so ll.o 

#compile any code and link with library
gcc src/llcaller.c -o bin/llcaller -L/scratch/flicktest/src/lib/ -llinkedlist

#Dont forget to keep LIB path in env variable 
export LD_LIBRARY_PATH=/scratch/flicktest/src/lib/:${LD_LIBRARY_PATH}



