// CRUD feito para a P1 da disciplina de Algoritmo e Estrutura de Dados
// Discentes: Fernanda Sousa de Assunção Vale - matrícula: 20250071607 e Luiz Ruifeng Mei - matrícula: 20240006006

// CRUD com objetivo de: CONTROLE DE CONSUMO DE ENERGIA
//A ideia surgiu da necessidade de organizar e acompanhar o consumo de energia de uma residência ao longo do ano.
// Motivação: Imagine uma pessoa que deseja saber quanto consumiu de energia em determinado mês ou quanto gastou durante um período. 
// Para isso, ela precisaria armazenar esses dados e realizar os cálculos manualmente.
// Pensando nesse problema, desenvolvemos um programa que permite cadastrar, consultar, 
// atualizar e excluir registros de consumo mensal, além de calcular o custo estimado da energia elétrica.

#include <stdio.h>


// O programa foi desenvolvido todo dentro do main() que é a função principal
int main() {

    float consumo[12]; //nossa estrutura de armazenamento é o vetor consumo, q representa os meses do ano
    //importante característica desse vetor:
    //como os índices do vetor começam em zero, janeiro corresponde à posição zero e dezembro à posição onze. 
    //por isso, sempre que o usuário informa um mês, utilizamos mes - 1 para acessar a posição correta.
    //o valor -1 representa um mês ainda não cadastrado.
    //isso foi feito porque o consumo de energia pode ser zero, mas não pode ser negativo. 
    //assim, conseguimos diferenciar um mês não cadastrado de um mês que realmente teve consumo igual a zero.
    
    float gasto;
    float tarifa;
    float custo;

    int mes;
    int opcao;
    int continuar = 1;
    char teste;

    for (int i = 0; i < 12; i++) {
        consumo[i] = -1;
    }

    while (continuar == 1) {

        printf("\n===== CONTROLE DE CONSUMO DE ENERGIA =====\n\n");

        printf("1 - CADASTRAR CONSUMO MENSAL\n");
        printf("2 - BUSCAR CONSUMO POR MES\n");
        printf("3 - ATUALIZAR CONSUMO DO MES\n");
        printf("4 - DELETAR CONSUMO DO MES\n");
        printf("5 - CALCULAR CUSTO DO MES/ANO\n\n");
        printf("0 - SAIR\n\n");
        

        printf("O que deseja fazer? ");
        scanf("%d", &opcao);



          // SAIR
        if (opcao == 0) {
            continuar = 0;
            printf("Programa encerrado!\n");
            break;
        }

         // CREATE
        
        if (opcao == 1) {

            printf("Digite o mês (1 a 12): ");
            scanf("%d%c", &mes, &teste);

            if (teste == ',' || teste == '.') {

                printf ("Mês inválido! Tente novamente.\n");

                while (teste != '\n') {

                    scanf("%c", &teste);
                    
                }

            } else if (mes < 1 || mes > 12) {

                printf ("Mês inválido! Tente novamente.\n");

            } else if (consumo[mes - 1] != -1) {

                printf ("Consumo já cadastrado para este mês! Tente novamente.\n");

            } else {

                printf ("Digite o consumo do mês em kWh: ");
                scanf ("%f%c", &gasto, &teste);

                if (teste == ',') {

                            printf ("Digite o valor com ponto!\n");

                            while (teste != '\n') {

                                scanf ("%c", &teste);

                            }

                } else if (gasto < 0) {

                    printf ("Consumo inválido! Tente novamente.\n");

                } else {

                    consumo [mes - 1] = gasto;
                    printf("Consumo cadastrado com sucesso!\n");

                }
            }
        }


        // READ

        if (opcao == 2) {

            printf("Digite o mês que deseja consultar (1 a 12): ");
            scanf("%d%c", &mes, &teste);

            if (teste == ',' || teste == '.') {

                printf ("Mês inválido! Tente novamente.\n");

                while (teste != '\n') {

                    scanf("%c", &teste);

                }

            } else if (mes < 1 || mes > 12) {

                printf ("Mês inválido! Tente novamente.\n");

            } else if (consumo[mes - 1] != -1) {
                
                printf ("Consumo do mês %d: %.2f kWh\n", mes, consumo[mes - 1]);
            
            } else {
            
                printf ("Não há consumo cadastrado para esse mês.\n");
           
            }
        }


        // UPDATE

        if (opcao == 3) {

            printf("Digite o mês que deseja atualizar (1 a 12): ");
            scanf("%d%c", &mes, &teste);

            if (teste == ',' || teste == '.') {

                printf ("Mês inválido! Tente novamente.\n");

                while (teste != '\n') {

                    scanf("%c", &teste);

                }
            
            } else if (mes < 1 || mes > 12) {

                printf ("Mês inválido! Tente novamente.\n");
            
            } else if (consumo[mes - 1] != -1) {

                printf("Consumo atual: %.2f kWh\n", consumo[mes - 1]);

                printf("Digite o novo consumo: ");
                scanf("%f%c", &gasto, &teste);

                if (teste == ',') {

                            printf ("Digite o valor com ponto!\n");

                            while (teste != '\n') {

                                scanf ("%c", &teste);

                            }

                } else if (gasto < 0) {

                    printf ("Consumo inválido! Tente novamente.\n");
             
                } else {

                    consumo[mes - 1] = gasto;
                    printf("Consumo atualizado com sucesso!\n");

                }

            } else {

                printf("Nao existe consumo cadastrado para esse mes.\n");

            }
        }


        // DELETE

        if (opcao == 4) {

            printf("Digite o mês que deseja deletar (1 a 12): "); 
            scanf("%d%c", &mes, &teste);

            if (teste == ',' || teste == '.') {

                printf ("Mês inválido! Tente novamente.\n");

                while (teste != '\n') {

                    scanf("%c", &teste);

                }

            } else if (mes < 1 || mes > 12) {

                printf ("Mês inválido! Tente novamente.\n");

            } else if (consumo[mes - 1] == -1) {

                printf ("Não há consumo cadastrado para esse mês.\n");

            } else {

                consumo[mes - 1] = -1;
                printf ("Consumo deletado com sucesso!\n");

            }

        }


        // CALCULAR CUSTO
        //além das 4 operações do CRUD, implementamos uma funcionalidade 
        //extra que permite calcular o custo estimado da energia elétrica 
        //com base no consumo registrado e na tarifa por kWh informada pelo usuário.

        //o usuario também pode escolher entre calcular o custo de um mês específico 
        //ou o custo total de um período (de janeiro até o mês informado).
        // no calculo anual, se houver algum mês sem consumo cadastrado, 
        //o programa informa que não é possível calcular o custo total.

        if (opcao == 5) {

            custo = 0;
            int opcao5 = 0;

             printf ("Como deseja calcular o custo?\n\n");
             printf ("Opção 1: por mês.\n");
             printf ("Opção 2: por ano.\n");
             scanf ("%d", &opcao5);

             if (opcao5 == 1) {

                printf ("Digite o mês que deseja calcular (1 a 12): ");
                scanf ("%d%c", &mes, &teste);

                if (teste == ',' || teste == '.') {

                    printf ("Mês inválido! Tente novamente.\n");

                    while (teste != '\n') {

                        scanf("%c", &teste);

                    }
                } else if (mes < 1 || mes > 12) {

                    printf ("Mês inválido! Tente novamente.\n");

                } else if (consumo[mes - 1] != -1) {

                    printf ("Digite o valor da tarifa por kWh: R$ ");
                    scanf ("%f%c", &tarifa, &teste);

                    if (teste == ',') {

                        printf ("Digite o valor com ponto!\n");

                        while (teste != '\n') {

                            scanf ("%c", &teste);

                        }

                    } else if (tarifa < 0) {

                        printf("Tarifa inválida! Não pode ser negativa.\n");

                    } else {

                        custo = consumo[mes - 1] * tarifa;

                        printf("Consumo: %.2f kWh\n", consumo[mes - 1]);
                        printf("Custo estimado: R$ %.2f\n", custo);

                    }
                } else {

                    printf ("Não há consumo cadastrado para esse mês!\n");

                }
             }

            if (opcao5 == 2) {

                //a tarifa HOJE (28/09/2026) da equatorial com impostos está R$ 1.11 por kWh
             

                int encontrado = 0;

                printf ("Em que mês você está (1 a 12)? ");
                scanf ("%d%c", &mes, &teste);

                if (teste == ',' || teste == '.') {

                    printf ("Mês inválido! Tente novamente.\n");
                    mes = 0;

                    while (teste != '\n') {

                        scanf ("%c", &teste);

                    }

                } else if (mes < 1 || mes > 12) {

                    printf ("Mês inválido! Tente novamente.\n");
                }

                if (mes >= 1 && mes <= 12) {

                    for (int i = 0; i < mes && encontrado != 1; i++) {

                        if (consumo[i] == -1) {

                            printf("Existe consumo não cadastrado durante o período informado! Tente novamente.\n");
                            encontrado = 1;

                        } else {

                            custo = consumo[i] + custo;
                        }
                    }

                    if (custo >= 0 && encontrado == 0) {

                        printf("Digite o valor da tarifa por kWh: R$ ");
                        scanf("%f%c", &tarifa, &teste);

                        if (teste == ',') {

                            printf("Digite o valor com ponto!\n");

                            while (teste != '\n') {
                                scanf("%c", &teste);
                            }

                        } else if (tarifa < 0) {
                            printf("Tarifa inválida! Não pode ser negativa.\n");

                        } else {

                            printf("Consumo: %.2f kWh\n", custo);
                            custo = custo * tarifa;
                            printf("Custo estimado: R$ %.2f\n", custo);

                        }
                    }
                }
            }
        }


        printf("\nDeseja continuar? (1/0): ");
        scanf("%d", &continuar);

    }

    return 0;
}