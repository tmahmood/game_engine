CC=g++
CFLAGS=-c -Wall -g
LDFLAGS=-g -Wall
SDLFLAG=`sdl-config --cflags --libs` -lSDL_image
PYFLAGS=-l python2.5
EXECUTABLE=../../bin/test

python_c: pyengine test_pyengine
	$(CC) ../../obj/pyengine.o $(LDFLAGS) $(PYFLAGS) -o$(EXECUTABLE)

test_pyengine:
	$(CC) -c pyengine_test.cc -o ../../obj/test_pyengine.o

pyengine:
	$(CC) $(CFLAGS) $(PYFLAGS) -c ../pyengine/pyengine.cc -o ../../obj/pyengine.o
