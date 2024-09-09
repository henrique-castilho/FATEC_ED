/*4. Faça um programa que receba do usuario o tamanho de uma string e chame uma
função para alocar dinamicamente essa string. Em seguida, o usuário deverá informar o
conteúdo dessa string. O programa imprime a string sem suas vogais.*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char* alocacaoString(int tamanho){
    char *string =  (char *) malloc ((tamanho + 1) * sizeof(char));
    if (string == NULL) {
        printf("Erro na alocação de memória.\n");
        exit(1);
    }
    return string;
}

void removeVogais(char *str){
    int j = 0;
    int tamanho = strlen(str);
    for (int i = 0; i < tamanho; i++) {
        if (str[i] != 'a' && str [i] != 'e' && str[i] != 'i' && str[i] != 'o' && str[i] != 'u' && 
            str[i] != 'A' && str [i] != 'E' && str[i] != 'I' && str[i] != 'O' && str[i] != 'U') {
                str[j++] = str[i];
        }
    }
    str[j] = '\0';  
}

int main(){
    int tam;
    char *str;

    printf("Digite o tamanho da string: ");
    scanf("%d", tam);

    str = alocacaoString(tam);

    printf("Digite o conteúdo da string: ");
    getchar();
    fgets(str, tam + 1, stdin); 

    removeVogais(str);

    printf("String sem vogais: %s\n", str);

    free(str);

    return 0;
}