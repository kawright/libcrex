/*
This file defines the entire public API for the `crex` framework for the C
programming language.
*/

////////////////////////////////////////////////////////////////////////////////
///////////////////////////// E N U M    T Y P E S /////////////////////////////
////////////////////////////////////////////////////////////////////////////////

/*
This enum type stores all possible return values for any `crex` function (with
the rare exception being functions which are not expected to return, such as
`rex_fatal`).

The member values also double as valid POSIX exit code which can be used
whenever an error signals a fatal condition.
*/
typedef enum rex_Err {

    // Success. No error occurred.
    rex_ERROK           =   0,

    // A general runtime error occurred.
    rex_ERRRUNTM        =   1,

    // An attempt to allocate heap memory failed.
    rex_ERRMEM          =   3,

    // A pointer to an unexpected type was found.
    rex_ERRTYPE         =   4,

    // Unexpected or malformed data was found.
    rex_ERRDATA         =   5,  

    // An out-of-bounds index was given.
    rex_ERRINDEX        =   6,

    // An undefined key was given.
    rex_ERRKEY          =   7,  

    // An arithemtic operation failed.
    rex_ERRARITH        =   8,  

    // An attempt to perform an IO operation failed.
    rex_ERRIO           =   9,  

    // An attempt to parse given data failed.
    rex_ERRPARSE        =   10, 

    // An operation timed out.
    rex_ERRTIMEOUT      =   11,

    // A socket error occurred.
    rex_ERRSOCK         =   12, 

    // An attempt to perform an illegal or unauthorized operation occurred.
    rex_ERRILLEGALOP    =   13, 

    // Skip a unit test for any reason.
    rex_ERRTESTSKIP     =   100,

    // Skip a unit test because it is a TODO item.
    rex_ERRTESTTODO     =   101,

    // Force a test to fail.
    rex_ERRTESTFORCE    =   102 

} rex_Err;

////////////////////////////////////////////////////////////////////////////////
/////////////////////////// O P A Q U E    T Y P E S ///////////////////////////
////////////////////////////////////////////////////////////////////////////////

/*
This opaque type stores a string of characters, and provides a helpful layer of
abstraction over C character arrays.
*/
typedef struct rex_Str *rex_Str;

////////////////////////////////////////////////////////////////////////////////
///////////////////////// S T R    O P E R A T I O N S /////////////////////////
////////////////////////////////////////////////////////////////////////////////

/*
Output the contents of a `rex_Str` instance.

Return `rex_ERRMEM` if memory for the output cannot be allocated.
*/
rex_Err rex_strgetcontent(rex_Str instance, char **out);

/*
Output the length of a `rex_Str` instance.
*/
rex_Err rex_strgetlen(rex_Str instance, int *out);

/*
Delete an instance of `rex_Str`.
*/
rex_Err rex_strdel(rex_Str instance);

/*
Output a new instance of `rex_Str` with given `contents`.

Return `rex_ERRMEM` if memory cannot be allocated for the output.
*/
rex_Err rex_strnew(char *content, rex_Str *out);

////////////////////////////////////////////////////////////////////////////////
////////////////////////// I O    O P E R A T I O N S //////////////////////////
////////////////////////////////////////////////////////////////////////////////

/*
Write an instance of `rex_str` to `stdout`.
*/
rex_Err rex_printstr(rex_Str instance);
