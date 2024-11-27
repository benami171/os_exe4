# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++14 -Wall -lgcov -fprofile-arcs -ftest-coverage

# Input Parameters
VERTICES=5000
EDGES=10000
SEED=44

# Valgrind flags
VALGRIND_MEMCHECK_FLAGS=--tool=memcheck -v --leak-check=full --show-leak-kinds=all  --error-exitcode=99

VALGRIND_CALLGRIND_FLAGS=--tool=callgrind -v --error-exitcode=99

# Source files
SRCS = Graph.cpp algo.cpp main.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Executable name
TARGET = main

# Default target
all: $(TARGET)

# to run valgrind with memcheck tool
valgrind: $(TARGET)
	valgrind $(VALGRIND_MEMCHECK_FLAGS) --log-file=memcheck_report.txt ./$(TARGET) -v $(VERTICES) -e $(EDGES) -s $(SEED)

# to run valgrind with callgrind tool
valgrind_callGraph: $(TARGET)
	valgrind $(VALGRIND_CALLGRIND_FLAGS) --tool=callgrind --log-file=callGraph_report.txt ./$(TARGET) -v $(VERTICES) -e $(EDGES) -s $(SEED)

# Link object files to create the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Compile source files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -f $(OBJS) $(TARGET) *.gcda *.gcno gmon.out *.gcov

# Phony targets
.PHONY: all clean