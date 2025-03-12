C is diffferent...

## -BOOLEAN-

Boolean is not a built in data type;
Expressions are given wither the values 1 for True or 0 for False
```C
    int a = (5 < 8);
    printf("%d", a); // 1
```

## -STRINGS-

Printf needs to be formatted with "format specifiers" like %d or %.01lf %c %s etc.
%p - prints pointers


```C
    int a = 4;
    printf("%d", a); // 4
```
    
fgets - retreives a line (string) from specifed stream. [fgets((string), (num of characters to read), (data stream, like stdin))];

```C
    char str[10];
    fgets(str, 10, stdin);
```
    
Strings are represented as "char string[n + 1]", where it is an array of characters length n + null terminator
When declaring a string, you do not need to input the size;

```C
    char str[] = "HELLO WORLD"; // is valid
    char str[11] = "HELLO WORLD"; // is not valid
```

'\0' is the null terminator, and implies that there is the strlen() + 1 length of string in memory.
The null terminator marks the end of a string.


### -PREPROCESSOR DIRECTIVES-
4 Main Types

> File Inclusion
```C
    #include <relative_file_path.h>
    #include "absolute/file/path.h"
```
> Macros
```C
    #define PI 3.14159 
    #define foo(a, b) a + b
    #define bar(r) r * r
    #define getGreater(x, y) x > y ? x : y;
```

> Conditonal Compilation
```C
    #ifdef MACRONAME // Code to be executed if macro_name is defined
    #ifndef MACRONAME // Code to be executed if macro_name is not defined
    #if (foo > bar) // Code to be executed if constant_expression is true
    #else // Code to be excuted if none of the above conditions are true
    #elif // Code to be excuted if the above conditions is not true
    #endif // End if expression
```

> Other Directives
```C
    #undef MACRONAME // Undefines a macro
    #pragma directive // directive can be startup, exit, once, etc. Mostly used for compiler features
```

Preprocessor directives may cause issues with expressions, as PEMDAS still applies to copy-pasted code


```C
    #define NONONOFUCKOFF ;
    printf("Hello World") NONONOFUCKOFF // valid
```
```C
    #define somefunc 1 + 2 * 3
    printf("%d", 2 * somefunc); // 8
```

## -ARRAYS-
You can also access indicies of arrays using the increments of the array variable;
```C
    int arr[30];    
    scanf("%d", arr + 2);
```
^^^^^^^^^^^^^^^^^^^^^ This accesses the (Third element) arr[2] of the array, as it is arr[0] + 2 integers.
^^^^^^^^^^^^^^^^^^^^^ = 0x00008000 => 0x00008010 (+ 16 bytes)

Providing less than the total amount of data in an array zeros out all other data in the array. This is true for even just 1 value;
```C
    int arr[10] = {10, 40};
    arr is now {10, 40, 0, 0, 0, 0, 0, 0, 0, 0}
```

Without including the subscript operators [], the array variable is a pointer variable ****** to the first item of the array
```C
    int *arr == &arr[0]
    int *arr == arr
```
When using double arrays, loop through the columns first and then increment the rows (like reading english)
This is due to cache locality

Double arrays are declared by:
```C
    int arr[ROWS][COLUMNS];
```

Assigning memory out of bounds is undefined behavior and the program may hang, reading it will work, but still undefined behavior.

Originally in ANSI C, you needed to know the size of an array during compile time.
Now it's ok to do that C99;

## Memory

0xFFFFFFFF
| Stack |
| :--------: |
VVVVVVVVVVVVVV Grow negative
| free space |
| ---------- |
|   (stack)  |


| free space |
| ---------- |
|   (heap)   |
^^^^^^^^^^^^^^ Grow positive
| Heap |
| :--------: |


| data seg   |
| :--------: |
| code seg   |
| :--------: |
0x00000000

* This is how programs are loaded into memory

* Code segment - We don't really mess with this. This is where code is stored.
* Data segment - This is where global inputs and variables are stored.

* Stack - (Automatic memory) - Space in memory where a functions local variables are allocated during a function call.
Automatically allocated and deallocated.
Usually around 8MB.

* Heap - (Free store) - Memory for dynamic allocation and deallocation.

Sometimes the stack and the heap can cross pollinate and "grow" into each other.

## Pointers
A variable that stores a memory address (usually of another variable)
```C
//Declaration
//int* is a pointer to an integer type

int a = 10;
int* x = &a;
int* y = x;
```

The value stored in one of these memory addresses can be dereferenced using the * (dereference operator)
```C
//Dereferencing
int a = 10;
int* x = &a;
printf("%d", *x);
//prints 10
printf("%p", x);
//prints 0xACFDA440 or wherever a was
```

Pointer arithmetic
```C
int* a = &b;
a += 1;
//A is moved 4 bytes upward (4 bytes for an integer)

double* b = &c;
b += 1;
//B is moved 8 bytes upward 
```

Dynamically Allocated Memory 
```C
int* a = (int*) malloc(length * sizeof(int));
//Here a could be an array of size "length" given that length is a valid integer
//Declares length int sized pointers starting at address a

int* a = (int*) calloc(length, sizeof(int));
//calloc needs two params as opposed to multiplying, and sets all indicies to 0
```
Keep in mind both malloc and calloc need to be casted to their respective data type pointer variants
By default both return a (void*) wtf??


