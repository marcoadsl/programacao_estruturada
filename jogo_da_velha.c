/**      @file: jogo_da_velha.c
 *     @author: Marco Antônio S. Leite
 * @disciplina: Programação Estruturada - TADS *
 * Implementação do jogo "Jogo da Velha". */

#include <stdio.h>
#include <stdlib.h>

int matrix[3][3];

char check(void){
	int i;

//linhas
	for (i=0; i<3; i++){
		if(matrix[i][0] == matrix[i][1] && matrix[i][1] == matrix[i][2])
			return matrix[i][0];
	}
//colunas
	for (i=0; i<3; i++){
		if(matrix[0][i] == matrix[1][i] && matrix[0][i] == matrix[2][i])
			return matrix[0][i];
	}
//diagonais
		if(matrix[0][0] == matrix[1][1] && matrix[1][1] == matrix[2][2])
			return matrix[0][0];
		if(matrix[0][2] == matrix[1][1] && matrix[1][1] == matrix[2][0])
			return matrix[0][2];
	return ' ';		
}
void init_matriz(void){
	int i;
	int j;

	for (i=0; i<3; i++)
		for (j=0; j<3; j++)
			matrix[i][j] = ' '; 
}

void get_player_move(void){
	int x;
	int y;

	puts("Digite as coordenada para X:");
	scanf("%d %d", &x, &y);
	x--; y--;

	if(matrix[x][y] != ' '){
		puts("Posicao invalida! Tente novamente");
		get_player_move();
	}else
		matrix[x][y] = 'X';
}

void get_computeder_move(void){
	int i;
	int j;

	for (i=0; i<3; i++){
		for (j=0; j<3; j++)
			if(matrix[i][j]== ' ')
				break;
		if(matrix[i][j]== ' ')
			break;
	}
	if(i*j == 9)
		puts("Empate");
	else
		matrix[i][j] = 'O';
}

void disp_matrix(void){
	int i;

	for(i=0; i<3; i++){
		printf(" %c | %c | %c \n", matrix[i][0], matrix[i][1], matrix[i][2] );
		if (i != 2)
			puts("---|---|---");
	}
	puts("");
}

int main(void){

	char done;
	printf("Este eh o jogo da velha.\nVoce esta jogando contro o computador\n");
	done = ' ';

	init_matriz();

	do{
		disp_matrix();
		get_player_move();
		done = check();

		if(done != ' ')
			break;
		get_computeder_move();
		done = check();
	
	}while(done == ' ');
	if(done == 'X')
		puts("Vc ganhou!");
	else
		puts("Eu ganhei");
	disp_matrix();
	return 0;
}
