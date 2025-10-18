#include <stdio.h>

int mdc(int a, int b) // Função para Calcular o MDC
{
    int resto;
    while (b != 0) {
        resto = a % b;
        printf("Algoritmo de Euclides: %d MOD %d = %d\n", a, b, resto);
        a = b;
        b = resto;
    }

    return a;
}

int mmc(int a, int b) // Função para Calcular o MMC
{
    return (a * b) / mdc(a, b);
}

int mmcLista(int C[], int N) // Função para Calcular o MMC dos Ciclos de Ativação das Chaves
{
    int MMC = C[0];

    for (int i = 1; i < N; i++)
    {
        MMC = mmc(MMC, C[i]);
        printf ("MMC: %d = (%d * %d) / MDC (%d, %d)\n\n", MMC, C[i-1], C[i], C[i-1], C[i]);
    }

    return MMC;
}

int main()
{
    int N;

    printf ("Digite o Numero de Chaves: ");
    scanf ("%d", &N);
    
    if (N < 1 || N > 10)
    {
        printf ("Erro! O Numero de Chaves deve estar entre 1 e 10!\n");
        return 1;
    }

    int C[20]; // Salvar os Ciclos

    printf ("Digite os Ciclos de Ativacao das Chaves: ");
    for (int i = 0; i < N; i++)
    {
        scanf ("%d", &C[i]);

        if (C[i] < 2 || C[i] > 20)
        {
            printf ("Erro! Os Ciclos de Ativacao das Chaves devem estar entre 2 e 20\n");
            return 1;
        }
    }

    printf ("\nCiclos: ");
    for (int i = 0; i < N; i++)
    {
        printf ("%d", C[i]);
        if (i < N - 1)
            printf (", ");
    }

    printf ("\n\n");

    int Ano = mmcLista(C, N); // Ano de Sincronização das Chaves

    if (Ano > 0 && Ano <= 50) // Verifica se o Ano de Sincronização das Chaves está entre 1 e 50
    {
        printf ("Ano de Sincronizacao das Chaves: %d\n", Ano);
    }
    else
    {
        printf ("Ativacao Impossivel! O Ano de Sincronizacao das Chaves esta fora do Intervalo de 1 a 50 Anos.\n");
    }
    
    return 0;
}