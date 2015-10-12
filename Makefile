IMPL_CFLAGS = -std=c++11 -D_XOPEN_SOURCE=600 \
		-D_DEFAULT_SOURCE \
		-pipe \
		-g \
		-pedantic \
		-Wall \
		-W \
		-Wno-sign-compare \
		-Wno-unused-parameter

LIBS = -lGL -lepoxy -llog4cpp

CFLAGS = `pkg-config --libs --cflags gtk+-3.0` ${IMPL_CFLAGS} ${LIBS} 

cube: cube.o Logger.o AdminBase.o OpenGLApplication.o OpenGLManager.o OpenGLProgram.o AbstractOpenGLProgram.o interface.ui.xml
	g++ ${CFLAGS} -o cube cube.o Logger.o AdminBase.o OpenGLApplication.o OpenGLManager.o OpenGLProgram.o AbstractOpenGLProgram.o

cube.o: cube.cc
	g++ cube.cc ${CFLAGS} -c

OpenGLApplication.o: OpenGLApplication.cc OpenGLApplication.h OpenGLProgram.o OpenGLManager.o AdminBase.o
	g++ OpenGLApplication.cc ${CFLAGS} -c

OpenGLProgram.o: OpenGLProgram.cc OpenGLProgram.h AbstractOpenGLProgram.o IOpenGLProgram.h IObject.h AdminBase.o
	g++ OpenGLProgram.cc ${CFLAGS} -c

OpenGLManager.o: OpenGLManager.cc OpenGLManager.h AdminBase.o
	g++ OpenGLManager.cc ${CFLAGS} -c

Square: Square.cc Square.h IObject.h IModel.h DataStructures.h OpenGLProgram.o
	g++ Square.cc ${CFLAGS} -c

SquareModel: SquareModel.cc SquareModel.h IModel.h
	g++ SquareModel.cc ${CFLAGS} -c

AbstractOpenGLProgram.o: AbstractOpenGLProgram.cc AbstractOpenGLProgram.h IOpenGLProgram.h AdminBase.o
	g++ AbstractOpenGLProgram.cc ${CFLAGS} -c

AdminBase.o: AdminBase.cc AdminBase.h
	g++ AdminBase.cc ${CFLAGS} -c

Logger.o: Logger.h Logger.cpp
	g++ Logger.cpp ${CFLAGS} -c

clean:
	rm -f cube cube.o *.o *.*~

