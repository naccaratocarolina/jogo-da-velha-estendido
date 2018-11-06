#include "jogo.h"
#define N 9

//assinatura da funcao verificaVitoriaEstendido para que ela possa ser usada antes de ser definida
int verificaVitoriaEstendido (int tabuleiro[N][N], int dimensao);

int verificaVitoria (int tabuleiro[N][N], int dimensao) { //funcao que trata das vitorias tradicionais
	//Dicionario de dados
	int jogador;                                      //designa o jogador 1 (X) ou 0 (O) posteriormente
	int somaLinha, somaColuna;                        //somatorios correspondentes ao caso 1 e 2
	int somaDiagonalPrimaria, somaDiagonalSecundaria; //somatorios correspondentes ao caso 3
	int i, j;                                         //variaveis auxiliares - linha e coluna, respectivamente

	//Corpo do programa
	for (i=0; i<dimensao; i++) { //loop principal que percorre as linhas da matriz
		//setando os valores iniciais das variaveis da funcao
		somaLinha = 0;
		somaColuna = 0;
		somaDiagonalPrimaria = 0;
		somaDiagonalSecundaria = 0;

		for (j=0; j<(dimensao-1); j++) { //loop principal que percorre as colunas da matriz
			//Caso 1: Linhas
			if ((tabuleiro[i][j] == tabuleiro[i][j+1]) && (tabuleiro[i][j]) ){
				somaLinha++; //eh salva uma ocorrencia na variavel de soma correspondente a linha
				jogador = tabuleiro[i][j]; //a jogada eh salva na coordenada [i, j], correspondente a linha
			}
			//Caso 2: Colunas
			if ((tabuleiro[j][i] == tabuleiro[j+1][i]) && (tabuleiro[j][i])) { 
				somaColuna++; //eh salva uma ocorrencia na variavel de soma correspondente a coluna
				jogador = tabuleiro[j][i]; //a jogada eh salva na coordenada [j, i], correspondente a coluna
			}
		}

		//Caso 3: Diagonais
		if ((i+1) != dimensao) { //n entendi esse if... ele eh mesmo necessario?
			//Diagonal Primaria
		  //if ((jogador = tabuleiro[i][i] == tabuleiro[i+1][i+1]) && (tabuleiro[i][i])) {
				somaDiagonalPrimaria++; //eh salva uma ocorrencia na variavel de soma correspondente a diagonal principal
				jogador = tabuleiro[i][i]; //a jogada eh salva na coordenada [i, i], correspondente a diagonal principal
			}
			//Diagonal Secundaria
			if ((tabuleiro[i][dimensao-1-i] == tabuleiro[i+1][dimensao-i]) && (tabuleiro[i][dimensao-1-i])) {
				somaDiagonalSecundaria++; //eh salva uma ocorrencia na variavel de soma correspondente a diagonal secundaria
				jogador = tabuleiro[i][dimensao-1-i]; //a jogada eh salva na coordenada [i, dimensao-1-i], correspondente a diagonal secundaria
			}
		}

		//Verifica se houve vitoria ate aqui
		if ((somaLinha == (dimensao-1)) || (somaColuna == (dimensao-1)) || (somaDiagonal == (dimensao-1)) || (somaOutraDiagonal == (dimensao-1))) 
			return jogador; //retorna o jogador vencedor
    }

    //Caso nenhum dos casos tenham sido atendidos, a verificacao continua na funcao verificaVitoriaEstendido
    return verificaVitoriaEstendido(tabuleiro, dimensao);
}

