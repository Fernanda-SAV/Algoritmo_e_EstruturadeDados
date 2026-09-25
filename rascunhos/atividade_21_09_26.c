//Fernanda Sousa de Assunção Vale e Luiz Ruifeng Mei - Atividade - 21/09/2026

#include <stdio.h>

int main () {
    
    int numeros[10];
    int quantidade=0;
    int opcao;
    int posicao;
    int novoValor;
    int busca;
    int encontrado;

    do{
        printf("====Lista de Números cadastrados====");
        printf("1 - Cadastrar\n");
        printf("2 - Buscar\n");
        printf("3 - Atualizar\n");
        printf("4 - Excluir\n");
        printf("0 - Sair\n");

        printf("Escolha uma opção:");
        scanf("%d", &opcao);


        //CREATE
      if (opcao == 1) {
				
			printf ("Qual número deseja criar?\n");
			scanf ("%d", &criar);
			
			if (quantidade <= 9) {
				vetor[quantidade] = criar;
				quantidade++;
				printf ("Número criado com sucesso!\n");
			} else {
				printf ("O vetor está cheio, delete algum número!\n");
			}
        }

        //READ
        else if (opcao == 2){
            
            int disjuntor_read= 0;
			int vezes = 0;
				
			printf ("Qual número deseja buscar\n");
			scanf("%d", &ler);
		
			for (int i = 0; i <= quantidade; i++) {
				if (vetor[i] == ler) {
					vezes++;
					disjuntor_read = 1;
				}
			}
			
			if (vezes != 0) {
				printf ("O número buscado está contido em %d posição(ões), sendo ela(s):\n", vezes);
			}
			
			for (int i = 0; i < quantidade; i++) {
				if (vetor[i] == ler) {
					printf ("Posição %d\n", i);
				}
			}
				
			if (disjuntor_read == 0) {
				printf ("Número digitado não criado.\n\n");
			}
		}
        
        //UPDATE
        else if (opcao == 3){

            printf ("Qual a posição deseja trocar?\n");
            scanf("%d", &posicao);

            printf("Qual vai ser o novo número?\n");
            scanf("%d", &novoValor);

            numeros[posicao] = novoValor;

            printf ("O número foi atualizado");

    }

        //DELETE
        else if (opcao == 4){
            printf ("Qual a posiução que deseja deletar?\n");
            scanf ("%d", &posicao);

            p
        }
    }



}