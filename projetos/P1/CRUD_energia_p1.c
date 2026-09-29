// CRUD feito para a P1 da disciplina de Algoritmo e Estrutura de Dados
// Discentes: Fernanda Sousa de Assunção Vale - matrícula: 20250071607 e Luiz Ruifeng Mei - matrícula: 20240006006

// CRUD com objetivo de: CONTROLE DE CONSUMO DE ENERGIA - permite que o usuário registre seus consumos mensais e 
// consiga, além de manipular os valores inseridos, possa calcular o consumo mensal e/ou anual, caso deseje.


// ******luiz, faz o readme desse crud por favor******
#include <stdio.h>

int main() {

    float consumo[12];
    //inserir variavel de controle - luiz e fernanda devem verificar ou verificar vetor sem iniciar vazio
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

        printf("O que deseja fazer? ");
        scanf("%d", &opcao);


        // CREATE
//****** luiz, aq vc pode inserir uma restrição para, caso o consumo já esteja cadastrado por 
//exemplo, nao permitir um novo cadastro em cima do mes já registrado 
// faz aquela verificaçao de segurança impedindo q o usuario insira mais coisas o que cabe dentro do vetor
// tem que verificar que o usuário NESSE CASO nao pode inserir mes 0 ******
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
// lembre que o usuario pode inserir zero, entao talvez seja melhor usar a variavel de controle, a diferença do zero vazio pro
// zero inserido pelo usuario -DIFERENCIE OS ZEROS
        }


        // CALCULAR CUSTO
// ****** luiz, aq eu notei que se inserir o valor da tarifa com virgula ao inves de ponto (por exemplo, não permita que o usuário insira 
// 1,11, aceite somente o 1.11), o programa "quebra"
// acho ideal colocar uma restrição em que o programa so aceite valores de float usando ponto e não virgula, para evitar essa situação
//alem disso, aq nessa opção, podemos perguntar se ele quer o calculo mensal escolhendo o mes que deseja calcular ou quer saber 
// o quanto gastou no ano, somando os valores de todos os 12 espaços ******
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
                // para calcular o valor anual pergunte pro usuario em que mes estamos

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

                for (int i = 0; i < mes && encontrado != 1 ; i++) {

                    if (consumo[i] == -1) {

                        printf ("Existe consumo não cadastrado durante o período informado! Tente novamente.\n");
                        encontrado = 1;

                    } else {

                        custo = consumo[i] + custo;

                    }
                }

                if (mes > 0 && mes < 13) {

                    if (custo >= 0 && encontrado == 0) {

                        printf ("Digite o valor da tarifa por kWh: R$ ");
                        scanf ("%f%c", &tarifa, &teste);

                        if (teste == ',') {

                            printf ("Digite o valor com ponto!\n");

                            while (teste != '\n') {

                                scanf ("%c", &teste);

                            }

                        } else {

                            printf("Consumo: %.2f kWh\n", custo);
                            custo = custo * tarifa;
                            printf("Custo estimado: R$ %.2f\n", custo);

                        }
                    }
                }
            }
        }
        // CONTINUAR

        printf("\nDeseja continuar? (1/0): ");
        scanf("%d", &continuar);

    }

    return 0;
}