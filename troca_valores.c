
/***********************************************************
 *	Author: Marco Antônio Da Silva Leite;
 *	
 *	Disciplina: Programação Estruturada
 *	
 *	Script: Ponteiros ;
 *
 * ********************************************************/


/***********************************************************
 *	
 * Escreva uma função CALCULA que:
 * 
 * receba como parâmetros duas variáveis inteiras, X e Y;
 * retorne em X a soma de X e Y;
 * retorne em Y a subtração de X e Y.
 * 
 * ********************************************************/


#include<stdio.h>

void calcula (int *x, int *y){
	*x = *x + *y;
	*y = *x -2 * *y;
	
}


int main(){	
	
	int x, y;
	
	printf("Digite o Valor de X: ");
	scanf("%d", &x);
	
	printf("Digite o Valor de Y: ");
	scanf("%d", &y);
	
	
	calcula(&x, &y);
	printf("O Resultado da Soma(X) é: %d\n", x);
	
	printf("O Resultado da Subtração(Y) é: %d\n", y);
	
	return 0;
	
	}
