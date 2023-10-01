// primes.c
// Řešení IJC-DU1, příklad a), 21.3.2023
// Autor: Zhdanovich Iaroslav, FIT
// Přeloženo: gcc 9.4.0

#include <stdio.h>
#include <time.h>
#include "eratosthenes.c"
#define ARRAY_SIZE 230000000

int main(){
    clock_t start = clock();                                                    // měření doby běhu programu
    bitset_create(p, ARRAY_SIZE);                                               // inicializace bitového pole
    eratosthenes(p, ARRAY_SIZE);                                                // použití eratostenového síta
    fprintf(stderr, "Time=%.3g\n\n", (double)(clock()-start)/CLOCKS_PER_SEC);
    return 0;
}