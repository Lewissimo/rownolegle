#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <omp.h>

void sieve_of_eratosthenes_functional(int n) {
    bool *prime = malloc((n+1) * sizeof(bool));
    int sqroot = (int)sqrt(n);

    // Inicjalizacja tablicy
    for (int i = 0; i <= n; i++) {
        prime[i] = true;
    }
    prime[0] = prime[1] = false; // 0 i 1 nie są liczbami pierwszymi

    // Sekwencyjne sito do pierwiastka z n
    for (int p = 2; p <= sqroot; p++) {
        if (prime[p]) {
            for (int i = p * p; i <= n; i += p) {
                prime[i] = false;
            }
        }
    }

    // Równoległe wykreślanie dla liczb pierwszych do pierwiastka z n
    #pragma omp parallel for schedule(static)
    for (int p = 2; p <= sqroot; p++) {
        if (prime[p]) {
            for (int i = p * 2; i <= n; i += p) {
                prime[i] = false;
            }
        }
    }

    // Wypisanie wyników
    for (int p = 2; p <= n; p++) {
        if (prime[p]) {
            printf("%d ", p);
        }
    }
    printf("\n");

    free(prime);
}

int main() {
    int n = 100;
    printf("Prime numbers up to %d (Functional Approach):\n", n);
    sieve_of_eratosthenes_functional(n);
    return 0;
}
