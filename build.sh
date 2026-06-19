#!/bin/bash
set -e  # Exit on any error

# Parameters
CC=gcc
CFLAGS="-Wall -O2 -march=native"
LIB_NAME="libvsl.a"
SRC_DIR="src"

# Source files
SRC_DIR="src"
SOURCES=("$SRC_DIR"/*.c)
if [ ${#SOURCES[@]} -eq 0 ]; then
    print_error "No .c files found in ${SRC_DIR}"
    exit 1
fi

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
BLUE='\033[0;34m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

print_header(){
	echo -e "${BLUE}===> Building Vikas Scientific Library${NC}"
}

print_success(){
	echo -e "${GREEN}✓ $1${NC}"
}

print_error(){
	echo -e "${RED}✗ Error: $1${NC}"
}

print_info(){
	echo -e "${YELLOW}→ $1${NC}"
}

removeLibFile(){
	rm -f ${LIB_NAME}
	echo -e "${GREEN}Removed the library file${NC}"
}

build(){
	removeLibFile
    print_header
    print_info "Found ${#SOURCES[@]} source files"
    
    # Compile each source file
    OBJECTS=()
    for src in "${SOURCES[@]}"; do
        obj="${src}"       # Get filename (e.g., arrays.c)
        obj="${obj%.c}.o"      # Change extension to .o (e.g., arrays.o)
        
        print_info "Compiling ${src}..."
        
        if $CC $CFLAGS -c "$src" -I./include -o "$obj"; then
            OBJECTS+=("$obj")
        else
            print_error "Failed to compile $src"
            exit 1
        fi
    done
    
    # Create static library
    print_info "Creating library ${LIB_NAME}..."
    if ar rcs "$LIB_NAME" "${OBJECTS[@]}"; then
        # Get library size
        if command -v du &> /dev/null; then
            LIB_SIZE=$(du -h "$LIB_NAME" | cut -f1)
            print_info "Library size: ${LIB_SIZE}"
        fi
    else
        print_error "Failed to create library"
        exit 1
    fi
    
    # Clean up object files and show success message
    # print_info "Cleaning up object files..."
    #rm -f "${OBJECTS[@]}"
    #echo -e "${GREEN}===> Build Successful!${NC}"
}

build
