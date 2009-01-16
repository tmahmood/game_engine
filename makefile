CC=g++
CFLAGS=-c -Wall -g
LDFLAGS=-g -Wall
SDLFLAG=`sdl-config --cflags --libs` -lSDL_image
EXECUTABLE=bin/game_engine

game_engine: main string_helper string_tokenizer file_helper sdl object vehical
	g++ obj/main.o obj/string_helper.o obj/string_tokenizer.o obj/file_helper.o obj/sdl_dm.o obj/object.o obj/vehical.o $(SDLFLAG) $(LDFLAGS) -o$(EXECUTABLE)

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


clean:
	rm obj/*.o
	rm bin/game_engine

