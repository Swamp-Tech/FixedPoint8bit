#ifndef FIX_POINT_TYPES_H
#define FIX_POINT_TYPES_H


// Беззнаковое число с фиксированной точкой 16бит (Младшие 8 бит на дробную часть)
typedef uint16_t ufix8_8;
// Ззнаковое число с фиксированной точкой 16бит (Младшие 8 бит на дробную часть)
typedef int16_t fix8_8;
// Беззнаковое число с фиксированной точкой 32-бита (Младшие 8 бит на дробную часть)
typedef uint32_t ufix24_8;
typedef int32_t fix24_8;

// Двоичные
typedef uint8_t degree8;

#endif