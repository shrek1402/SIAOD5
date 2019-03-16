CC=g++
CFLAGS=-c
LDFLAGS=
SOURCES=сиаод3/сиаод3.cpp cиаод3/pch.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=siaod

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(CFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *.o Geometry
