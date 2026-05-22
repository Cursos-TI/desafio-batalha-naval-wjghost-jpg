#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define AGUA 0
#define NAVIO 3

int main() {

    // MATRIZ DO TABULEIRO
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    // VETORES DOS NAVIOS
    int navioHorizontal[TAMANHO_NAVIO] = {NAVIO, NAVIO, NAVIO};
    int navioVertical[TAMANHO_NAVIO] = {NAVIO, NAVIO, NAVIO};

    // COORDENADAS DOS NAVIOS
    int linhaHorizontal, colunaHorizontal;
    int linhaVertical, colunaVertical;

    int valido = 1;

    // INICIALIZA O TABULEIRO COM ÁGUA
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // =========================
    // ENTRADA DO NAVIO HORIZONTAL
    // =========================

    printf("=== BATALHA NAVAL ===\n\n");

    printf("NAVIO HORIZONTAL (tamanho 3)\n");
    printf("Digite a linha inicial (0 a 9): ");
    scanf("%d", &linhaHorizontal);

    printf("Digite a coluna inicial (0 a 9): ");
    scanf("%d", &colunaHorizontal);

    // VALIDAÇÃO DO NAVIO HORIZONTAL
    if (linhaHorizontal < 0 || linhaHorizontal >= TAMANHO_TABULEIRO ||
        colunaHorizontal < 0 || colunaHorizontal + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {

        printf("\nErro: posição inválida para o navio horizontal.\n");
        valido = 0;
    }

    // POSICIONA NAVIO HORIZONTAL
    if (valido) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[linhaHorizontal][colunaHorizontal + i] = navioHorizontal[i];
        }
    }

    // =========================
    // ENTRADA DO NAVIO VERTICAL
    // =========================

    if (valido) {

        printf("\nNAVIO VERTICAL (tamanho 3)\n");

        printf("Digite a linha inicial (0 a 9): ");
        scanf("%d", &linhaVertical);

        printf("Digite a coluna inicial (0 a 9): ");
        scanf("%d", &colunaVertical);

        // VALIDAÇÃO DO NAVIO VERTICAL
        if (linhaVertical < 0 || linhaVertical + TAMANHO_NAVIO > TAMANHO_TABULEIRO ||
            colunaVertical < 0 || colunaVertical >= TAMANHO_TABULEIRO) {

            printf("\nErro: posição inválida para o navio vertical.\n");
            valido = 0;
        }
    }

    // VERIFICA SOBREPOSIÇÃO
    if (valido) {

        for (int i = 0; i < TAMANHO_NAVIO; i++) {

            if (tabuleiro[linhaVertical + i][colunaVertical] == NAVIO) {

                printf("\nErro: os navios estão se sobrepondo.\n");
                valido = 0;
                break;
            }
        }
    }

    // POSICIONA NAVIO VERTICAL
    if (valido) {

        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[linhaVertical + i][colunaVertical] = navioVertical[i];
        }
    }

    // =========================
    // EXIBE O TABULEIRO
    // =========================

    if (valido) {

        printf("\n=== TABULEIRO FINAL ===\n\n");

        for (int i = 0; i < TAMANHO_TABULEIRO; i++) {

            for (int j = 0; j < TAMANHO_TABULEIRO; j++) {

                printf("%d ", tabuleiro[i][j]);
            }

            printf("\n");
        }
    }

    return 0;
}