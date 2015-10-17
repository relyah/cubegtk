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

cube: cube.o Logger.o AdminBase.o OpenGLApplication.o OpenGLManager.o OpenGLProgram.o AbstractOpenGLProgram.o Square.o Camera.o SquareModel.o InputManager.o AbstractObject.o interface.ui.xml
	g++ ${CFLAGS} -o cube cube.o Logger.o AdminBase.o OpenGLApplication.o OpenGLManager.o OpenGLProgram.o AbstractOpenGLProgram.o Square.o Camera.o SquareModel.o InputManager.o AbstractObject.o

cube.o: cube.cc
	g++ cube.cc ${CFLAGS} -c

OpenGLApplication.o: OpenGLApplication.cc OpenGLApplication.h IKeyReleasedListener.h
	g++ OpenGLApplication.cc ${CFLAGS} -c

OpenGLProgram.o: OpenGLProgram.cc OpenGLProgram.h IOpenGLProgram.h IObject.h
	g++ OpenGLProgram.cc ${CFLAGS} -c

OpenGLManager.o: OpenGLManager.cc OpenGLManager.h
	g++ OpenGLManager.cc ${CFLAGS} -c

Square.o: Square.cc Square.h IObject.h IModel.h DataStructures.h
	g++ Square.cc ${CFLAGS} -c

SquareModel.o: SquareModel.cc SquareModel.h IModel.h IKeyReleasedListener.h
	g++ SquareModel.cc ${CFLAGS} -c

Camera.o: Camera.cc Camera.h IOpenGLProgram.h IScrollListener.h
	g++ Camera.cc ${CFLAGS} -c

AbstractObject.o: AbstractObject.cc AbstractObject.h
	g++ AbstractObject.cc ${CFLAGS} -c

AbstractOpenGLProgram.o: AbstractOpenGLProgram.cc AbstractOpenGLProgram.h IOpenGLProgram.h
	g++ AbstractOpenGLProgram.cc ${CFLAGS} -c

AdminBase.o: AdminBase.cc AdminBase.h
	g++ AdminBase.cc ${CFLAGS} -c

InputManager.o: InputManager.cc InputManager.h
	g++ InputManager.cc ${CFLAGS} -c

Logger.o: Logger.h Logger.cpp
	g++ Logger.cpp ${CFLAGS} -c

clean:
	rm -f cube cube.o *.o *.*~

