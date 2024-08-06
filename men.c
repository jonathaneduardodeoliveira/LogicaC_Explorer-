#include <stdio.h>

int main() {
    float nota1, nota2, nota3;

    printf("Digite tres numeros separados por espaco: ");
    scanf("%f %f %f", &nota1, &nota2, &nota3);

    float media = (nota1 + nota2 + nota3) / 3;

    printf("A media das tres notas é: %.2f\n", media);

    return 0;
} 
