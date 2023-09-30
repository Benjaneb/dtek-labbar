#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define COLUMNS 6

void print_number(int n)
{
    static int count = 0;

    if (count == COLUMNS)
    {
        printf("\n");
        count = 0;
    }

    printf("%10d ", n);
    count++;
}

void print_sieves(int n)
{
    char composites[n];
    // Zero initialize
    for (int i = 0; i < n; i++)
        composites[i] = 0;    
    
    // Sieve of eratosthenes
    float sqrtn = sqrt(n);
    for (int i = 2; i <= sqrtn; i++)
        if (!composites[i-1])
            for (int j = i * i; j <= n; j += i)
                composites[j-1] = 1;

    int countDistanceFour = 0;
    int previousPrime = 0;
    // Print numbers not marked as composites
    // and count prime numbers with distance 4 from previous prime
    for (int i = 2; i <= n; i++) {
        if (!composites[i-1]) {
            print_number(i);
            if (i - previousPrime == 4)
                countDistanceFour++;
            previousPrime = i;
        }
    }
    printf("\nPrimes with distance 4: %d\n", countDistanceFour);
}

// 'argc' contains the number of program arguments, and
// 'argv' is an array of char pointers, where each
// char pointer points to a null-terminated string.
int main(int argc, char *argv[])
{
    if (argc == 2)
        print_sieves(atoi(argv[1]));
    else
        printf("Please state an interger number.\n");
    return 0;
}