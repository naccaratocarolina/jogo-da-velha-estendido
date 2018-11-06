/*
========================================================================================================
Nome: jogo.h
Autores: Lorena Mamede e Carolina Naccarato
Descricao: Neste arquivo pode-se encontram a chamada de todas as funcoes do arquivo jogo.c, assim como
o algoritmo implementado para a criacao do codigo em c.

()
*
: 
========================================================================================================
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//int verificaVitoriaEstendido (int tabuleiro[N][N], int dimensao); ???

int verificaVitoria (int tabuleiro[N][N], int dimensao); //funcao que trata das vitorias tradicionais
/*
0- Dicionario de dados
1- loop principal que percorre as linhas da matriz (tabuleiro)
		1.1- Define o valor inicial igual a zero para todas as variaveis da funcao
	2- loop principal que percorre as colunas da matriz
		2.1- Caso 1: Linhas
			2.1.1- Garantir que a posicao tabuleiro[i][j] seja igual a posicao seguinte tabuleiro[i][j+1], percorrendo a linha
			2.1.2- Alem disso, garantir que o loop nao ira extrapolar as dimensoes do tabuleiro[i][j]
		Se ambas as condicoes forem atendidas, adicionar uma ocorrencia na variavel somaLinha

		2.2- Caso 2: Colunas
			2.2.1- Garantir que a posicao tabuleiro[j][i] seja igual a posicao seguinte tabuleiro[j+1][i], percorrendo a coluna
			2.2.2- Alem disso, garantir que o loop nao ira extrapolar as dimensoes do tabuleiro[j][i]
		Se ambas as condicoes forem atendidas, adicionar uma ocorrencia na variavel somaColuna

	3- Caso 3: Diagonais
	Condicao ((i+1) != dimensao)
		3.1- Diagonal Primaria
			3.1.1- Garantir que a posicao tabuleiro[i][i] seja igual a posicao seguinte tabuleiro[i+1][i+1], percorrendo a diagonal primaria
			3.1.2- Alem disso, garantir que o loop nao ira extrapolar as dimencoes do tabuleiro tabuleiro[i][i]
		Se ambas as condicoes forem atendidas, adicionar uma ocorrencia na variavel somaDiagonalPrimaria

		3.2- Diagonal Secundaria
			3.2.1- 
			3.2.2- 
		Se ambas as condicoes forem atendidas, adicionar uma ocorrencia na variavel somaDiagonalSecundaria
4- Realiza a verificacao de vitoria:
	4.1- Se a soma de alguma das variaveis auxiliares da funcao (somaLinha, somaColuna, somaDiagonalPrimaria, somaDiagonalSecundaria) for 
	igual a dimensao - 1 (precisamos subtrair 1 pois a contagem da dimensao comeca no 0), logo sabemos que o jogador venceu a partida com 
	o caso de vitoria correspondente
	4.2- Se nenhuma das condicoes acima forem atendidas, a funcao verificaVitoria chama a funcao verificaVitoriaEstendido
*/

int verificaVitoriaEstendido (int tabuleiro[N][N], int dimensao);
/*
0- Dicionario de dados
1- loop principal que percorre as linhas da matriz (tabuleiro)
	2- loop principal que percorre as colunas da matriz
*/

void verificaGanhador (int jogador);
/*
0- Dicionario de dados
*/

void exibeTabuleiro (int tabuleiro[N][N], int dimensao);
/*
0- Dicionario de dados
*/

int menu (int *modo, int *dimensao);
/*
0- Dicionario de dados
*/

void zeraTabuleiro (int tabuleiro[N][N], int dimensao);
/*
0- Dicionario de dados
*/

int jogo (int dimensao, int *ganhador, int modo);
/*
0- Dicionario de dados
*/

