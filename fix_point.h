#ifndef FIX_POINT_H 
#define FIX_POINT_H

// Переопределенные стандартные типы
#include <stdint.h>

// Возвращает адрес первого байта числа  
#define GET_BYTE(X) ((uint8_t*)(&X)) 


//
// Макросы ввода значений
//

// Преобразует Десятичную дробь в двоичную дробь с фиксированной точкой
// INT - целая часть, FRAC - дробная (3 разряда!!!), fix8_8 - ufix8_8 переменная
// FRAC = 3 - это 0,003 
// Писать DECIMAL(1,003,...) нельзя, 0 перед числом делает его восьмеричным
// FRAC = 123 - это 0,123
#define DECIMAL(INT,FRAC,FIX8_8) \
            FIX8_8 = ((INT << 8) | ( (FRAC * 256UL) / 1000UL ) )
// Возвращает число с фикс точкой fix8_8
// GET_DEC(3,45) - вернет (3.045)!
#define GET_DEC(INT,FRAC) \
            ((INT << 8) | ( (FRAC * 256UL) / 1000UL ) )
            
// Задает и возвращает число с фикс точкой в двоичном виде
// инт + (frac/256) - его десятичное значение
// Дробная часть хранится просто в виде frac
#define GET_BIN(INT,FRAC) \
            ((INT << 8) | FRAC)

//
// Прочие операции
//

// Инкремент переменной переменной с фиксированной точкой (8 бит дробная часть)
#define INC_FIX(X) (X += 256)

// Декремент переменной переменной с фиксированной точкой (8 бит дробная часть)
#define DEC_FIX(X) (X -= 256)

// Реализует сдвиг вправо на 8 бит через копирование байт
// Для 32-битных чисел
#define SHIFT_RIGHT_BY_8_BITS(N_32BIT) \
            GET_BYTE(N_32BIT) [0] = GET_BYTE(N_32BIT) [1]; \
            GET_BYTE(N_32BIT) [1] = GET_BYTE(N_32BIT) [2]; \
            GET_BYTE(N_32BIT) [2] = GET_BYTE(N_32BIT) [3]; \
            GET_BYTE(N_32BIT) [3] = 0


// Квадратный корень положительного целого числа от 0 до 255
// Аргумент может быть переменной или целочисленной константой
// Результат сохраняется в fix8_8
#define SQRT(X, fix8_8) \
            GET_BYTE(fix8_8) [0] = sqrt_frac [X]; \
            GET_BYTE(fix8_8) [1] = sqrt_int [X]


//
// Умножение
//

// Макрос беззнакового умножения A = X * Y 
// A - ufix24_8
// X, Y  - ufix8_8 или ufix24_8
#define MUL_UFIX(X, Y, A) \
            A = (ufix24_8)X * (ufix24_8)Y; \
            SHIFT_RIGHT_BY_8_BITS (A)

// Тут стандартный сдвиг, так как нужно учитывать знаковый бит
#define MUL_FIX(X, Y, A) \
            A = (fix24_8)X * (fix24_8)Y; \
            A >>= 8

// Возведение числа в квадрат
#define SQUARE(X, C) \
            C = (fix24_8)X * (fix24_8)X; \
            C >>= 8


//
// Деление
//
       
// Беззнаковое деление - С = X / Y
// A - uint32_t
// X, Y  - uint16_t or uint32_t
#define DIV_UFIX(X, Y, A) \
            GET_BYTE(A) [0] = 0; \
            GET_BYTE(A) [1] = GET_BYTE(X) [0]; \
            GET_BYTE(A) [2] = GET_BYTE(X) [1]; \
            GET_BYTE(A) [3] = 0;  \
            A /= (ufix8_8)Y
// Знаковое деление
#define DIV_FIX(X, Y, A) \
            GET_BYTE(A) [0] = 0; \
            GET_BYTE(A) [1] = GET_BYTE(X) [0]; \
            GET_BYTE(A) [2] = GET_BYTE(X) [1]; \
            if (GET_BYTE(X) [1] & 0x80)  \
                GET_BYTE(A) [3] = 0xFF; \
            else \
                GET_BYTE(A) [3] = 0; \
            A /= (fix24_8)Y

//
// Тригонометрия
//

// Переводит обычные градусы в двоичные градусы
// INT - целая часть
// FRAC - дробная (2 разряда!)
// FRAC = 3 - это 0,03
#define DEGREE(INT, FRAC) \
            ( ( (INT*100 + FRAC) * 256UL ) / 9000UL )

// Переводит обычные радианы в двоичные градусы
// Аналогично как и для градусов
#define RAD(INT, FRAC) \
            ( ( (INT*100 + FRAC) * 256UL ) / 157UL )

// Вычисляет косинус в градусах до 90 градусов
// Только до 90 градусов
#define COS_D(INT, FRAC) \
            cosines [DEGREE (INT, FRAC)]

// Вычисляет косинус в радианах до 90 градусов
// Только до 90 градусов
#define COS_R(INT, FRAC) \
            cosines [RAD (INT, FRAC)]
// Вычисляет косинус двоичных градусов
// 1 двоичный градус = 90/256 обычных градусов
// Только до 90 градусов
#define COS_B(B) \
            cosines [B]

void taylor_cos (void);

#include "fix_point.c"

#endif