OPENGLLIB= -lGL -lGLU
GLEWLIB= -lGLEW
GLFWLIB = -lglfw
GLFWDEP = -lX11 -lXxf86vm -lXrandr -lpthread -lXi
LIBS=$(OPENGLLIB) $(GLEWLIB) $(GLFWLIB)
LDFLAGS=-L/usr/local/lib 
CPPFLAGS=-I/usr/local/include

BIN=transformer
SRCS=transformer.cpp gl_framework.cpp draw_shapes.cpp robot.cpp load_texture.cpp
INCLUDES=gl_framework.hpp draw_shapes.hpp robot.hpp load_texture.hpp

all: $(BIN)

$(BIN): $(SRCS) $(INCLUDES)
	g++ $(CPPFLAGS) $(SRCS) -o $(BIN) $(LDFLAGS) $(LIBS)
clean:
	rm -f *~ *.o $(BIN) $(BIN)
