/*
This file contains the implementations of the `rex_Str` type, and all of its
related operations.
*/

#include <string.h>
#include <stdlib.h>
#include "./crex.h"

/*
This opaque type stores a string of characters, and provides a helpful layer of
abstraction over C character arrays.
*/
struct rex_Str {
    char    *content;
    int     len;
};

/*
Output the contents of a `rex_Str` instance.

Return `rex_ERRMEM` if memory for the output cannot be allocated.
*/
rex_Err rex_strgetcontent(rex_Str instance, char **out) {
    *out = strdup(instance->content);
    if (*out == NULL) {
        return rex_ERRMEM;
    }
    return rex_ERROK;
}

/*
Output the length of a `rex_Str` instance.
*/
rex_Err rex_strgetlen(rex_Str instance, int *out) {
    *out = instance->len;
    return rex_ERROK;
}

/*
Delete an instance of `rex_Str`.
*/
rex_Err rex_strdel(rex_Str instance) {
    free(instance->content);
    free(instance);
    return rex_ERROK;
}

/*
Output a new instance of `rex_Str` with given `content`.
*/
rex_Err rex_strnew(char *content, rex_Str *out) {

    // Allocate memory for the output:
    rex_Str outobj = malloc(sizeof(struct rex_Str));
    if (outobj == NULL) {
        return rex_ERRMEM;
    }

    // Assign attributes:
    outobj->content = strdup(content);
    if (outobj->content == NULL) {
        free(outobj);
        return rex_ERRMEM;
    }
    outobj->len = strlen(content);

    *out = outobj;
    return rex_ERROK;
}