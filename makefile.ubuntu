CC=g++
CFLAGS=-c -Wall -std=c++11
LDFLAGS=-lm -lstdc++
SOURCES=main.cpp polyominoes.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=polyominoes

all: $(SOURCES) $(EXECUTABLE)
    
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm *.o *.exe
