# Vikas Scientific Library Makefile
# Simple and clean

# Compiler and flags
CC = gcc
CFLAGS = -Wall -O3 -march=native
AR = ar
ARFLAGS = rcs

# Directories
SRC_DIR = src
INCLUDE_DIR = include

# Library name
LIB = libvsl.a

# Source files (all .c files in src/)
SRCS = $(wildcard $(SRC_DIR)/*.c)

# Object files (replace .c with .o)
OBJS = $(SRCS:.c=.o)

# Default target: build the library
all: $(LIB)

# Build the library from object files
$(LIB): $(OBJS)
	@echo "Creating library $@..."
	$(AR) $(ARFLAGS) $@ $^
	@echo "✓ Build successful!"
	@echo "Library: $(LIB)"

# Compile each .c file to .o
%.o: %.c
	@echo "Compiling $<..."
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

# Clean build artifacts
clean:
	@echo "Cleaning..."
	rm -f $(OBJS) $(LIB)
	@echo "✓ Clean complete"

# Rebuild everything from scratch
rebuild: clean all

# Show help
help:
	@echo "VSL Makefile Commands:"
	@echo "  make          - Build the library"
	@echo "  make clean    - Remove build artifacts"
	@echo "  make rebuild  - Clean and rebuild"
	@echo "  make help     - Show this help"

# Phony targets (not actual files)
.PHONY: all clean rebuild help
