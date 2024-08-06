#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

// Função para limpar o buffer do teclado
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Função para verificar se a letra faz parte da palavra
int letraCorreta(char letra, char palavra[], int tam) {
    int i;
    for (i = 0; i < tam; i++) {
        if (letra == palavra[i]) {
            return 1;
        }
    }
    return 0;
}

// Função para verificar se a palavra está correta
int palavraCorreta(char palavraDigitada[], char palavraCorreta[]) {
    if (strcmp(palavraDigitada, palavraCorreta) == 0) {
        return 1;
    }
    return 0;
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    char pratos[5][20] = {"feijoada", "acarajé", "moqueca", "tapioca", "pão de queijo"};
    char dicas[5][50] = {"Dica: Comida que leva porco e tem a cor preta",
                         "Dica: Comida típica da Bahia",
                         "Dica: Prato de peixe típico do Nordeste",
                         "Dica: Comida feita com goma de mandioca",
                         "Dica: Delícia mineira feita com queijo"};
    char opcoes[5][5][20] = {{"1 - Feijoada", "2 - Buchada", "3 - Churrasco", "4 - Paella", "5 - Lasanha"},
                             {"1 - Acarajé", "2 - Sushi", "3 - Picanha", "4 - Risoto", "5 - Cuscuz"},
                             {"1 - Moqueca", "2 - Bife a Cavalo", "3 - Cachorro Quente", "4 - Torta de Frango", "5 - Arroz com Feijão"},
                             {"1 - Tapioca", "2 - Batata Frita", "3 - Pizza", "4 - Hambúrguer", "5 - Sopa de Legumes"},
                             {"1 - Pão de Queijo", "2 - Cachorro Quente", "3 - Sushi", "4 - Macarronada", "5 - Paella"}};

    int escolha_prato, escolha_opcao;
    int i, j, chansses = 3;
    char palavra_digitada[20];

    printf("Bem-vindo ao Jogo de Adivinhar Comidas Típicas do Brasil do Jonathan Eduardo de Oliveira!\n\n");

    do {
        // Escolhendo aleatoriamente um prato
        escolha_prato = rand() % 5;

        printf("Dica da comida: %s\n", dicas[escolha_prato]);
        printf("Escolha o prato correto:\n");
        for (i = 0; i < 5; i++) {
            printf("%s\n", opcoes[escolha_prato][i]);
        }

        // Obtendo a escolha do usuário
        printf("Digite sua escolha: ");
        scanf("%d", &escolha_opcao);
        limparBuffer();

        if (escolha_opcao < 1 || escolha_opcao > 5) {
            printf("Opção inválida!\n");
            continue;
        }

        // Convertendo a escolha para o índice correto do array
        escolha_opcao--;

        // Verificando se a escolha está correta
        if (escolha_prato == escolha_opcao) {
            printf("Digite a palavra: ");
            scanf("%s", palavra_digitada);

            if (!palavraCorreta(palavra_digitada, pratos[escolha_prato])) {
                chansses--;
                printf("Fome! Restam %d chance(s)!\n", chansses);
                if (chansses == 0) {
                    printf("Você perdeu!\n");
                    break;
                }
            } else {
                printf("Parabéns! Você acertou!\n");
                break;
            }
        } else {
            chansses--;
            printf("Fome! Restam %d chance(s)!\n", chansses);
            if (chansses == 0) {
                printf("Você perdeu!\n");
                break;
            }
        }
    } while (1);

    return 0;
}
