#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Portuguese");

    float nota1, nota2, nota3, media;
    int opcao;

    do {
        // Solicita ao usuário que insira as três notas
        printf("Digite a primeira nota: ");
        scanf("%f", &nota1);
        printf("Digite a segunda nota: ");
        scanf("%f", &nota2);
        printf("Digite a terceira nota: ");
        scanf("%f", &nota3);

        // Calcula a média das notas
        media = (nota1 + nota2 + nota3) / 3.0;

        // Verifica se o aluno está aprovado ou não
        if (media >= 7.0) {
            printf("O aluno está aprovado com média %.2f.\n", media);
        } else {
            printf("O aluno está reprovado com média %.2f.\n", media);
        }

        // Opções para calcular outra média ou sair
        printf("\nDeseja calcular outra média?\n");
        printf("1 - Sim\n");
        printf("2 - Sair\n");
        printf("Digite sua escolha: ");
        scanf("%d", &opcao);

    } while (opcao != 2);

    return 0;
}
