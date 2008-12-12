CC=g++
CFLAGS=-c -Wall -g
LDFLAGS=-g -Wall
SDLFLAG=-lSDL

SOURCES=src/tester.cc src/helpers/file_helper.cc src/helpers/string_helper.cc src/helpers/string_tokenizer.cc src/map.cc src/sdl/sdl_dm.cc

OBJECTS=$(SOURCES:.cc=.o)

EXECUTABLE=bin/game_engine

all: $(SOURCES) $(EXECUTABLE)

	
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(SDLFLAG) $(OBJECTS) -o $@


clean:
	rm src/*.o
	rm src/helpers/*.o
	rm bin/game_engine
.cc.o:
	$(CC) $(CFLAGS) $(SDLFLAG) $< -o $@

