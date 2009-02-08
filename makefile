CC=g++
CFLAGS=-c -Wall -g
LDFLAGS=-g -Wall
SDLFLAG=`sdl-config --cflags --libs` -lSDL_image
PYFLAGS=-l python2.5
EXECUTABLE=bin/game_engine.a

game_engine: main string_helper string_tokenizer file_helper sdl object vehical timer ini_parser dictionary pyengine events
	g++ obj/main.o obj/string_helper.o obj/string_tokenizer.o obj/file_helper.o obj/sdl_dm.o obj/object.o obj/vehical.o obj/timer.o obj/ini_parser.o obj/dictionary.o obj/pyengine.o obj/event.o $(SDLFLAG) $(LDFLAGS) $(PYFLAGS) -o$(EXECUTABLE)

main:
	g++ $(CFLAGS) -c src/main.cc -oobj/main.o

string_helper:
	g++ $(CFLAGS) -c src/helpers/string_helper.cc -o obj/string_helper.o

string_tokenizer:
	g++ $(CFLAGS) -c src/helpers/string_tokenizer.cc -o obj/string_tokenizer.o

file_helper:
	g++ $(CFLAGS) -c src/helpers/file_helper.cc -o obj/file_helper.o

sdl:
	g++ $(CFLAGS) $(SDLFLAG) -c src/sdl/sdl_dm.cc -o obj/sdl_dm.o

vehical:
	g++ $(CFLAGS) $(SDLFLAG) -c src/objects/vehical.cc -o obj/vehical.o

object:
	g++ $(CFLAGS) $(SDLFLAG) -c src/objects/object.cc -o obj/object.o

timer:
	g++ $(CFLAGS) $(SDLFLAG) -c src/sdl/timer.cc -o obj/timer.o

ini_parser:
	g++ $(CFLAGS) $(SDLFLAG) -c src/ini_parser/iniparser.c -o obj/ini_parser.o

dictionary:
	g++ $(CFLAGS) $(SDLFLAG) -c src/ini_parser/dictionary.c -o obj/dictionary.o

pyengine:
	g++ $(CFLAGS) $(PYFLAGS) -c src/pyengine/pyengine.cc -o obj/pyengine.o

events:
	g++ $(CFLAGS) $(SDLFLAG) -c src/sdl/event.cc -o obj/event.o

clean:
	rm obj/*.o
	rm $(EXECUTABLE)

