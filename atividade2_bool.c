//Fernanda Sousa de Assunção Vale e Luiz Ruifeng Mei - Atividade 2 - 02/09/2026


#include <stdio.h>
#include <stdbool.h>
int main()
{
    int anoNascimento;
    int anoAtual;
    int idade;
    
    bool podeVotar;
    bool podeTrabalhar;
    bool podeDirigir;
    bool podeAbrirEmpresa;
    bool podeCasarSemAutorizacao;
    bool podeSerVereador;
    bool podeSerPrefeitoOuDeputado;


    printf("Digite aqui o ano atual:");
    if (scanf ("%d", &anoAtual) !=1){
        printf("Entrada errada, digite apenas números.\n");
        return 1;
    }
    printf("Digite aqui seu ano de nascimento:");
    if (scanf ("%d", &anoNascimento) !=1){
        printf("Entrada errada, digite apenas números.\n");
        return 1;
    }

    idade = anoAtual - anoNascimento;

    podeVotar = (idade>=16);
    podeTrabalhar = (idade>=18);
    podeDirigir = (idade>=18);
    podeAbrirEmpresa = (idade>=18);
    podeCasarSemAutorizacao = (idade>=18);
    podeSerVereador = (idade>=18);
    podeSerPrefeitoOuDeputado = (idade>=18);

    printf("\nSua idade em 2026 é de %d anos.\n\n", idade);

    if (anoNascimento < 1900 || anoNascimento > 2026){
        printf("Verifique se há erro na digitação do seu ano de nascimento. Não há como considerar neste programa idades acima de 126 anos ou pessoas que ainda não nasceram.\n\n");
    } else{

            if (podeVotar == true){
                printf("Você pode votar!\n");
            } else {
                printf("Você NÃO pode votar!\n");
            }

            if (podeTrabalhar == true){
                printf("Você pode trabalhar!\n");
            } else {
                printf("Você NÃO pode trabalhar. Apenas pode ser Jovem Aprendiz!\n");
            }

            if (podeDirigir == true){
                printf("Você pode dirigir!\n");
            } else {
                printf("Você NÃO pode dirigir!\n");
            }

            if (podeAbrirEmpresa == true){
                printf("Você pode abrir uma empresa!\n");
            } else {
                printf("Você NÃO pode abrir uma empresa!\n");
            }

            if (podeCasarSemAutorizacao == true){
                printf("Você pode casar sem autorização!\n");
            } else {
                printf("Você NÃO pode casar sem autorização dos seus responsáveis!\n");
            }

            if (podeSerVereador == true){
                printf("Você pode ser vereador!\n");
            } else {
                printf("Você NÃO pode ser vereador!\n");
            }

            if (podeSerPrefeitoOuDeputado == true){
                printf("Você pode ser prefeito ou deputado!\n");
            } else {
                printf("Você NÃO pode ser prefeito e nem deputado!\n");
            }

            return 0;
    }

}
