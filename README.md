# Malloc

School project where we had to recode the famous `malloc()` function.

This recode of malloc is thread safe.

The library is composed of:

* `malloc()`
* `free()`
* `realloc()`
* `calloc()`

Few more symbols are also in the library to inspect the allocated/freed memory blocks:

* `show_alloc_mem()`
* `show_alloc_mem_free()`
* `show_alloc_mem_all()`

You can generate the shared library using `make`.

You can run unit tests by getting in the tests folder and running `make tests`.

`assert()` function is recoded in order not to use `malloc()` via it's `printf()` call.