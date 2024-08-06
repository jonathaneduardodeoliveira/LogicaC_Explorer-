#include <stdio.h>
#include <locale.h> // Adicionando a inclusão da biblioteca locale.h

int main() {
    // Definindo a localidade para aceitar acentos
    setlocale(LC_ALL, "Portuguese");

    int senhaCorreta = 1234;
    int senhaUsuario;
    int opcao;
    int arquivosBloqueados = 0; // Flag para indicar se os arquivos estão bloqueados ou não
    
    printf("Digite a sua senha para acessar seus arquivos:\n");
    
    do {
        printf("Senha: ");
        scanf("%d", &senhaUsuario);
        
        if (senhaUsuario != senhaCorreta) {
            printf("Senha incorreta. Sua dica: estude novamente.\n");
        }
        
    } while (senhaUsuario != senhaCorreta);
    
    printf("Parabéns! Seus arquivos estão disponíveis, Jonathan Eduardo de Oliveira.\n");
    
    while (1) {
        printf("\nSelecione uma opção:\n");
        printf("1. Bloquear seus arquivos novamente\n");
        printf("2. Sair\n");
        scanf("%d", &opcao);
        
        switch (opcao) {
            case 1:
                printf("Seus arquivos foram bloqueados novamente.\n");
                arquivosBloqueados = 1;
                break;
            case 2:
                printf("Saindo...\n");
                return 0;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
        
        if (arquivosBloqueados) {
            printf("\nSelecione uma opção:\n");
            printf("1. Desbloquear seus arquivos\n");
            printf("2. Sair\n");
            scanf("%d", &opcao);
            
            switch (opcao) {
                case 1:
                    printf("Seus arquivos foram desbloqueados.\n");
                    arquivosBloqueados = 0;
                    break;
                case 2:
                    printf("Saindo...\n");
                    return 0;
                default:
                    printf("Opção inválida. Tente novamente.\n");
            }
        }
    }
    
    return 0;
}
