#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>

// Função para verificar se um diretório existe
int dirExists(const char *path) {
    struct stat info;

    if(stat(path, &info) != 0) // Se falhar ao obter informações sobre o diretório
        return 0;
    else if(info.st_mode & S_IFDIR) // Se for um diretório
        return 1;
    else
        return 0;
}

// Função para criar um diretório
int createDir(const char *path) {
    if(mkdir(path) == -1) { // Corrigindo a chamada da função mkdir
        perror("Erro ao criar pasta 'cofre'");
        exit(EXIT_FAILURE);
    }
    return 1;
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    // Verifica se o diretório "cofre" existe, se não existir, cria-o
    if (!dirExists("cofre")) {
        if (createDir("cofre") == 1) {
            printf("Pasta 'cofre' criada com sucesso.\n");
        }
    }

    const int senhaCorreta = 1234;
    int senhaUsuario;
    int tentativas = 3; // Limite de tentativas

    printf("Digite a sua senha para acessar seus arquivos:\n");

    while (tentativas > 0) {
        printf("Senha: ");
        scanf("%d", &senhaUsuario);

        if (senhaUsuario == senhaCorreta) {
            printf("Parabéns! Seus arquivos estão disponíveis, Jonathan Eduardo de Oliveira.\n");
            break; // Sai do loop se a senha estiver correta
        } else {
            printf("Senha incorreta. Você tem %d tentativas restantes.\n", --tentativas);
        }
    }

    if (tentativas == 0) {
        printf("Limite de tentativas excedido. Saindo...\n");
        exit(EXIT_FAILURE); // Termina o programa com falha
    }

    int opcao;
    int arquivosBloqueados = 0;

    do {
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
                exit(EXIT_SUCCESS); // Termina o programa com sucesso
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
                    exit(EXIT_SUCCESS); // Termina o programa com sucesso
                default:
                    printf("Opção inválida. Tente novamente.\n");
            }
        }
    } while (1);

    return 0;
}
