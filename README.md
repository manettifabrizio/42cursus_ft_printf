<h1 align="center">
	🖨 ft_printf 🖨 
</h1>

<p align="center">
	<b><i>CURSUS: 2019 - AUTHOR: fmanetti - GRADE: 107 - FINISHED: 25/04/2020</i></b><br>
</p>

<p align="center">
	The goal of this project is recode printf(). You will mainly learn about using a variable number of arguments.
</p>

![image](https://github.com/manettifabrizio/42cursus_srcs/blob/main/images/ft_printf.gif)

## Introduction

You will discover a popular and versatile C function: printf(). This exercise is a great opportunity to improve your programming skills. It is of moderate difficulty. You will discover variadic functions in C. The key to a successful ft_printf is a well-structured and extensible code.

For more detailed information, look at the [**subject of this project**](https://github.com/manettifabrizio/42cursus_srcs/tree/main/subjects/ft_printf).

### Disclaimer

At 42 school when we program in C we are subject to a set of rules called [**the norm**](https://github.com/manettifabrizio/42cursus_srcs/blob/main/subjects/norm/en.norme_v2.pdf), so if the code is not 100% optimized this is the reason. This project was coded following norminette v2.

## Implemented conversions

- `%c`: Prints a single character.
- `%s`: Prints a string (as defined by the common C convention).
- `%p`: The void * pointer argument has to be printed in hexadecimal format. 
- `%d`: Prints a decimal (base 10) number.
- `%i`: Prints an integer in base 10.
- `%u`: Prints an unsigned decimal (base 10) number.
- `%x`: Prints a number in hexadecimal (base 16) lowercase format.
- `%X`: Prints a number in hexadecimal (base 16) uppercase format.
- `%%`: Prints a percent sign.

## Implemented flags

- `-`: Left adjustment of the output in the indicated field.
- `0`: Indicating that zero-padding should be used rather than blank-padding.
- `.`: Precision.

## Bonus conversions

- `%f`: Prints a float with signed value in the form [-]dddd.dddd, where dddd is one or more decimal digits.
- `%e`: Prints a float with signed value in the form [-]d.dddde±dd[d], where d is one decimal digit.

## Bonus flags

- `#`: A `#' character specifying that the value should be printed in an ``alternate form''.
- `' '`: A space specifying that a blank should be left before a positive number for a signed format.
- `+`: A `+' character specifying that there should always be a sign placed before the number when using signed formats.

## Usage

### Requirements

The function is written in C language and thus needs the **`gcc` compiler** and some standard **C libraries** to run.

### Instructions

**1. Compiling the library**

To compile, go to the library path and run:

```shell
$ make
```

**2. Using it in your code**

To use the library functions in your code, simply include its header:

```C
#include "ft_printf.h"
```

## Testing

* [42TESTERS-PRINTF](https://github.com/Mazoise/42TESTERS-PRINTF) - Mazoise
* [PRINTF_TESTER](https://github.com/Kwevan/PRINTF_TESTER.git) - Kwevan
* [printf_lover-v2](https://github.com/charMstr/printf_lover_v2.git) - charMstr

## Sources

[`Microsoft Docs`](https://docs.microsoft.com/en-us/cpp/c-runtime-library/format-specification-syntax-printf-and-wprintf-functions?view=msvc-170)