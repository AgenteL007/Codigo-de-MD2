#include <stdio.h>
#include <stdbool.h>

bool ehPrimo(int N) // Função para Verificar se o Número é Primo
{
    if (N <= 1)
        return false;

    if (N <= 3)
        return true;

    if (N % 2 == 0 || N % 3 == 0)
        return false;
    
    for (int i = 5; i * i <= N; i += 6)
    {
        if (N % i == 0 || N % (i + 2) == 0)
            return false;
    }
    return true;
}

void decomporFatoresPrimos(int N) // Função para Decompor um Número em Fatores
{
    if (N == 1) // Quando o Número é 1
    {
        printf ("Fator Primo: 1 = 1\n");
        return;
    }

    int N2 = N; // Salvar o Número Original
    int Fator = 2;
    int Expoente;
    int Verificador = 1;

    while (N > 1)
    {
        printf ("Testando Fator: %d\n", Fator);
        printf ("Atual: %d\n", N);

        if (ehPrimo(Fator)) // Verifica se o Fator é Primo
        {
            printf ("%d eh Primo\n", Fator);

            if (N % Fator == 0) // Verifica se o Fator divide o Atual
            {
                Expoente = 0;
                printf ("%d divide %d\n", Fator, N);
                printf ("Dividindo sucessivamente:\n");

                while (N % Fator == 0) // Faz Divisões Sucessivas
                {
                    Expoente++;
                    int R = N / Fator; // R = Resultado
                    printf ("%d ÷ %d = %d", N, Fator, R);

                    if (R % Fator == 0 && R > 1)
                    {
                        printf ("=> Continua Divisivel por %d\n", Fator);
                    }
                    else if (R > 1)
                    {
                        printf ("=> NAO EH mais Divisivel por %d\n", Fator);
                    }
                    else
                    {
                        printf ("=> Chegou-se em 1\n");
                    }

                    N = R;
                }

                printf ("Fator Primo: %d^%d\n", Fator, Expoente);

                if (Verificador)
                {
                    printf ("Fatores Parciais: %d", Fator);
                    if (Expoente > 1)
                    {
                        printf ("^%d", Expoente);
                        Verificador = 0;
                    }
                }
                else
                {
                    printf ("Fatores Primos: x %d", Fator);
                    if (Expoente > 1)
                    {
                        printf ("^%d", Expoente);
                    }
                }

                if (N > 1)
                
                {
                    printf (" x [%d]", N);
                }
                
                printf ("\n\n");

            }
            else
            {
                printf ("%d NAO divide %d\n", Fator, N);
                printf ("Ir para o Proximo Fator.\n\n");
            }
            
            Fator++;

            if (N > 1 && ehPrimo(N))
            {
                printf ("Numero Restante %d eh Primo\n", N);
                printf ("Fator Primo: %d^1\n");
            }

            if (Verificador)
            {
                printf ("Fatores Primos Finais: %d\n");
            }
            else
            {
                printf ("Fatores Primos Finais:  x %d\n, N");
            }

            N = 1;
        }
    }

    printf ("Numero Decomposto\n");
    printf ("%d = ", N2);

    N = N2;
    Fator = 2;
    Verificador = 1;

    while (N > 1) // Juntar os Fatores Primos
    {
        Expoente = 0;
        while (N % Fator == 0)
        {
            Expoente++;
            N /= Fator;
        }

        if (Expoente > 0)
        {
            if (!Verificador)
            {
                printf (" x ");
            }

            printf ("%d", Fator);

            if (Expoente > 1)
            {
                printf ("^%d",Expoente);
            }

            Verificador = 0;
        }

        Fator++;
    }
}

int main()
{
    int N;

    do
    {
        printf ("Digite um Numero entre 1 e 105: ");
        scanf ("%d", &N);

        if (N < 1 || N > 105)
            printf ("Erro! O Numero deve estar entre 1 e 105!\n");
    } while (N < 1 || N > 105);

    decomporFatoresPrimos(N);
}