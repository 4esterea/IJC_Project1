// bitset-i.h
// Řešení IJC-DU1, příklad a), 21.3.2023
// Autor: Zhdanovich Iaroslav, FIT
// Přeloženo: gcc 9.4.0

#include <stdio.h>
#include <limits.h>
#include <stdint.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>

#define MAX_BITSET_SIZE (SIZE_MAX / sizeof(unsigned long) * CHAR_BIT)
#define LONG_BIT (CHAR_BIT * sizeof(unsigned long))

typedef unsigned long bitset_t;

typedef unsigned long bitset_index_t;

#define bitset_create(array_name, size)\
    bitset_t (array_name)[(size) / (LONG_BIT) + (((size) % (LONG_BIT)) ? 2 : 1)] = { (size), };\
    static_assert((size) != 0 && size <= MAX_BITSET_SIZE, "bitset_create: Bitset size error")


#define bitset_alloc(array_name, size) \
    bitset_t * (array_name) = malloc(LONG_BIT * ((size) / (LONG_BIT) + (((size) % (LONG_BIT)) ? 2 : 1)));\
    memset((array_name), 0, ((size) / (LONG_BIT) + (((size) % (LONG_BIT)) ? 2 : 1)));\
    assert((size) != 0 && (size) <= MAX_BITSET_SIZE);\
    if ((array_name) == NULL) {\
        fprintf(stderr, "bitset_alloc: Memory allocation error\n");\
        exit(EXIT_FAILURE);\
    }\
    (array_name)[0] = size;


static inline void bitset_free(bitset_t* array_name) {
    free(array_name);
}

static inline bitset_index_t bitset_size(const bitset_t* array_name) {
    return array_name[0];
}

static inline void bitset_setbit(bitset_t* array_name, bitset_index_t index, int expression) {
    unsigned long mask = ((unsigned long)0x0000000000000001) << ((index % LONG_BIT));
    if (expression == 0) {
        array_name[index / LONG_BIT] &= ~mask;
    } else {
        array_name[index / LONG_BIT] |= mask;
    }
}

static inline int bitset_getbit(const bitset_t* array_name, bitset_index_t index) {
    if (((signed int)(index) < 0 || (index) > bitset_size(array_name)+LONG_BIT)){
        fprintf(stderr, "bitset_getbit: Index %lu mimo rozsah 0..%lu\n", (unsigned long)index, (unsigned long)bitset_size(array_name));
        exit(EXIT_FAILURE);
    } else
    return ((array_name[index / LONG_BIT] >> (index % LONG_BIT)) & 0x1);
}

