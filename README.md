## Fixed Point Library for  NES

This is a math library that implements fixed-point calculations for NES and other 8-bit processors.
The code is implemented in C for the CC65 compiler for the C99 standard.

Example (signed multiplication):
```c
fix24_8 c;   // result
fix8_8  a, b // args
// -1 * 2*(240/256)
a = -1 * GET_BIN(2,240);
// 23*(13/256)
b = GET_BIN(23,13);
MUL_FIX(a, b, c);
```
![](../Cache/Pasted%20image%2020250220220133.png)
Example (cosine): 

```c
fix8_8 c;  
// cos (60.0) [0..90 degree - valid values ​​for argument]
c = SIN_D(60, 0);
```
![](../Cache/Pasted%20image%2020250220220319.png)
Example (square root):

```c
fix8_8 c;  
//0..255 valid values ​​for argument
SQRT(47, c);
```
![](../Cache/Pasted%20image%2020250220220446.png)
