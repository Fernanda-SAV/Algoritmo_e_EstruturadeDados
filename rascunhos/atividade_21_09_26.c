//Fernanda Sousa de Assunção Vale e Luiz Ruifeng Mei - Atividade - 21/09/2026

#include <stdio.h>

int main () {
    
    int numeros[10];
    int quantidade=0;
    int opcao;
    int valor;
    int posicao;
    int novoValor;
    int vezes;

    do{
        printf("====Lista de Números cadastrados====\n");
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
			scanf ("%d", &valor);
			
			if (quantidade <= 9) {
				numeros[quantidade] = valor;
				quantidade++;
				printf ("Número criado com sucesso!\n");
			} else {
				printf ("O vetor está cheio, delete algum número!\n");
			}
        }

        //READ
        else if (opcao == 2){
            
			vezes = 0;
				
			printf ("Qual número deseja buscar\n");
			scanf("%d", &valor);
		
			for (int i = 0; i < quantidade; i++) {
				if (numeros[i] == valor) {
					vezes++;
				}
			}
			
			if (vezes == 0) {
                printf("Número não encontrado.\n");
            } else {
                printf("O número está em %d posição(ões):\n", vezes);

                for (int i = 0; i < quantidade; i++) {
                    if (numeros[i] == valor) {
                        printf("Posição %d\n", i);
                    }
                }
            }
		}
        
    // UPDATE
        else if (opcao == 3) {
            printf("Qual número deseja trocar? ");
            scanf("%d", &valor);

            posicao = -1;

            for (int i = 0; i < quantidade; i++) {
                if (numeros[i] == valor) {
                    posicao = i;
                    break;
                }
            }

            if (posicao == -1) {
                printf("Número não encontrado. Nenhum valor foi atualizado.\n");
            } else {
                printf("Qual será o novo número? ");
                scanf("%d", &novoValor);

                numeros[posicao] = novoValor;
                printf("Número atualizado com sucesso!\n");
            }
        }

        // DELETE
        else if (opcao == 4) {
            printf("Qual número deseja excluir? ");
            scanf("%d", &valor);

            posicao = -1;

            for (int i = 0; i < quantidade; i++) {
                if (numeros[i] == valor) {
                    posicao = i;
                    break;
                }
            }

            if (posicao == -1) {
                printf("Número não encontrado. Nenhum valor foi excluído.\n");
            } else {
                for (int i = posicao; i < quantidade - 1; i++) {
                    numeros[i] = numeros[i + 1];
                }

                quantidade--;
                printf("Número excluído com sucesso!\n");
            }
        }


    } while (opcao != 0);

     printf("Programa encerrado.\n");

    return 0;
}