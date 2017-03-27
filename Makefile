INSTALL=/lib

CFLAGS+= -Wall
LDFLAGS+= -lc -ldl 

all: libnvidia-ml.so

libnvidia-ml.so: nvml.h nvml.c
	$(CC) -fPIC -shared -D_GNU_SOURCE $(CFLAGS) $(LDFLAGS) nvml.h nvml.c -o libnvidia-ml.so
	strip libnvidia-ml.so

clean:
	rm  libnvidia-ml.so nv.tar.gz

install: all
	rm -rf /usr/lib64/libnvidia-ml.so.1
	cp libnvidia-ml.so /usr/lib64/libnvidia-ml.so.1

uninstall: 
	rm -rf /usr/lib64/libnvidia-ml.so.1
	ln -s /usr/lib64/libnvidia-ml.so.346.46 /usr/lib64/libnvidia-ml.so.1
	#ln -s /usr/lib64/libnvidia-ml.so.352.39 /usr/lib64/libnvidia-ml.so.1

tar: nvml.h nvml.c Makefile
	mkdir nv
	cp nvml.c nvml.h Makefile nv
	tar czvf nv.tar.gz nv
	rm -rf nv
