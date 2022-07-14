/*
This file contains the implementations of types and operations related to IO.
*/

#include <stdio.h>
#include <stdlib.h>
#include "./crex.h"

/*
Write an instance of `rex_str` to `stdout`.
*/
rex_Err rex_printstr(rex_Str instance) {
    char        *contents;
    rex_Err     err;
    err = rex_strgetcontent(instance, &contents);
    if (err == rex_ERRMEM) {
        return err;
    }
    printf("%s", contents);
    free(contents);
    return rex_ERROK;
}