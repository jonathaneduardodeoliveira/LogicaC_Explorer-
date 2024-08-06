            #include <stdio.h>

int main() {
    char nome_aluno[50], nome_turma[50];
    float nota1, nota2, nota3, media;
    int opcao;

    do {
        printf("Digite o nome do aluno: ");
        scanf("%s", nome_aluno);

        printf("Digite o nome da turma: ");
        scanf("%s", nome_turma);

        printf("Digite a primeira nota: ");
        scanf("%f", &nota1);

        printf("Digite a segunda nota: ");
        scanf("%f", &nota2);

        printf("Digite a terceira nota: ");
        scanf("%f", &nota3);

        media = (nota1 + nota2 + nota3) / 3;

        printf("Nome do aluno: %s\n", nome_aluno);
        printf("Turma: %s\n", nome_turma);
        printf("Média das notas: %.2f\n", media);

        printf("Deseja calcular a média para outro aluno?\n");
        printf("1. Sim\n");
        printf("2. Encerrar\n");
        scanf("%d", &opcao);

    } while (opcao != 2);

    return 0;
}
