# Compiler and Flags
CXX := g++
CXXFLAGS := -std=c++20

# Target and Source Files
TARGET := main
SOURCES := src/main.cpp src/Bus.cpp
HEADERS := src/Bus.hpp

DEFAULT_GOAL := run

run: compile
	./$(TARGET)

compile: $(TARGET)

$(TARGET): $(SOURCES) $(HEADERS)
	$(CXX) $(SOURCES) $(CXXFLAGS) -o $(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: run compile clean