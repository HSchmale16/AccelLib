CC=g++
CFLAGS=
LDFLAGS=
HEADERS=AccelLib.hpp
SOURCES=AccelLib.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXE=HolidayLights
ARDUINO_BUILD_DIR=AccelLib/
ARDUINO_ZIP=arduino.zip

all: arduino

# creates an arduino library 
arduino:
	mkdir $(ARDUINO_BUILD_DIR)
	cp $(SOURCES) $(ARDUINO_BUILD_DIR)
	cp $(HEADERS) $(ARDUINO_BUILD_DIR)

# Stuff to allow lib to be built for platforms other than arduino
$(EXE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@
	
.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	if [ -e $(EXE) ] ; then rm $(EXE); fi
	rm -rf *.o
	rm -rf src/*.o

