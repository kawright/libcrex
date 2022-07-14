/*
Write "Hello, world" to stdout.

This will test basic str and io functionality.
*/

#include "../src/crex.h"
#include <assert.h>

int main(int argc, char *argv[]) {
    rex_Str     hello;
    assert(rex_strnew("Hello, world!\n", &hello) == rex_ERROK);
    assert(rex_printstr(hello) == rex_ERROK);
    assert(rex_strdel(hello) == rex_ERROK);
    return 0;
}