Passagem de Matrizes e Vetores como Parâmetro

            Para passar uma matriz ou vetor como parâmetro, basta declarar o parâmetro da mesma forma que a matriz/vetor foi declarado.

            Por definição da linguagem C, um vetor é sempre passado por referência, logo, qualquer alteração em seus elementos, altera a variável usada como parâmetro na chamada da rotina.

    #include <stdio.h>

    #define TAM_MAX 10

    void ImprimeVet (int Tam, int Vet[TAM_MAX])
    {
        int i;
        for (i=0; i< Tam; i++)
        {
          printf("%d", Vet[i]);
        }    
    }

    int main()
    {
      int Notas[TAM_MAX];

        ImprimeVet(TAM_MAX, Notas); // Passa o vetor 'Notas' como
                                     // parâmetro

        return 0;

    }
Exemplos com Matrizes


    #define NLIN 10
    #define NCOL 10
    int Matriz[NLIN][NCOL];

Preencher uma matriz com um dado

   for(i=0; i < NLIN; i++)     
       for(j=0; j < NCOL; j++)    
        Matriz[i][j] = 30;

Somar um número a uma linha/coluna de uma matriz

void SomaValorNaColuna(int Valor, int Matriz[NLIN][NCOL], int Coluna)
{
   for(i=0; i < NLIN; i++) // para cada linha de 'Coluna'
     Matriz[i][Coluna] = Matriz[i][Coluna] + 30;
}

Criar uma matriz identidade

void CriaIdent(int Colunas, int linhas, int Matriz[NLIN][NCOL])
{
  
}

Criar uma matriz transposta

void CriaTransp(int Colunas, int linhas,
                int Matriz[NLIN][NCOL], int Trasposta[NLIN][NCOL])
{
  
}

Cria uma rotina que some duas matrizes

void SomaMatrizes(int Colunas, int linhas,
                  int MatrizA[NLIN][NCOL], int MatrizB[NLIN][NCOL],
                  int MatrizSOMA[NLIN][NCOL])
{
  
}

Cria uma rotina que multiplique duas matrizes

void MultMatrizes(int Colunas, int linhas,
                  int MatrizA[NLIN][NCOL], int MatrizB[NLIN][NCOL],
                  int MatrizMULT[NLIN][NCOL])
{

}

Acesso a uma linha de uma matriz

Uma linha de uma matriz é vista, em C, como sendo um vetor. O acesso à linha é feito informando apenas a primeira das dimensões da matriz.
No exemplo a seguir as funções InicializaVet e ImprimeVet são usadas para manipular os dados de cada uma das linhas de uma matriz.

#include <stdio.h>

#define NLinhas 10
#define NColunas 5

void ImprimeVet(int Vet[NColunas])
{
    int i;
    for(i = 0; i < NColunas; i++) {
    printf("%d ", Vet[i]);
    }
}
void InicializaVet(int Vet[NColunas], int n)
{
    int i;
    for(i = 0; i < NColunas; i++) {
    Vet[i] = i * n;
    }
}

int main()
{
    int Matriz[NLinhas][NColunas];

    int i;
    for(i = 0; i < NLinhas; i++) {
        InicializaVet(Matriz[i], i);
        printf("\n");
    }

    for(i = 0; i < NLinhas; i++) {
        ImprimeVet(Matriz[i]);
        printf("\n");
    }
    return 0;
}


Cuidados com os limites dos índices de Matrizes e Vetores

A linguagem C não faz nenhum teste de verificação dos índices usados para acessar os elementos de um vetor.

Isto significa que, se estes limites não forem respeitados, resultados indesejados serão obtidos.

No exemplo a seguir, a matriz int M[2][3] é acessada com índices fora dos limites corretos, o que gera um resultado diferente do esperado.
#include <stdio.h>


void ImprimeVet(int Vet[3])
{
    int i;
    for(i = 0; i < 3; i++) {
    printf("%d ", Vet[i]);
    }
}

int main()
{
    int Matriz[2][3];

    int i;
    for(i = 0; i < 10; i++)
    {
        Matriz[0][i] = i;  // a matriz tem 3 colunas, mas o laço do for vai até 10
    }

    for(i = 0; i < 2; i++) {
        ImprimeVet(Matriz[i]);
    printf("\n");
    }
    return 0;
}

No caso deste exemplo, no primeiro for, após atribuir um valor para a posição Matriz[0][2], o código avança sobre os dados da segunda linha, mesmo sendo a linha definida como 0, como se pode observar na saída do programa, apresentada a seguir:

0 1 2
3 4 5

Outro exemplo, desta vez usando strings, também ocorre o mesmo problema, neste caso porque a string colocada em cada linha da matriz é maior do que os espaço disponível para armazená-la.
#include <stdio.h>
#include <string.h>

void ImprimeVet(int Vet[3])
{
    int i;
    for(i = 0; i < 3; i++) {
    printf("%d ", Vet[i]);
    }
}

int main()
{
    char Texto[2][17];

    int i;

    strcpy(Texto[0], "Aula de Programacao");  // esta string não cabe na linhada matriz
                                             
    strcpy(Texto[1], "em linguagem C."); 

    for(i = 0; i < 2; i++) {
        printf("%s\n", Texto[i]);
    }
    return 0;
}

A saída do programa é :

Aula de Programacem linguagem C.
em linguagem C.

Passagem dos Elementos de Matrizes e Vetores como Parâmetro (por valor)

A passagem dos elementos de um vetor como parâmetro é idêntica à passagem de uma variável. Ou seja, quando a passagem for por valor usa-se vet[i] e quando for por referência usa-se &vet[i].
    #include <stdio.h>
    #include <string.h>
    void Imprime (int N) // função com um parâmetro por valor
    {
        printf("%d", N);
    }

    int main()
    {
        int i;

        int Vet[10];

        for(i = 0; i < 10; i++)
        {
            Vet[i] = i;
        }      
        for (i=0; i< 10; i++)
        {
           Imprime(Vet[i]);// passa o valor de cada um dos elementos do vetor como parâmetro
        }
        return 0;
      }

A saída do programa é :
0123456789

  Passagem dos Elementos de Matrizes e Vetores como Parâmetro (por referência)

A passagem dos elementos de um vetor como parâmetro é idêntica à passagem de uma variável. Ou seja, quando a passagem for por valor usa-se vet[i] e quando for por referência usa-se &vet[i].

   #include <stdio.h>
   #include <string.h>

    void Imprime (int N) // função com um parâmetro por valor
    {
        printf("%d", N);
    }

   void Set (int *N, int i) // função com um parâmetro por referência
    {
      *N = i;
    }

   int main()
    {
        int i;

        int Vet[10];

        for (i=0; i< 10; i++)
        {
           Set(&Vet[i], i); // Note que é preciso colocar o '&' antes
                          // de Vet[i] pois a função 'Incr' espera um
                          // parâmetro por REFERÊNCIA

           Imprime(Vet[i]); // Note que NÃO se deve colocar nada antes
                            // de Vet[i] pois a função 'Imprime' espera um
                            // parâmetro por VALOR

        }

        return 0; 

      }

A saída do programa é :
0123456789


