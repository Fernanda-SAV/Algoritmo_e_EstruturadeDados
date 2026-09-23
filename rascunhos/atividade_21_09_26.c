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
        if (opcao == 1){

            printf("Digite um número:\n");
            scanf("%d", &numeros[quantidade]);

            quantidade++;

            if (quantidade < 10) {
                printf("Número cadastrado!\n");
            } else {
                printf ("Vetor cheio!\n");
            }
        }

        //READ
        else if (opcao == 2){
            
            printf("Qual número você gostaria de buscar?\n");
            scanf("%d", &busca);

            encontrado=0;

            for (int i = 0; i < quantidade; i++){
                if (numeros[i]) == busca){
                    printf("Número encontrado na posição %d.", i);

                    encontrado=1;       
                }
            }

            if (numeros [i]==)
        
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


