#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
   int valor;
   struct nodo *prox;
   struct nodo *ant;   
}Nodo;

Nodo *inicio = NULL, *fim = NULL;
int tamanho = 0;       

void insere(int elemento){
	Nodo *novo;
	
	
	novo = (Nodo*) malloc (sizeof (Nodo));
	novo->valor = elemento;
	novo->prox = NULL;
	novo->ant = NULL;

    if (inicio == NULL){
		inicio = novo;
	}
	else{
		fim->prox = novo;
		novo->ant = fim;
	}
	
	fim = novo;
    tamanho++;
    
}

void remover(int elemento){
	Nodo *aux;
	
	aux = inicio;
	
	while(aux != NULL && aux->valor != elemento){
		aux = aux->prox;	
	}
	
	if (aux == NULL)
		printf("Elemento nao esta na lista...\n");
	
	else{
		if (aux == inicio && aux == fim){
				inicio = fim = NULL;
		}
		
		else if (aux == inicio){
			inicio = inicio->prox;
			inicio->ant = NULL;
		}
		
		else if (aux == fim){
			fim = fim->ant;
			fim->prox = NULL;
		}
		
		else{
		aux->ant->prox = aux->prox;
		aux->prox->ant = aux->ant;
		}
		
		printf("Elemento %d removido!", aux->valor);
		free(aux);	
	}
}

void mostra_inicio (){
	Nodo *aux = inicio;
	
    printf("\n");
	printf("NULL <-- "); 
	while (aux != NULL){
		if ((aux == inicio && aux->prox == NULL) || aux == fim)
			printf ("%d --> ", aux->valor);
		else
			printf ("%d <--> ", aux->valor);	
		aux = aux->prox;
	}
	printf("NULL "); 
	printf("\n");
}

void mostra_fim (){
	Nodo *aux = fim;
	
    printf("\n"); 
	printf("NULL <-- "); 
	while (aux != NULL){
		if ((aux == fim && aux->ant == NULL) || aux == inicio)
			printf ("%d --> ", aux->valor);
		else
			printf ("%d <--> ", aux->valor);	
		aux = aux->ant;
	}
	printf("NULL "); 
	printf("\n");
}

void procura_valor(int elemento){
	Nodo *aux;
	
	aux = inicio;
    int cont = 1; 
	
	while(aux != NULL && aux->valor != elemento){
		aux = aux->prox;
		cont++;
	}
	
	if (aux == NULL){
		printf("Elemento nao esta na lista...\n");
		} else if (aux->valor == elemento){
			printf("Elemento encontrado na posicao: %d\n", cont);
			}
	
	}

void procura_posicao(int elemento){
    Nodo *aux;
	
	aux = inicio;
    int cont = 1; 
	
	while(aux != NULL && cont != elemento){
		aux = aux->prox;
		cont++;
	}
	
	if (aux == NULL){
		printf("Posicao nao encontrada na lista...\n");
		} else if (cont == elemento){
			printf("Elemento nesta posicao: %d\n", aux->valor);
			}
    }

void remover_n_maior(){
	//remover o n esimo maior elemento
	}

void remover_n_menor(){
	//remover o n esimo menor elemento da lista
	}
	
void troca_posicao(){
	//trocar dois elementos de posicao com base nas posicao
	//informadas pelo usuario
	}
	
void mostra_tamanho(){
	printf("Tamanho da lista: %d\n", tamanho);
	}
	
void limpar_lista(){
	//
 }
 

int main(void) {
   int elemento;
   int opcao;
   
   do{
		printf ("\n 1 - Insere elemento na lista"); 
		printf ("\n 2 - Procurar elemento por valor"); 
		printf ("\n 3 - Procurar elemento por posicao");
		printf ("\n 4 - Remover um elemento da lista");
		printf ("\n 5 - Remover o n-esimo maior elemento da lista");
		printf ("\n 6 - Remover o n-esimo menor elemento da lista");
		printf ("\n 7 - Trocar elementos de posicao");
		printf ("\n 8 - Mostrar o tamanho da lista");
		printf ("\n 9 - Mostrar lista do inicio ate o fim");
		printf ("\n10 - Mostrar a lista do fim ao inicio");
		printf ("\n11 - Limpar a lista");
		printf ("\n0 - Sair do programa");
		printf ("\nOpcao? ");
		scanf ("%d", &opcao);
		
		switch (opcao){
			case 0:
				printf("Encerrando o programa...\n");
				break;
			case 1:
				printf ("\nInforme valor a ser inserido: ");
				scanf ("%d", &elemento);
				insere(elemento);
				mostra_inicio();
				break;
			case 2:
			    printf ("\nInforme o valor que deseja procurar: ");
				scanf ("%d", &elemento);
				procura_valor(elemento);
				mostra_inicio();
				break;
			case 3:
			    printf ("\nInforme a posicao que deseja procurar: ");
				scanf ("%d", &elemento);
				procura_posicao(elemento);;
				mostra_inicio();
				break;
			case 4:
					if (inicio != NULL){
					printf ("\nInforme valor a ser removido: ");
					scanf ("%d", &elemento);
					remover(elemento);
					if (inicio != NULL)
						mostra_inicio();
				}
				else
					printf("Lista vazia...\n");
				break;
			case 5:
			    remover_n_maior();
				break;
			case 6:
				remover_n_menor();
				break;
			case 7:
				troca_posicao();
				break;
			case 8:
                mostra_tamanho();
				break;
			case 9:
				if (inicio != NULL)
					mostra_inicio();
				else
					printf("Lista vazia...\n");
				break;
			case 10:
				if (inicio != NULL)
					mostra_fim();
				else
					printf("Lista vazia...\n");
				break;
			case 11:
				limpar_lista();
				break;
			default:
				printf("Opcao invalida!\n");
				mostra_inicio();
				break;	
			}
	}while(opcao != 0);
}
