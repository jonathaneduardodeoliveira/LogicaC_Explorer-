    #include <stdio.h>

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
    
    return 0;
}
