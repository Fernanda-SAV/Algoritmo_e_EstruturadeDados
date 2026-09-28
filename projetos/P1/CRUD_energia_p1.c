// CRUD feito para a P1 da disciplina de Algoritmo e Estrutura de Dados
// Discentes: Fernanda Sousa de Assunção Vale - matrícula: 20250071607 e Luiz Ruifeng Mei - matrícula: 20240006006

// CRUD com objetivo de: CONTROLE DE CONSUMO DE ENERGIA - permite que o usuário registre seus consumos mensais e 
// consiga, além de manipular os valores inseridos, possa calcular o consumo mensal e/ou anual, caso deseje.


// ******luiz, faz o readme desse crud por favor******
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
//****** luiz, aq vc pode inserir uma restrição para, caso o consumo já esteja cadastrado por 
//exemplo, nao permitir um novo cadastro em cima do mes já registrado ******
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
// ****** luiz, aq eu notei que se inserir o valor da tarifa com virgula ao inves de ponto (por exemplo, não permita que o usuário insira 1,11, aceite somente o 1.11), o programa "quebra"
// acho ideal colocar uma restrição em que o programa so aceite valores de float usando ponto e não virgula, para evitar essa situação
//aleem disso, aq nessa opção, podemos perguntar se ele quer o calculo mensal escolhendo o mes que deseja calcular ou quer saber 
// o quanto gastou no ano, somando os valores de todos os 12 espaços ******
        if (opcao == 5) {

            printf("Digite o mes que deseja calcular (1 a 12): ");
            scanf("%d", &mes);

            if (consumo[mes - 1] != 0) {

                printf("Digite o valor da tarifa por kWh: R$ ");
                scanf("%f", &tarifa);
//a tarifa HOJE (28/09/2026) da equatorial com impostos está R$ 1.11 por kWh
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