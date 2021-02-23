# ft_printf
Project for 42_Roma

This project is pretty straight forward. You will recode printf.
You will mainly learn how to use variadic arguments.

The project contains a C library regrouping usual functions and ft_printf, a function
that will mimic the real printf.

See the subjects for further information

[SUBJECTS](Resources/en_subject.pdf)

## Getting Started

The repository contains a main, usefull to test the ft_printf function.

### Build the library

The following command builds the library, without the bonus functions
```
make re
```


The following command builds the complete library, also with the bonus functions
```
make bre
```


For testing the library with the main, use this command:
```
gcc -L . -lftprintf main_ft_printf.c
```
