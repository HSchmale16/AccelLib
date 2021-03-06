CC=g++
CFLAGS=
LDFLAGS=
HEADERS=AccelLib.h
SOURCES=AccelLib.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXE=HolidayLights
ARDUINO_BUILD_DIR=AccelLib/
ARDUINO_ZIP=arduino.zip
ARDUINO_EX_PATH=Examples/Arduino/*


all: arduino

# creates an arduino library 
arduino:
	mkdir $(ARDUINO_BUILD_DIR)
	# copy files to arduino build dir
	cp $(SOURCES) $(ARDUINO_BUILD_DIR)
	cp $(HEADERS) $(ARDUINO_BUILD_DIR)
	cp -r $(ARDUINO_EX_PATH) $(ARDUINO_BUILD_DIR)/Examples
	# zip that directory
	zip -r $(ARDUINO_ZIP) $(ARDUINO_BUILD_DIR)
	# perform clean up
	rm -rf $(ARDUINO_BUILD_DIR)

# Stuff to allow lib to be built for platforms other than arduino
$(EXE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@
	
.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	if [ -e $(EXE) ] ; then rm $(EXE); fi
	rm -rf *.o
	rm -rf src/*.o

