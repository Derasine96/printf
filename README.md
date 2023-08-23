# PRINTF FUNCTION

## Description

------------

[![printf.jpg](https://i.postimg.cc/QtBH3tmV/printf.jpg)](https://postimg.cc/S2hyLmwp)

The printf function sends formatted output to stdout.
A custom _printf() for learning purposes was developed by cohort  #8 students Nicks and Musa parsanka.
_printf() function format string is a character string, beginning and ending in its initial shift state, if any. 
These arguments are placed using the percentage '%' operator

------------
### Resources

Secrets of printfby Don colton
https://www.cypress.com/file/54761/download

------------

#### Authorized Functions and Macros

------------

write (man 2 write)
malloc (man 3 malloc)
free (man 3 free)
va_start (man 3 va_start)
va_end (man 3 va_end)
va_copy (man 3 va_copy)
va_arg (man 3 va_arg)

------------

#### Compilation


The code must be compiled this way:

**$ gcc -Wall -Werror -Wextra -pedantic *.c**

As a consequence, be careful not to push any c file containing a main function in the root directory of your project (you could have a test folder containing all your tests files including main functions)

The main files will include your main header file (main.h): **#include main.h**

------------

#### Use & Examples


------------

**Prototype:** int _printf(const char *format, ...);
**Use - General:** _printf("format string", var1, var2, ...);

**Examples:**
 - Basic String: _printf("%s Alx", "Hello");`
	 - Output: Hello Alx

- Print integers: _printf("This is an array element: arr[%d]:%c", 32, arr[32]);`
	- Output: This is an array element arr[32]:A

Many other specifiers and flags were added and by combinig those the _printf() function generate a different ouput. The following list are the specifiers and flags allowed.

------------

#### Use & Examples

------------

###### Specifiers

Specifier                |Output                        |Examples |
|----------------|-------------------------------|-----------------------------|
| `c` | Character | y |
| `d` or `i` | Signed integer | 1024, -1024 |
| `s` | String of characters | Hello Alx |
| `b` | Binary Representation of unsigned integer | 01010110 |
| `u` | Unsigned integer | 1024 |
| `o` | Unsigned octal | 432 |
| `x` | Unsigned hexadecimal integer | 3ca |
| `X` | Unsigned hexadecimal integer (uppercase) | 3CA |
| `S` | String with hex-ascii value replacing special chars | \x0A\x0A |
| `p` | Pointer address | 0x403212 |
| `r` | Reversed string of characters | dlroW olleH |
| `R` | ROT13 Translation of string | Uryyb |

###### Flags (In development...)

|Flag                |Description                        |
|----------------|-------------------------------|
| `-` |Left-justify the output within the field width that was given; Right justification is the default (see _width_ sub-specifier). |
| `+` |Preceeds the result with a plus or minus sign (`+` or `-`) even for positive numbers. By default, only negative numbers are preceded with a `-` sign. |
| `(space)` |If no sign is going to be written, a blank space is inserted before the value. |
| `#` |Used with `o`, `x` or `X` specifiers the value is preceeded with 0, 0x or 0X respectively for values different than zero. |
| `0` |Left-pads the number with zeroes (`0`) instead of spaces when padding is specified (see _width_ sub-specifier). |

###### Width (In development...)

|Width                |Description                        |
|----------------|-------------------------------|
| `(number)` |Minimum number of characters to be printed. If the value to be printed is shorter than this number, the result is padded with blank spaces. The value is not truncated even if the result is larger.|
| `*` | The _width_ is not specified in the _format_ string, but as an additional integer value argument preceding the argument that has to be formatted.|

### Precision (In development...)

|.Precision               |Description                        |
|----------------|-------------------------------|
| `.(number)` |**For integer specifiers (`d`, `i`, `o`, `u`, `x`, `X`):** _precision_ specifies the minimum number of digits to be written. If the value to be written is shorter than this number, the result is padded with leading zeros. The value is not truncated even if the result is longer. A _precision_ of 0 means that no character is written for the value 0. **For `s`**: this is the maximum number of characters to be printed. By default all characters are printed until the ending null character is encountered. If the period is specified without an explicit value for _precision_, 0 is assumed. |

### Lenght modifiers (In development...)

|Modifier/Specifier  |`d` & `i`  |`u`, `o`, `x`, `X` |`c` |`s` |`p` |
|----------------|---------|------------|-------------|-----|-------|
| `none` | int |unsigned int | int| char pointer| void pointer |
| `h` |short int|unsigned short int |     |     |              |
| `l` |long int |unsigned long int  |     |     |              |

------------

#### Files contained in this repository

------------

|Name                |Information                        |Relevant Files                         |
|----------------|-------------------------------|-----------------------------|
|`main.h`	| Header file with the data type struct, standard libraries and custom prototypes.| `*.c compilation` |
|`_printf.c`|Main printf function file. Calls other functions.|`printf_(name of var).c file` |
|`printfunction.c`|. Contains:
Contains percentage print function
Contains decimal and integer functions
Custom function for char data type.
|`printfunction2.c`|. Contains:
Function that calls string type variable
Function that gets the binary
Functions that returns octal number.
|`printfunction3.c`|. Contains:
Calls hexadecimal numbers (lowercase)
Calls hexadecimal numbers (Uppercase)
|`utils.c`|. Contains:
Auxiliar function for hexadecimal specific functions (lowercase). 
Auxiliar function hexadecimal specific functions (Uppercase).
Returns a string and non readable characters are printed in hexadecimal numbers (Lowercase).
Returns a string in reverse.
Returns a string in Rot13.` |
Auxiliar functions such as strlen and strcpy.
|`_putchar.c` | Custom putchar function. | `None` |


------------

## Tasks required for this project

------------

0. ### Write a function that produces output according to a format.
Handle the following conversion specifiers:
- c
- s
- %

1. ### Handle the following conversion specifiers:
- d
- i

2. ###### Create a man page for the function

3. ###### Handle the following conversion specifiers:
- b

4. ###### Handle the following conversion specifiers:
- u
- x
- o
- x
- X

5. ###### Use a local buffer of 1024 chars in order to call write as little as possible.

6. ###### Handle the following format specifiers
- S : prints the string.
- Non printable characters (0 < ASCII value < 32 or >= 127) are printed this way: \x, followed by the ASCII code value in hexadecimal (upper case - always 2 characters).

7. ###### Handle the following conversion specifier: p

8. ###### Handle the following flag characters for non-custom conversion specifiers:
- ´+´
- space
- ´#´ 

9. ###### Handle the following length modifiers for non-custom conversion specifiers:
- l
- h
Conversion specifiers to handle: d, i, u, o, x, X

10. ###### Handle the field width for non-custom conversion specifiers.

11. ###### Handle the precision for non-custom conversion specifiers.

12. ###### Handle the 0 flag character for non-custom conversion specifiers.

13. ###### Handle the - flag character for non-custom conversion specifiers.

14. ###### Handle the following custom conversion specifier:
 - r : prints the reversed string

15. ###### Handle the following custom conversion specifier:
- R: prints the rot13'ed string

16. ###### *
All the above options work well together.

### Authors &copy;

- Gbenga Etomu
- Obikwelu Chidera
