# makefile
# Řešení IJC-DU1, příklad a), 21.3.2023
# Autor: Zhdanovich Iaroslav, FIT
# Přeloženo: gcc 9.4.0

run: primes primes-i
	ulimit -s 29000
	./primes 
	./primes-i

primes: eratosthenes.o primes.c
	gcc -O2 -g -std=c11 -pedantic -Wall -Wextra primes.c -o primes -lm

primes-i: eratosthenes-i.o primes.c
	gcc -DUSE_INLINE -O2 -g -std=c11 -pedantic -Wall -Wextra primes.c -o primes-i -lm

eratosthenes-i.o: eratosthenes.c bitset.h bitset-i.h
	gcc -DUSE_INLINE -O2 -g -std=c11 -pedantic -Wall -Wextra -c eratosthenes.c -o eratosthenes-i.o

eratosthenes.o: eratosthenes.c bitset.h bitset-i.h
	gcc -O2 -g -std=c11 -pedantic -Wall -Wextra -c eratosthenes.c -o eratosthenes.o

clean:
	rm -f primes primes-i *.o correct