int verificaVitoriaEstendido (int tabuleiro[N][N], int dimensao){
    //Dicionario de dados
    int jogador;              //designa o jogador 1 (X) ou 0 (O) posteriormente
    int somaDiagonalInferior; //variavel correspondente ao caso 4
    int somaDiagonalSuperior; //variavel correspondente ao caso 5
    int somaDiagonalBorda;    //variavel correspondente ao caso 6
    int dimAux, dimAux2;      //variaveis auxiliares
    int acresce, decresce;    //variaveis auxiliares
    int i, j;                 //variaveis auxiliares - linha e coluna, respectivamente

    //Corpo do programa
    for (i=0; i<dimensao; i++) { //loop principal que percorre as linhas da matriz
    //setando os valores iniciais das variaveis da funcao
    jogador = 0;
    dimAux = dimensao-1;
    dimAux2 = dimensao-1;
    somaDiagonalInferior = 0;
    somaDiagonalSuperior = 0;
    somaDiagonalBorda = 0;
    decresce = i;
    acresce = 0;


        for(j=0; j<dimensao; j++) { //loop principal que percorre as colunas da matriz
        	//Caso 4:
            if ((j+i) < (dimensao-1)){
                if((tabuleiro[j+i][j] == tabuleiro[j+1+i][j+1]) && (tabuleiro[j+i][j])) {
                     somaDiagonalInferior++; //eh salva uma ocorrencia na variavel de soma correspondente a diagonal inferior
                     jogador = tabuleiro[j+i][j]; //a jogada eh salva na coordenada [j+1+i, j], correspondente a diagonal inferior
                }
            
            } else {
                if((tabuleiro[dimAux][j] == tabuleiro[dimAux-1][j+1]) && (tabuleiro[dimAux][j])) {
                    somaDiagonalInferior++; //eh salva uma ocorrencia na variavel de soma correspondente a diagonal inferior
                    jogador = tabuleiro[dimAux][j]; //a jogada eh salva na coordenada [dimAux, j], correspondente a diagonal inferior
                }                
                dimAux--;
            }


            //Caso 5:
            if(decresce){
                if((tabuleiro[decresce][j] == tabuleiro[decresce-1][j+1]) && (tabuleiro[decresce][j])){
                    somaDiagonalSuperior++; //eh salva uma ocorrencia na variavel de soma correspondente a diagonal superior
                    jogador = tabuleiro[decresce][j]; //a jogada eh salva na coordenada [decresce, j], correspondente a diagonal superior
                }
                decresce--;
            } else if (acresce!=i){
                if((tabuleiro[acresce][j] == tabuleiro[acresce+1][j+1]) && (tabuleiro[acresce][j])) {
                    somaDiagonalSuperior++; //eh salva uma ocorrencia na variavel de soma correspondente a diagonal superior
                    jogador = tabuleiro[acresce][j]; //a jogada eh salva na coordenada [acresce, j], correspondente a diagonal superior
                }
                acresce++;
            }

            //Caso 6:
            if ((j+i) < (dimensao-1)){
                if((tabuleiro[j][j+1]==tabuleiro[j+1][j+1+i]) && (tabuleiro[j][j+i])){
                     somaDiagonalBorda++; //eh salva uma ocorrencia na variavel de soma correspondente a diagonal borda
                     jogador = tabuleiro[j][j+1]; //a jogada eh salva na coordenada [j, j+1], correspondente a diagonal borda
                }                
            } else {
                if((tabuleiro[j][dimAux2] == tabuleiro[j+1][dimAux2-1]) && (tabuleiro[j][dimAux2])) {
                    somaDiagonalBorda++; //eh salva uma ocorrencia na variavel de soma correspondente a diagonal borda
                    jogador = tabuleiro[j][dimAux2]; //a jogada eh salva na coordenada [j, dimAux2], correspondente a diagonal borda
                }                
                dimAux2--;
            }
        }

        //Verifica se houve vitoria ate aqui
        if((somaDiagonalInferior == (dimensao-1)) || (somaDiagonalSuperior == (dimensao-1)) || (somaDiagonalBorda == (dimensao-1))) {
            return jogador; //retorna o jogador vencedor
        }
    }

    //Fim dos casos de vitoria e da verificacao dos mesmos
    return 0;
}

void verificaGanhador (int jogador) {
	if (!jogador) {
		printf("Empate \n");
	} else {
		if (jogador==1)
       		printf("X ganhou ");
	    else
	      	printf("O ganhou ");
	}

	printf("\n------FIM DE JOGO------\n");
}

