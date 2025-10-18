#include <stdio.h>
#include <stdbool.h>

int D; // Total de Divisores do Número
int S; // Soma de Todos os Divisores do Número

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
        D =1;
        S = 1;
        printf ("Fator Primo: 1 = 1\n");
        printf ("Total de Divisores: 1\n");
        printf ("Soma de Todos os Divisores: 1\n\n");
        return;
    }

    int N2 = N; // Salvar o Número Original
    int Fator = 2;
    int Expoente;
    int Verificador = 1;

    int FatoresPrimos[10]; // Salvar os Fatores Primos
    int ExpoentesPrimos[10]; // Salvar os Expoentes dos Fatores Primos
    int ContadorFatores = 0; // Contar o Número Total de Fatores Primos

    while (N > 1)
    {
        printf ("Testando Fator: %d\n", Fator);
        printf ("Numero Atual: %d\n", N);

        if (ehPrimo(Fator)) // Verifica se o Fator é Primo
        {
            printf ("%d eh Primo\n", Fator);

            if (N % Fator == 0) // Verifica se o Fator divide o Atual
            {
                Expoente = 0;
                printf ("%d DIVIDE %d\n", Fator, N);
                printf ("Dividindo sucessivamente:\n");

                while (N % Fator == 0) // Faz Divisões Sucessivas
                {
                    Expoente++;
                    int R = N / Fator; // R = Resultado
                    printf ("%d / %d = %d", N, Fator, R);

                    if (R % Fator == 0 && R > 1)
                    {
                        printf (" => Continua Divisivel por %d\n", Fator);
                    }
                    else if (R > 1)
                    {
                        printf (" => NAO EH mais Divisivel por %d\n", Fator);
                    }
                    else
                    {
                        printf (" => Chegou-se em 1\n");
                    }

                    N = R;
                }

                printf ("Fator Primo: %d^%d\n", Fator, Expoente);

                FatoresPrimos[ContadorFatores] = Fator; // Armazena os Fatores Primos
                ExpoentesPrimos[ContadorFatores] = Expoente; // Armazena os Expoentes dos Fatores Primos
                ContadorFatores++;

                if (Verificador) // Mostra os Fatores Primos Parciais
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
                    printf ("Fatores Primos: ... x %d", Fator);
                    if (Expoente > 1)
                    {
                        printf ("^%d", Expoente);
                    }
                }

                if (N > 1)
                
                {
                    printf (" x [%d]", N);
                }
                
                printf ("\n");

            }
            else
            {
                printf ("%d NAO divide %d\n", Fator, N);
                printf ("Ir para o Proximo Fator.\n\n");
                Fator++;
            }
        }    
        else
        {
            printf ("%d NAO EH Primo\n", Fator);
            printf ("Ir para o Proximo Fator.\n\n");
            Fator++;
        }

        if (N > 1 && ehPrimo(N)) // Se o Número Restante for Primo, já pode encerrar a Decomposição
        {
            printf ("Numero Restante %d eh Primo\n", N);
            printf ("Fator Primo: %d^1\n", N);

            FatoresPrimos[ContadorFatores] = N; // Armazena os Fatores Primos
            ExpoentesPrimos[ContadorFatores] = 1; // Armazena os Expoentes dos Fatores Primos
            ContadorFatores++;

            if (Verificador)
            {
                printf ("Fatores Primos Finais: %d\n", N);
            }
            else
            {
                printf ("Fatores Primos Finais: ... x %d\n", N);
            }
            
            N = 1;
        }
    }

    printf ("\nNumero Decomposto: ");
    printf ("%d = ", N2);

    N = N2;
    Verificador = 1;

    for (int i = 0; i < ContadorFatores; i++)
    {
        if (!Verificador)
        {
            printf (" x ");
        }
        printf ("%d", FatoresPrimos[i]);
        if (ExpoentesPrimos[i] > 1)
        {
            printf ("^%d", ExpoentesPrimos[i]);
        }
        Verificador = 0;
    }

    printf ("\n\n");

    printf("Funcao Tau = (e1 + 1) x (e2 + 1) x ... x (ek + 1)\n");

    D = 1; // A Menor Quantidade de Divisores de um Número
    printf ("Calculo: ");

    for (int i = 0; i < ContadorFatores; i++) // Calcula o Total de Divisores
    {
        printf ("(%d + 1)", ExpoentesPrimos[i]);
        D = D * (ExpoentesPrimos[i] + 1);
        
        if (i < ContadorFatores - 1)
        {
            printf (" x ");
        }
    }
    printf (" = %d\n", D);
    printf ("Total de Divisores de %d: %d\n\n", N2, D);

    printf ("Funcao Sigma = [(p1^(e1+1) - 1)/(p1 - 1)] x [(p2^(e2+1) - 1)/(p2 - 1)] x ...\n");

    S = 1; // A Menor Soma de Todos os Divisores de um Número
    printf ("Calculo: ");

    for (int i = 0; i < ContadorFatores; i++)
    {
        int p = FatoresPrimos[i];
        int e = ExpoentesPrimos[i];

        int Potencia = 1;
        int SP = 0; // Soma Parcial dos Divisores
        
        printf ("(");
        for (int j = 0; j <= e; j++)
        {
            SP = SP + Potencia;
            if (j < e)
            {
                printf ("%d + ", Potencia);
            }
            else
            {
                printf ("%d", Potencia);
            }
            Potencia = Potencia * p;
        }
        printf (")");
        
        S = S * SP;
        
        if (i < ContadorFatores - 1)
        {
            printf (" x ");
        }
    }

    printf (" = %d\n", S);
    printf ("Soma de Todos os Divisores de %d: %d\n\n", N2, S);
}

int main()
{
    int N;
    float R; // Razão de Eficiência

    do
    {
        printf ("Digite um Numero entre 1 e 105: ");
        scanf ("%d", &N);
        printf ("\n");

        if (N < 1 || N > 105)
            printf ("Erro! O Numero deve estar entre 1 e 105!\n");
    } while (N < 1 || N > 105);

    decomporFatoresPrimos(N);

    R = (float) D / S;

    printf ("Razao de Eficiencia (%d) = %.2f\n", N, R);

    return 0;
}