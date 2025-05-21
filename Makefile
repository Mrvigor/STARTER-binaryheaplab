# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -std=c++17 -g

# Target executable
TARGET = examheap

# Source files
SRCS = examheap.cpp heap.cpp
OBJS = $(SRCS:.cpp=.o)

# Default rule
all: $(TARGET)

# Link object files to create the final executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile each .cpp file to .o
%.o: %.cpp heap.h
	$(CXX) $(CXXFLAGS) -c $<

# Clean up build files
clean:
	rm -f $(TARGET) *.o