void exibeTabuleiro(int tabuleiro[N][N], int dimensao){
	
	for(int a=0; a<dimensao; a++){
		printf("  %d ",a);
	}
	printf("\n");
	for(int i=0; i<dimensao; i++){
		printf("%d", i );
		for(int j=0; j<dimensao;j++){
			if(tabuleiro[i][j]==1)
				printf(" X ");
			else if(tabuleiro[i][j]==2)
				printf(" O ");
			else
				printf("   ");
			if(j!= (dimensao-1))
				printf("|");
		}
		printf("\n");
	}
}

int menu(int *modo, int *dimensao){
	int opcao;

	puts("\n------------ MENU ------------");
	

	printf("1.Jogar\n0.Sair\n\n:");
	scanf("%d",&opcao);

	while((opcao > 1)||(opcao < 0)){
		printf("\nOpcao invalida!\n");
		printf("1.Jogar\n0.Sair\n\n:");
		scanf("%d",&opcao);
	}
	
	if(!opcao)
		return 0;
	else{
		printf("\nEscolha o modo de jogo: \n1.Um jogador\n2.Dois jogadores\n\n:");
		scanf("%d",modo);
		
		while((*modo > 2)||(*modo < 1)){
			printf("\nOpcao invalida!\n");
			printf("\nEscolha o modo de jogo: \n1.Um jogador\n2.Dois jogadores\n\n:");
			scanf("%d",modo);
		}

		printf("\nEscolha as dimensoes do tabuleiro:\n4. 4x4\n5. 5x5\n6. 6x6\n7. 7x7\n8. 8x8\n9. 9x9\n\n:");
		scanf("%d",dimensao);
		
		while((*dimensao > 9)||(*dimensao < 4)){
			printf("\nOpcao invalida!\n");
			printf("\nEscolha as dimensoes do tabuleiro:\n4. 4x4\n5. 5x5\n6. 6x6\n7. 7x7\n8. 8x8\n9. 9x9\n\n:");
			scanf("%d",dimensao);
		}

		system("clear");
		
		return 1;
	}
}


void zeraTabuleiro(int tabuleiro[N][N], int dimensao){

	for(int linha=0; linha<dimensao; linha++){
		for(int coluna=0; coluna<dimensao; coluna++){
			tabuleiro[linha][coluna]=0;
		}		
	}
}

int jogo(int dimensao, int *ganhador, int modo){
	int vez = 0 ;
	char jogador;
	int tabuleiro[N][N];
	int linha;
	int coluna;

	zeraTabuleiro(tabuleiro, dimensao);
	puts("----- A partida comecou!! -----\n");
	exibeTabuleiro(tabuleiro,dimensao);

	do {		
		if (vez%2)
			jogador = 'X';
		else
			jogador = 'O';
		printf("\n--------- Vez de %c ---------\n", jogador);

		if ((modo == 1)&&(vez%2)) {
			srand (time(NULL));
			printf("\nJogada do Computador\n");

			do {
				linha = rand() % dimensao;
				coluna = rand() % dimensao;
			} while(tabuleiro[linha][coluna]);

		} else {
			do {
				printf("Linha: ");
				scanf("%d", &linha);

				printf("Coluna: ");
				scanf("%d", &coluna);

				if ((tabuleiro[linha][coluna])||(linha>=dimensao)||(coluna>=dimensao)){
					puts("\nEntrada invalida! Tente outra!");
				}
			} while ((tabuleiro[linha][coluna])||(linha>=dimensao)||(coluna>=dimensao));
			
		}		

		printf("\n");

		if (vez%2)
			tabuleiro[linha][coluna] = 1;
		else
			tabuleiro[linha][coluna] = 2;

		system("clear");

		exibeTabuleiro(tabuleiro,dimensao);

		if (vez>4) {
			*ganhador = verificaVitoria(tabuleiro, dimensao);
			if (*ganhador)
				return *ganhador;
		}
		vez++;

	} while (vez<(dimensao*dimensao));
	return 0;
}

int main (void) {
	int dimensao;
	int modo;
	int jogador;
	
	while (menu(&modo,&dimensao)) {		
		jogador = 0;

		jogo(dimensao, &jogador, modo);	
		
		verificaGanhador(jogador);
	}
	
	return 0;	
}