# mubsan

Minimal implementation of UBSAN, which can be utilized inside kernels.

## Note

**I understand some of the code is a bit repetitive and an eyesore, I'm currently thinking of ways to reduce the repetitive nature of the code, while also making sure it doesn't over complicated it**

This isn't complete yet, however if you want to test it, fork the repository and run:

```bash
$ make
```

## Usage

Statically link the `mubsan.c` file with your existing project.  
Then, define a function with the following signature:

```c
int mubsan_log(const char* format, ...) {
    // code
}
```

This function should accepting a formatted string and print it to the screen, however, how you implement it is up to you.

Running the test with the aforementioned instructions will yield this output, then exit:

```
mubsan @ test.c:21:8: array out of bounds, for type 'int [4]', by index type 'int' 4
```

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
