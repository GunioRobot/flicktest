CC=gcc
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=parsechar.c 
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=parsechar

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@



