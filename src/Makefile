DIRS=libtests.a libdaemon.a libpulse.a  #libpulsecore.a
LIBRARY=libpulsecommon.a
EXEC=main

INCLUDE=-I./ -I../ -I/home/aissy/temp/bashchroot/lib64/lib64/dbus-1.0/include -I/usr/include/dbus-1.0 \
	-I../avahi/  -I/usr/lib64/glib-2.0/include -I/usr/include/glib-2.0 -I/usr/include/gtk-3.0 -I/usr/include/pango-1.0 \
	-I/usr/include/harfbuzz -I/usr/include/cairo -I/usr/include/gdk-pixbuf-2.0 -I/usr/include/atk-1.0 \
	-I./pulse -I../soxr/src


CXXFLAGS=-I../ -DHAVE_CONFIG_H=1

LIBRARIES_LINK=-ldbus-1 -lsystemd   \
	  -lm   -lpulsecommon -lspeexdsp   -lxcb -lasyncns

all:$(EXEC) 
$(DIRS):
	make -C $(shell bash getlibname $@) COMPILE_ONLY=1
$(LIBRARY): $(DIRS)
	ar rcs $(LIBRARY) daemon/*.o pulse/*.o pulsecore/*.o utils/*.o 
$(EXEC): $(LIBRARY)
	gcc  $@.c $(INCLUDE) -L./ $(LIBRARIES_LINK) $(CXXFLAGS) -o $@

clean_lib: 
	rm -rf $(LIBRARY)
clean:
	rm -rf daemon/*.o tests/*.o pulse/*.o $(DIRS) $(LIBRARY)
