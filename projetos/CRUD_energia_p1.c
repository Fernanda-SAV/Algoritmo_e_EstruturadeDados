#include <stdio.h>

int main() {

    float consumo[12] = {0};
    float gasto;
    float tarifa;
    float custo;

    int mes;
    int opcao;
    int continuar = 1;

    while (continuar == 1) {

        printf("\n===== CONTROLE DE CONSUMO DE ENERGIA =====\n\n");

        printf("1 - CADASTRAR CONSUMO MENSAL\n");
        printf("2 - BUSCAR CONSUMO POR MES\n");
        printf("3 - ATUALIZAR CONSUMO DO MES\n");
        printf("4 - DELETAR CONSUMO DO MES\n");
        printf("5 - CALCULAR CUSTO DO MES\n\n");

        printf("O que deseja fazer? ");
        scanf("%d", &opcao);


        // CREATE

        if (opcao == 1) {

            printf("Digite o mes (1 a 12): ");
            scanf("%d", &mes);

            printf("Digite o consumo do mes em kWh: ");
            scanf("%f", &gasto);

            consumo[mes - 1] = gasto;

            printf("Consumo cadastrado com sucesso!\n");
        }


        // READ

        if (opcao == 2) {

            printf("Digite o mes que deseja consultar (1 a 12): ");
            scanf("%d", &mes);

            if (consumo[mes - 1] != 0) {

                printf("Consumo do mes %d: %.2f kWh\n",
                       mes, consumo[mes - 1]);

            } else {

                printf("Nao existe consumo cadastrado para esse mes.\n");

            }
        }


        // UPDATE

        if (opcao == 3) {

            printf("Digite o mes que deseja atualizar (1 a 12): ");
            scanf("%d", &mes);

            if (consumo[mes - 1] != 0) {

                printf("Consumo atual: %.2f kWh\n", consumo[mes - 1]);

                printf("Digite o novo consumo: ");
                scanf("%f", &gasto);

                consumo[mes - 1] = gasto;

                printf("Consumo atualizado com sucesso!\n");

            } else {

                printf("Nao existe consumo cadastrado para esse mes.\n");

            }
        }


        // DELETE

        if (opcao == 4) {

            printf("Digite o mes que deseja deletar (1 a 12): ");
            scanf("%d", &mes);

            if (consumo[mes - 1] != 0) {

                consumo[mes - 1] = 0;

                printf("Consumo deletado com sucesso!\n");

            } else {

                printf("Nao existe consumo cadastrado para esse mes.\n");

            }
        }


        // CALCULAR CUSTO

        if (opcao == 5) {

            printf("Digite o mes que deseja calcular (1 a 12): ");
            scanf("%d", &mes);

            if (consumo[mes - 1] != 0) {

                printf("Digite o valor da tarifa por kWh: R$ ");
                scanf("%f", &tarifa);

                custo = consumo[mes - 1] * tarifa;

                printf("Consumo: %.2f kWh\n", consumo[mes - 1]);
                printf("Custo estimado: R$ %.2f\n", custo);

            } else {

                printf("Nao existe consumo cadastrado para esse mes.\n");

            }
        }


        // CONTINUAR

        printf("\nDeseja continuar? (1/0): ");
        scanf("%d", &continuar);
    }

    return 0;
}