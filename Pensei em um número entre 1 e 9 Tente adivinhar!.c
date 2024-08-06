#include <stdio.h>
#include <unistd.h>

int main() {
    int numeroPensado = 9;
    int tentativa;
    int tentativasMaximas = 3;

    printf("Pensei em um numero entre 1 e 9. Tente adivinhar!\n");

    for (int i = 0; i < tentativasMaximas; i++) {
        printf("Tentativa %d de %d. Tente adivinhar o numero: ", i + 1, tentativasMaximas);
        scanf("%d", &tentativa);

        if (tentativa == numeroPensado) {
            printf("Parabens! Voce adivinhou o numero que eu estava pensando: %d\n", numeroPensado);
            return 0;
        } else {
            printf("Que pena! Tente novamente.\n");
        }
    }

    printf("Suas tentativas acabaram. O número que eu estava pensando era: %d\n", numeroPensado);

    printf("Pressione Enter para fechar o programa...\n");
    getchar(); // Espera pela entrada de Enter

    return 0;
}
