C=gcc
CFLAGS=-c
LDFLAGS= -Wall
SOURCES=poll_demo.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=pd
all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@ -lm

.c.o:
	$(CC) $(CFLAGS) $< -o $@

