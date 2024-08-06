#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main() {
    int senhaCorreta = 1234;
    int senhaUsuario;
    
    printf("Digite a sua senha para acessar seus arquivos:\n");
    
    do {
        printf("Senha: ");
        scanf("%d", &senhaUsuario);
        
        if (senhaUsuario != senhaCorreta) {
            printf("Senha incorreta. Sua dica: estude novamente.\n");
        }
        
    } while (senhaUsuario != senhaCorreta);
    
    printf("Parabéns! Seus arquivos estão disponíveis, Jonathan Eduardo de Oliveira.\n");

    // Criar uma pasta chamada "arquivos-protegidos"
    if (mkdir("arquivos-protegidos", 0777) == -1) {
        perror("Erro ao criar pasta");
        exit(EXIT_FAILURE);
    } else {
        printf("Pasta 'arquivos-protegidos' criada com sucesso.\n");
    }
    
    return 0;
}
