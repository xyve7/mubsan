#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

int mubsan_log(const char* format, ...) {
    va_list args;
    va_start(args, format);

    vfprintf(stderr, format, args);

    va_end(args);

    exit(1);
}
__attribute__((nonnull)) void func(int* val) {
    (void)val;
}
int main() {
    _Bool* boolPtr;
    int value = 188;

    boolPtr = (_Bool*)&value; // Assign a non-zero value to a _Bool pointer

    // Print the value to avoid optimization
    printf("Bool value: %d\n", *boolPtr);
}
