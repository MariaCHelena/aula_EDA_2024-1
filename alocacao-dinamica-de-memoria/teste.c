#include <stdio.h>

int main() {
    FILE* arquivo = fopen("arquivo.txt", "rb"); // b indica modo binário
    if(arquivo == NULL) {
        fprintf(stderr, "Erro ao tentar abrir arquivo.txt.");
        return 1;
    }

    /* Pula até o fim do arquivo */
    fseek(arquivo, 0, 0);

    /* Lê o indicador de posição (em bytes) */
    long tamanho = ftell(arquivo);
    fclose(arquivo);

    printf("O arquivo.txt possui %ld bytes.\n", tamanho);

    return 0;
}
