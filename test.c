#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

int mubsan_log(const char* format, ...) {
    va_list args;
    va_start(args, format);

    fprintf(stderr, "mubsan: ");
    vfprintf(stderr, format, args);

    va_end(args);

    exit(1);
}

int main() {
    int arr[4] = {1, 2, 3, 4};
    arr[4] = 10;
}
