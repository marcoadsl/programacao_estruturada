Exemplos com Vetores

    int Vetor[5];  // declara um vetor de 5 posições

    int Matriz[5][3]; // declara uma matriz de 5 linhas e 3 colunas

        Vetor[0] = 9; // coloca 9 na primeira posição do vetor
        Vetor[4] = 30 // coloca 30 na última posição do vetor

        Matriz[0][1] = 15; // coloca 15 na célula que está na primeira linha
                           // e na segunda coluna da matriz

Preenchimento de um vetor com um dado

     for(i=0; i<5; i++)                  for(i=0; i<=4; i++)
        Vetor[i] = 30;                      Vetor[i] = 30;      

Colocar os números de 1 a 5 em Vetor

     for(i=0; i<5; i++)
       Vetor[i] = i+1;

Colocar os números de 5 a 1 em Vetor

     for(i=0; i<5; i++)
       Vetor[i] = 5-i;

Uso de Constantes para definir o tamanho de um vetor

    #define TAM_MAX 10

    double VetReais[TAM_MAX];

    for(i=0; i<TAM_MAX; i++)
       VetReais[i] = TAM_MAX - i;  // coloca 5,4,3,2,1 no vetor

Copiar os dados de um vetor para outro

    #define TAM_MAX 10

    double VetReais[TAM_MAX], Copia[TAM_MAX];

    for(i=0; i<TAM_MAX; i++)
       VetCopia[i] = VetReais[i];  // Copia os dados de um vetor
                                   // para outro

Copiar os dados de um VET1 para as primeiras 5 posições de COPIA e VET2 para as outras 5

    #define TAM_MAX 10

    // Note que a declaração do vetor "Cópia" cria o dobro de posições
    double Vet1[TAM_MAX], Vet2[TAM_MAX], Copia[TAM_MAX*2];

    for(i=0; i<TAM_MAX; i++)
       VetCopia[i] = Vet1[i];  // Copia os dados do primeiro vetor

    for(i=0; i<TAM_MAX; i++)   // Copia os dados do segundo vetor
       VetCopia[i+TAM_MAX] = Vet2[i]; 

// ****** Pergunta: Como fazer a cópia usando um único comando for ?

Leitura dos dados de um um vetor               

  #define TAM_MAX 10

    double Vet1[TAM_MAX];

    for(i=0; i<TAM_MAX; i++)
       scanf("%f",&Vet1[i]);

Encontrar o maior valor dentro de um vetor               

  #define TAM_MAX 10

    double Vet1[TAM_MAX];
    double Maior;

    for(i=0; i<TAM_MAX; i++)
       scanf("%f",&Vet1[i]);// le os   dados

    Maior = Vet1[0];  // assume que o primeiro é o maior
    for(i=0; i<TAM_MAX; i++)
       if Vet1[i] > Maior
          Maior = Vet1[i];

    printf("O maior elemento é %f\n",Maior);

// ****** Pergunta: Como fazer a mesma busca e imprimir também a
// ****** posição do dado dentro do vetor. Tente fazer isto usando
// ****** apenas 1 variável.

Crie um programa que copie para um vetor os elementos de outro em ordem crescente.

// A ideia aqui é encontrar o menor elemento do vetor 1 e colocar no vetor 2. Tirar este número de vet1, por exemplo,
// colocando no seu lugar, no vetor 1, um número grande e recomeçar a busca pelo novo número menor.

  #define TAM_MAX 10

    double Vet1[TAM_MAX], VetOrdenado[TAM_MAX];
    double Menor, Maior;

    for(i=0; i<TAM_MAX; i++)
       scanf("%f",&Vet1[i]);// le os   dados

    PosMaior = 0;  // assume que o maior está na 1a. posição
    for(i=0; i<TAM_MAX; i++)
       if Vet1[i] > Vet1[PosMaior]
          PosMaior = i;   // acha a posição do maior

    for(j=0; j<TAM_MAX;j++)
    {
      PosMenor = 0;  // assume que o primeiro é o menor
      for(i=0; i<TAM_MAX; i++)
         if Vet1[i] < Vet1[PosMenor]
           PosDoMenor = i;
      VetOrdenado[j]= Vet1[PosMenor]; // copia menor para o novo vetor
// inutiliza a posição do menor colocando nela um número grande
      Vet1[PosMenor] = Vet1[PosMaior]; // no caso o maior do vetor
                              
   }

   for(i=0; i<TAM_MAX; i++)
       print("%f\n",VetOrdenado[i]);// Imprime os dados
