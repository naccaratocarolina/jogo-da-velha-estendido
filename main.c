#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "jogo.h"

int main (void){
	int dimensao;
	int modo;
	int jogador;
	
	while (menu(&modo, &dimensao)){		
		jogador = 0;

		jogo(dimensao, &jogador, modo);	
		
		verificaGanhador(jogador);
	}
	
	return 0;	
}