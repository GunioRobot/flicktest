IDIR =../include
CC         = gcc
CFLAGS     = -c -Wall -I$(IDIR)
LDFLAGS    =
SOURCES    = parsechar.c
OBJECTS    = $(SOURCES:.c       = .o)
EXECUTABLE = parsechar

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
clean:
	rm -rf *o parsechar



