#include <stdlib.h>
#include <stdio.h>

/*
Hjelpefunksjon brukt til å lage et array til å teste funksjonene
ikke relevant til selve eksamensoppgaven
*/
void random_array(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        A[i] = rand() % 2;
    }
}

// oppgave A
int forekommer(int *A, int n, int k)
{
    // Lager en counter integer til å telle antall ganger k forekommer
    int count = 0;

    // Itererer arrayet ved en for loop
    for (int i = 0; i < n; i++)
    {
        // Hver gang vi finner k, legger vi til 1 på counteren
        if (A[i] == k)
        {
            count++;
        }
    }

    // Når programmet har kjørt gjennom hele arrayet, returnerer vi antall ganger k forekommer
    return count;
}

// oppgave B
void sorter(int *A, int n)
{
    // Deklarerer to variabler som brukes i sorteringen
    int temp;
    int sorted = 0;

    // Ønsker å kjøre sorteringsloopen så lenge arrayet ikke er sortert
    while (!sorted)
    {   
        // Starter hver iterasjon med å anta et arrayet er sortert
        sorted = 1;

        // For loop som itererer arrayet
        for (int i = 0; i < n - 1; i++)
        {
            // Hvis er element er større enn det som kommer etter, må man bytte plass på elementene
            if (A[i] > A[i + 1])
            {
                // Swapper to elementer ved å bruke en temp variabel
                temp = A[i];
                A[i] = A[i + 1];
                A[i + 1] = temp;

                // Nå som vi har måttet swappe to elementer, kan vi ikke lenger anta at lista er sortert, derav settes den til 0
                sorted = 0;
            }
        }
    }
}

// Oppgave C
int majoritetselement(int *A, int n)
{
    // Bruker sorteringsfunksjonen til å sortere arrayet
    sorter(A, n);

    // Finner midterste tallet
    int midten = A[n/2];

    // Sjekker hvor mange ganger midterste tallet forekommer ved forekommerfunksjonen
    int antall_midten = forekommer(A, n, midten);

    // Dersom midterste tallet er et majoritetselement, returnerer vi 1
    if (antall_midten > n/2)
        return 1;
    
    // Hvis ikke, 0
    else 
        return 0;
}

// Main brukt til å teste funksjonene
int main()
{
    int n = 1000;
    int k = 17;
    int *A = malloc(sizeof(int) * n);

    random_array(A, n);

    printf("majoritetselement: %d\n", majoritetselement(A, n));
}