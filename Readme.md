## Fixed Point Library for  NES

This is a math library that implements fixed-point calculations for NES and other 8-bit processors.
The code is implemented in C for the CC65 compiler for the C99 standard.

Example (multiplication):
```c
a = -1 * GET_BIN(2,240);
b = GET_BIN(23,26);
DIV_FIX(a, b, c);
value_32bit = c;
```
Example (cosine): 

```c
value_32bit = cosines[128];
```
Example (square root):

```c
SQRT(47, c);
value_32bit = c;
```
