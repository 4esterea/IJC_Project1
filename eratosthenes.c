// eratosthenes.c
// Řešení IJC-DU1, příklad a), 21.3.2023
// Autor: Zhdanovich Iaroslav, FIT
// Přeloženo: gcc 9.4.0

#ifdef USE_INLINE
#include "bitset-i.h"
#else
#include "bitset.h"
#endif
#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>


void eratosthenes(bitset_t *array, long unsigned size) 
{   
    
    bitset_setbit(array, (LONG_BIT), 1);                            // nastavi 1 pro 0
    bitset_setbit(array, (1+LONG_BIT), 1);                          // nastavi 1 pro 1
    for (int i = LONG_BIT+2; i < sqrt(size+LONG_BIT); i++)          // Eratosthenovo síto
    {
        if (bitset_getbit(array, (i)) == 0) 
        {
            for (long unsigned temp = i + i - LONG_BIT; temp < size+LONG_BIT; temp += (i-LONG_BIT))
            {
                bitset_setbit(array, temp, 1);
            }
        }
    }
    int prvocisla[10];
    int count = 0;
    for (long unsigned i = LONG_BIT+size-1; i >= LONG_BIT; i--){   // najde posledních 10 prvočísel
        if (bitset_getbit(array, i) == 0)
        { 
            prvocisla[count] = i-LONG_BIT;                         
            count +=1;
            if (count == 10) break;
        }
    }
    for (int i = 9; i >= 0; i--) printf("%i\n", prvocisla[i]);     // vypíše posledních 10 prvočísel ve vzestupném pořadí
}

