# taken from here to start experimenting
# http://mrbook.org/blog/tutorials/make/

CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=main.cpp split.cpp permutate_vector.cpp compare.cpp hcat.cpp width.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=5-1

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm *.o

debug:
	g++ -Wall main_dbg_friendly.cpp split.cpp permutate_vector.cpp compare.cpp hcat.cpp width.cpp
