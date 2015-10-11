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

LIBS = -lGL -lepoxy -llog4cpp

CFLAGS = `pkg-config --libs --cflags gtk+-3.0` ${IMPL_CFLAGS} ${LIBS} 

cube: cube.o Logger.o AdminBase.o OpenGLApplication.o OpenGLManager.o interface.ui.xml
	g++ ${CFLAGS} -o cube cube.o Logger.o AdminBase.o OpenGLApplication.o OpenGLManager.o

cube.o: cube.cc
	g++ cube.cc ${CFLAGS} -c

OpenGLManager: OpenGLManager.cc OpenGLManager.h
	g++ OpenGLManager.cpp ${CFLAGS} -c

OpenGLApplication: OpenGLApplication.cc OpenGLApplication.h
	g++ OpenGLApplication.cpp ${CFLAGS} -c

AdminBase: AdminBase.cc AdminBase.h
	g++ AdminBase.cc ${CFLAGS} -c

Logger.o: Logger.h Logger.cpp
	g++ Logger.cpp ${CFLAGS} -c

clean:
	rm -f cube cube.o *.o *.*~

