#Mike Brandin, CPSC 1021, April 7th, 2020

# Config
CC = g++
CFLAGS = -c -Wall -g
LFLAGS = -lm
TARGET = out


# Generate source and object lists
C_SRCS := \
	$(wildcard .cpp) \
	$(wildcard src/.cpp) \
	$(wildcard src//*.cpp)

HDRS := \
	$(wildcard .h) \
	$(wildcard src/.h) \
	$(wildcard src//*.h)

OBJS := $(patsubst %.cpp, bin/%.o, $(wildcard *.cpp))
OBJS += $(filter %.o, $(patsubst src/%.cpp, bin/%.o, $(C_SRCS)))
all: build
	@echo "All Done"
# Link all built objects
build: $(OBJS)
	$(CC) $(OBJS) -o $(TARGET) $(LFLAGS)
# Catch root directory src files
bin/%.o: %.cpp $(HDRS)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@
# Catch all nested directory files
bin/%.o: src/%.cpp $(HDRS)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f $(TARGET)
	rm -rf bin

run: build
	./$(TARGET) zoo.cpp
