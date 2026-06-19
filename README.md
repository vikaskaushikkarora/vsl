# Vikas Scientific Library
A C library for scientific computation

## Library Contents
- **arrays**: Array manipulation functions
- **calculus**: Numerical calculus operations
- **inOut**: Input/output utilities
- **mathFunc**: Mathematical functions
- **matrix**: Matrix operations (basic)
- **random**: Random number generation
- **statistics**: Statistical functions

## Using the Library
### Include the header file
```
#include "all_headers.h"
int main() {
    long* arr = ar_Alloc(100);
    long* arr1 = ar_Alloc(100);
    // ... use library functions
    ar_Free(arr,arr1);
    return 0;
}
```
### Compile your program:
```bash
gcc main.c -L<vsl_directory_address> -I<vsl_directory_address>/include -lm -lpthread -lvsl -o a.out
./a.out
```

## Building

### build.sh
#### Make script executable (first time only)
```bash
chmod +x build.sh
```
#### Build the library
```bash
./build.sh
```

**Advantages:**
- Works everywhere bash is available
- No additional dependencies
- Simple and transparent

**Shortcomings:**
- Compiles the whole library from scratch
- Not easy while debugging and building the library

### Makefile
#### Commands
```bash
make
make clean
make rebuild
make help
```

**Advantages:**
- Standard thing to compile libraries
- Only compiles the changed modules

**Shortcomings:**
- Not simple
- Requires make to be installed

### Output
Both methods create: `libvsl.a`
