#include <stdio.h>
#include <string.h>

int main () {
    char palavra[100], senha[11];

    printf("Digite uma palavra: ");
    scanf("%[^\n]", palavra);
    printf("Voce digitou %s\n", palavra);
    

    printf("\nDigite uma senha, so digitos (no maximo 10): ");
    // scanf("%[a..z,A..Z]", senha);
    // printf("\nSua senha e: %s\n", senha);

    char c = getchar(); //capturando o enter anterior (esvaziando o buffer)
    int i = 0;
    //leitura segura
    while (i < 10 && ((c = getchar()) != '\n')) {
        senha[i++] = c;
    }
    senha[i] = '\0';    
    printf("\nSua senha: %s\n", senha);

    //Verificação se a palavra é palindrome
    i = 0;
    int j = strlen(palavra) - 1;
    int e_palindrome = 1;
    while (i <= j && e_palindrome) {
        if (palavra[i++] != palavra[j--]) {
            e_palindrome = 0;
        }
    }
    if (e_palindrome) {
        printf("\n%s e palindrome\n", palavra);
    } else {
        printf("\n%s nao e palindrome\n", palavra);
    }
    


    return 0;
}
