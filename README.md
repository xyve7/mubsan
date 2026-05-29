# mubsan

Minimal implementation of UBSAN, which can be utilized inside freestanding environments.

## Note

**Not all of the handlers are implemented, only the major ones.**

To test the project on Linux or macOS, clone the repository and run.

```bash
$ make
$ ./mubsantest
mubsan @ test.c:21:8: array out of bounds, for type 'int [4]', by index type 'int' 4
```

## Usage

Statically link the `mubsan.c` file with your existing project.  
Then, define a function with the following signature:

```c
int mubsan_log(const char* format, ...) {
    // code
}
```

This function should work like `printf`.


## Dependencies

`mubsan.c` depends on `stdint.h`.

## Credit

So, finding documentation for this was pretty abysmal, so I had to utilize other implementations and using them as reference.  
However, the only main reference I even used was GCC itself, however, I'll credit the others that I viewed anyways.

[OSDev Wiki Page on UBSAN](https://wiki.osdev.org/Undefined_Behavior_Sanitization)  
[GCC Mirror](https://github.com/gcc-mirror/gcc/blob/master/libsanitizer/ubsan/ubsan_handlers.cpp)  
[Sortix](https://gitlab.com/sortix/sortix/blob/master/libc/ubsan/ubsan.c)  
[optee_os](https://github.com/OP-TEE/optee_os/blob/master/core/kernel/ubsan.c)  
[tinyubsan](https://github.com/Abb1x/tinyubsan/blob/master/src/tinyubsan.c)  
[barebones](https://github.com/fwsGonzo/barebones/blob/abb810ef9437af015d19de4d60dae1ad0d637eec/src/crt/ubsan.c)  
[dgos](https://github.com/doug65536/dgos/blob/3f27fb17727a3e6dd8ba3aca5043e2f41d537bfd/kernel/lib/ubsan.cc)
