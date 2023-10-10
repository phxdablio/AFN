#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

// Função para verificar se o caractere é um caractere especial válido
bool isSpecialChar(char c) {
    return (c == '@' || c == '*' || c == '_' || c == '-' || c == '#');
}

// Função para verificar se a string é um identificador válido
bool isValidIdentifier(char *input, int tamanho) {
    if (tamanho > 8) {
        return false; // Verifica se a string é maior que 8 caracteres
    }

    if (!isupper(input[0]) || !isdigit(input[1])) {
        return false; // Verifica a primeira e a segunda posição
    }

    for (int i = 2; i < tamanho; i++) {
        if (!(isupper(input[i]) || isdigit(input[i]) || isSpecialChar(input[i]))) {
            return false; // Verifica as posições restantes
        }
    }

    return true; // Se todas as verificações passarem, é um identificador válido
}

// Função para lidar com identificadores inválidos
void Erro() {
    printf("O identificador não atende aos critérios especificados.\n");
    // Você pode adicionar ações adicionais aqui, se desejar
}

int main() {
    int tamanho;

    printf("Digite o tamanho do identificador (1-8): ");
    scanf("%d", &tamanho);

    if (tamanho < 1 || tamanho > 8) {
        printf("Tamanho de identificação inválido. Deve ser de 1 a 8 caracteres.\n");
        return 1;
    }

    char input[9]; // Tamanho máximo é 8 + 1 (para o caractere nulo)

    printf("Digite o identificador: ");
    scanf("%s", input);

    if (isValidIdentifier(input, tamanho)) {
        printf("O identificador \"%s\" é válido.\n", input);
    } else {
        Erro();
    }

    return 0;
}

