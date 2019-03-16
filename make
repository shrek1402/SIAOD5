CC=g++
CFLAGS=-c
LDFLAGS=
SOURCES=Сиаод3\сиаод3.cpp Сиаод3\pch.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=Geometry

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(CFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *.o Geometry
