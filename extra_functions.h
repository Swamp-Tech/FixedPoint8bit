#ifndef EXTRA_FUNCTIONS_H 
#define EXTRA_FUNCTIONS_H

// Вычисляет косинус через три члена ряда тейлора
// Входное значение задается через value_16bit в радианах
// Возле 0 и Пи считает плохо
// value_16bit - задает аргумент в радианах (От 0 до 3.14)
// c - выгружется результат
/*
int32_t c;
uint32_t term_1;
uint32_t term_2;
uint32_t term_3;
*/
void taylor_cos (void);

#include "extra_functions.c"

#endif