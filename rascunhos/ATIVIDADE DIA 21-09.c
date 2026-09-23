#include <stdio.h>

int main () {
	
    int vetor[10] = {5,10};
    int criar;
    int ler;
    int atualizar_antigo;
    int atualizar_novo;
    int deletar;
    int continuar = 1;
    int disjuntor;
    int opcao;

	while (continuar == 1) {
	
		printf ("O que deseja fazer?\n\n");
		printf ("1.CRIAR\n");
		printf ("2.LER\n");
		printf ("3.ATUALIZAR\n");
		printf ("4.DELETAR\n\n");
		scanf("%d", &opcao);
		
		//CREATE
		
		if (opcao == 1) {
			
			disjuntor = 0;
			int repetido = 0;
				
			printf ("Qual número deseja criar?\n");
			scanf ("%d", &criar);
			
			for (int i = 0; i < 10 && repetido == 0; i++) {
				if (vetor[i] == criar) {
					repetido = 1;	
				}	
			}
			
			if (repetido == 1) {
				printf ("Número já existe, tente novamente.\n");
			} else {	
				for (int i = 0; i < 10 && disjuntor == 0; i++) {
					if (vetor[i] == 0) {
						vetor[i] = criar;
						disjuntor = 1;		
					}
				}
					
				if (disjuntor == 1){
					printf ("Número criado com sucesso!\n\n");
				} else {
					printf ("O vetor está cheio!\n\n");
				}
			}
		}	
			
		//READ
		
		if (opcao == 2) {
			
			disjuntor = 0;
				
			printf ("Qual número deseja ler\n");
			scanf("%d", &ler);
		
			for (int i = 0; i < 10; i++) {
				if (vetor[i] == ler){
					printf("o número %d está na posição %d\n\n", ler, i);
					disjuntor = 1;
				}
			}
				
			if (disjuntor == 0){
				printf ("Número digitado não criado.\n\n");
			}
		}
			
		//UPDATE
		
		if (opcao == 3) {
			
			disjuntor = 0;
				
			printf ("Qual número você deseja atualizar?\n");
			scanf ("%d", &atualizar_antigo);
				
			for (int i = 0; i<10 && disjuntor == 0; i++) {
				if (vetor[i] == atualizar_antigo) {
					printf ("Qual vai ser o novo número?\n");
					scanf ("%d", &atualizar_novo);
					vetor[i] = atualizar_novo;
					disjuntor = 1;
				}	
			}
				
			if (disjuntor == 1) {
				printf("Número atualizado com sucesso!\n\n");
			} else {
				printf("Número não encontrado!\n\n");
			}
		}
			
		//DELETE
		
		if (opcao == 4) {
			
			disjuntor = 0;
				
			printf ("Qual número deseja deletar?\n");
			scanf ("%d", &deletar);
				
			for (int i = 0; i < 10 && disjuntor == 0; i++) {
				if (vetor[i] == deletar) {
					vetor[i] = 0;
					disjuntor = 1;
				}
			}
				
			if (disjuntor == 1) {
				printf("Número deletado com sucesso!\n\n");
			} else {
				printf ("Número não encontrado.\n\n");
			}
		}
			
		//CONTINUAR?
			
		printf ("Deseja continuar? (1/0)\n");
		scanf ("%d", &continuar);
	}
}