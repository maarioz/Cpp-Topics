CXX := clang++
CXXFLAGS := -std=c++17 -Wall -Wextra -pedantic -Wold-style-cast -Werror
INCL := -Iinclude
SRC_DIR := src
LDLIBS := -lSDL2 -lSDL2_image -lSDL2_mixer
SOURCES := $(shell find $(SRC_DIR) -type f -iregex ".*\.cpp")
OBJECTS := $(SOURCES:.cpp=.o)
TARGET := output

all: $(TARGET)

DEPS := $(patsubst %.o, %.d, $(OBJECTS))
-include $(DEPS)
DEPFLAGS = -MMD -MF $(@:.o=.d)

$(TARGET): $(OBJECTS)
	$(CXX) $(LDLIBS) $^ -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCL) -c $< -o $@ $(DEPFLAGS)

clean:
	rm $(OBJECTS) $(TARGET) $(DEPS)