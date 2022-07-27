DIRS=libtests.a libdaemon.a libpulse.a 
LIBRARY=libpulsecommon.a
EXEC=main

LIBRARIES_LINK=-ldbus-1 -lsystemd   -lpulsecore \
	  -lm   -lpulsecommon -lspeexdsp -lpulsecore   -lxcb -lasyncns

all:$(EXEC) 
$(DIRS):
	make -C $(shell getlibname $@) COMPILE_ONLY=1
$(LIBRARY):
	ar rcs $(LIBRARY) daemon/*.o pulse/*.o pulsecore/*.o utils/*.o 
$(EXEC): $(DIRS) $(LIBRARY)
	gcc  $@.c -I./ -L./ $(LIBRARIES_LINK) -o $@

clean:
	rm -rf daemon/*.o tests/*.o pulse/*.o $(DIRS) $(LIBRARY)
