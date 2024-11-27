# Compiler
CC = gcc
# Compiler flags
CFLAGS = -g -std=c11 -Wall

# Valgrind flags
VALGRIND_MEMCHECK_FLAGS=--tool=memcheck -v --leak-check=full --show-leak-kinds=all  --error-exitcode=99

# Source files
SRCS = race.c

# Object files
OBJS = $(SRCS:.c=.o)

# Executable name
TARGET = race

# Default target
all: $(TARGET)

# to run valgrind with memcheck tool
valgrind: $(TARGET)
	valgrind --leak-check=full -s --track-origins=yes --show-leak-kinds=all  --error-exitcode=99 ./$(TARGET)

valgrind_helgrind: $(TARGET)
	valgrind --tool=helgrind --log-file=helgrind_report.txt ./$(TARGET)

# Link object files to create the executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Compile source files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -f $(OBJS) $(TARGET)

# Phony targets
.PHONY: all clean valgrind