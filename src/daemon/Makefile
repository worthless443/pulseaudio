DIR=daemon
INCLUDE=-I../ -I../../ -I/home/aissy/temp/bashchroot/lib64/lib64/dbus-1.0/include -I/usr/include/dbus-1.0 \
	-I../../avahi/  -I/usr/lib64/glib-2.0/include -I/usr/include/glib-2.0 -I/usr/include/gtk-3.0 -I/usr/include/pango-1.0 \
	-I/usr/include/harfbuzz -I/usr/include/cairo -I/usr/include/gdk-pixbuf-2.0 -I/usr/include/atk-1.0 \
	-I../pulse -I../../soxr/src

LINK=-L../

LIBRARIES=-ldbus-1 -lsystemd          daemon/cmdline.o  pulse/rtclock.o  daemon/daemon-conf.o   -lpulsecore \
	  -lm   -lpulse  -lresampler -lspeexdsp -lpulsecore  

DEFS=-DHAVE_CONFIG_H=1
UTILS=$(shell ls *.c)
UTILS_OBJS=$(patsubst %.c,%.o,$(UTILS))
SHARED=../lib$(DIR).so
STATIC=../lib$(DIR).a
ifdef COMPILE_ONLY
all: $(UTILS_OBJS)
else
all: $(STATIC)
endif
$(UTILS_OBJS): %.o : %.c
	gcc -c $(INCLUDE) $(DEFS) $^ -o $@ -D_GNU_SOURCE=1
$(SHARED): $(UTILS_OBJS)
	gcc -shared -fPIE $^ -o $@
$(STATIC): $(UTILS_OBJS)
	ar rcs $@ $^
clean:
	rm -rf $(DIR)/*.o

