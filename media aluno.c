#include <stdio.h>
#include <stdbool.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Portuguese");

    char nome[50];
    float nota1, nota2, nota3;
    float media;
    bool continuar = true;

    printf("Digite o nome do aluno: ");
    scanf("%s", nome);

    do {
        do {
            printf("Digite a nota 1 (): ");
            scanf("%f", &nota1);
            if (nota1 < 7 || nota1 > 10) {
                printf("Nota inválida! Digite uma nota entre 7 e 10.\n");
            }
        } while (nota1 < 7 || nota1 > 10);

        do {
            printf("Digite a nota 2 (): ");
            scanf("%f", &nota2);
            if (nota2 < 7 || nota2 > 10) {
                printf("Nota inválida! Digite uma nota entre 7 e 10.\n");
            }
        } while (nota2 < 7 || nota2 > 10);

        do {
            printf("Digite a nota 3 (): ");
            scanf("%f", &nota3);
            if (nota3 < 7 || nota3 > 10) {
                printf("Nota inválida! Digite uma nota entre 7 e 10.\n");
            }
        } while (nota3 < 7 || nota3 > 10);

        media = (nota1 + nota2 + nota3) / 3;

        printf("\nA média do aluno %s é: %.2f\n", nome, media);

        if (media >= 7) {
            printf("Parabéns, %s! Você foi aprovado!\n", nome);
        } else {
            printf("%s, você foi reprovado. Estude mais!\n", nome);
        }

        printf("\nDeseja calcular uma nova média?\n");
        printf("1 - Sim\n");
        printf("2 - Não (encerrar o programa)\n");
        int opcao;
        scanf("%d", &opcao);

        if (opcao == 2) {
            continuar = false;
        }

    } while (continuar);

    printf("Programa encerrado. Obrigado, %s!\n", nome);

    return 0;
}
