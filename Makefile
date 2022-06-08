TARGET = App

BIN_DIR = bin

CPPFILES = $(shell find src -type f -iname *.cpp)
OBJECTS = $(CPPFILES:%.cpp=%.o)

INCLUDES = -Iinclude $(shell pkg-config --cflags glfw3)
LIBS = -L./libs $(shell pkg-config --libs --static glfw3) -lGL -lGLU
CPPFLAGS = -Wall -Werror -Wextra $(INCLUDES) -O1
MV = mv

ifeq ($(BUILD), debug)
	CPPFLAGS += -O0 -g
else ifeq ($(BUILD), realase)
	CPPFLAGS += -O3 -s -DNDEBUG
endif

%.o: %.cpp
	$(CXX) $(CPPFLAGS) -c -o $@ $<

$(TARGET): $(OBJECTS)
	$(CXX) -o $@ $^ $(LIBS)

all: $(CPPFILES) $(OBJECTS)

.PHONY: $(BIN_DIR)

clean:
	$(RM)  $(TARGET) $(OBJECTS)
setup:
	mkdir -p include libs assets
