CC=g++
CFLAGS=-c -Wall -g
LDFLAGS=-g -Wall
SOURCES=src/tester.cpp src/helpers/file_helper.cc src/helpers/string_helper.cc src/helpers/string_tokenizer.cc src/map.cc src/point.cc
OBJECTS=$(SOURCES:.cpp=.o) 
EXECUTABLE=bin/game_engine

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

