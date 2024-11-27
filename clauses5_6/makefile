# Compiler
CC = gcc

# Compiler flags
CFLAGS = -g -std=c11 -Wall

## Input Parameters
#VERTICES=5000
#EDGES=10000
#SEED=44

# Valgrind flags
VALGRIND_MEMCHECK_FLAGS=--tool=memcheck -v --leak-check=full --show-leak-kinds=all  --error-exitcode=99

MAKE_VALGRIND_GDB=valgrind --vgdb=yes --vgdb-error=0

#VALGRIND_CALLGRIND_FLAGS=--tool=callgrind -v --error-exitcode=99

# Source files
SRCS = hello.c

# Object files
OBJS = $(SRCS:.c=.o)

# Executable name
TARGET = hello

# Default target
all: $(TARGET)

valgrind_gdb: $(TARGET)
	valgrind --leak-check=full --vgdb=yes --vgdb-error=0 ./$(TARGET)
# to run valgrind with memcheck tool
valgrind: $(TARGET)
	valgrind --leak-check=full -s --track-origins=yes --show-leak-kinds=all  --error-exitcode=99 ./$(TARGET)


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
.PHONY: all clean valgrind valgrind_callGraph