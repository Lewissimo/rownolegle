#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <omp.h>

void sieve_of_eratosthenes_domain(int n) {
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
                printf("%d\n",i);
                
            }
        }
    }

    // Równoległe wykreślanie dla reszty zakresu
    #pragma omp parallel for schedule(static)
    for (int i = sqroot + 1; i <= n; i++) {
        if (prime[i]) {
            for (int j = i * i; j <= n; j += i) {
                prime[j] = false;
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
    printf("Prime numbers up to %d (Domain Approach):\n", n);
    sieve_of_eratosthenes_domain(n);
    return 0;
}
