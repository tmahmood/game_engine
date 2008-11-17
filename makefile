CC=g++
CFLAGS=-c -Wall -g
LDFLAGS=-g
SOURCES=src/tester.cpp src/file_helper.cc src/string_helper.cc src/string_tokenizer.cc src/map.cc
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=bin/game_engine

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

