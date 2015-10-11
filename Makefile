IMPL_CFLAGS = -std=c++11 -D_XOPEN_SOURCE=600 \
		-D_DEFAULT_SOURCE \
		-pipe \
		-g \
		-pedantic \
		-Wall \
		-W \
		-Wmissing-prototypes \
		-Wno-sign-compare \
		-Wno-unused-parameter

LIBS = -lGL -lepoxy

CFLAGS = `pkg-config --libs --cflags gtk+-3.0` ${IMPL_CFLAGS} ${LIBS} 

cube: cube.o interface.ui.xml
	g++ ${CFLAGS} -o cube cube.o

cube.o: cube.cc
	g++ cube.cc ${CFLAGS} -c

clean:
	rm -f cube cube.o

