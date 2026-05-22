#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define AGUA 0
#define NAVIO 3

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    int linha, coluna;
    int valido;

    // Inicializa o tabuleiro com água
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    printf("=== BATALHA NAVAL - NIVEL AVENTUREIRO ===\n");
    printf("Tabuleiro 10x10\n");
    printf("Agua = 0 | Navio = 3\n\n");

    // ==========================
    // NAVIO 1 - HORIZONTAL
    // ==========================
    printf("NAVIO 1 - HORIZONTAL\n");
    printf("Digite a linha inicial (0 a 9): ");
    scanf("%d", &linha);

    printf("Digite a coluna inicial (0 a 9): ");
    scanf("%d", &coluna);

    valido = 1;

    if (linha < 0 || linha >= TAMANHO_TABULEIRO ||
        coluna < 0 || coluna + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        valido = 0;
    }

    if (valido) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linha][coluna + i] == NAVIO) {
                valido = 0;
                break;
            }
        }
    }

    if (valido) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[linha][coluna + i] = NAVIO;
        }
    } else {
        printf("\nErro: posição inválida para o navio horizontal.\n");
        return 1;
    }

    // ==========================
    // NAVIO 2 - VERTICAL
    // ==========================
    printf("\nNAVIO 2 - VERTICAL\n");
    printf("Digite a linha inicial (0 a 9): ");
    scanf("%d", &linha);

    printf("Digite a coluna inicial (0 a 9): ");
    scanf("%d", &coluna);

    valido = 1;

    if (linha < 0 || linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO ||
        coluna < 0 || coluna >= TAMANHO_TABULEIRO) {
        valido = 0;
    }

    if (valido) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linha + i][coluna] == NAVIO) {
                valido = 0;
                break;
            }
        }
    }

    if (valido) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[linha + i][coluna] = NAVIO;
        }
    } else {
        printf("\nErro: posição inválida ou sobreposição no navio vertical.\n");
        return 1;
    }

    // ==========================
    // NAVIO 3 - DIAGONAL PRINCIPAL
    // linha e coluna aumentam
    // ==========================
    printf("\nNAVIO 3 - DIAGONAL PRINCIPAL\n");
    printf("Esse navio anda assim: baixo e direita.\n");
    printf("Digite a linha inicial (0 a 9): ");
    scanf("%d", &linha);

    printf("Digite a coluna inicial (0 a 9): ");
    scanf("%d", &coluna);

    valido = 1;

    if (linha < 0 || linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO ||
        coluna < 0 || coluna + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        valido = 0;
    }

    if (valido) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linha + i][coluna + i] == NAVIO) {
                valido = 0;
                break;
            }
        }
    }

    if (valido) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[linha + i][coluna + i] = NAVIO;
        }
    } else {
        printf("\nErro: posição inválida ou sobreposição no navio diagonal principal.\n");
        return 1;
    }

    // ==========================
    // NAVIO 4 - DIAGONAL SECUNDÁRIA
    // linha aumenta e coluna diminui
    // ==========================
    printf("\nNAVIO 4 - DIAGONAL SECUNDARIA\n");
    printf("Esse navio anda assim: baixo e esquerda.\n");
    printf("Digite a linha inicial (0 a 9): ");
    scanf("%d", &linha);

    printf("Digite a coluna inicial (0 a 9): ");
    scanf("%d", &coluna);

    valido = 1;

    if (linha < 0 || linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO ||
        coluna < TAMANHO_NAVIO - 1 || coluna >= TAMANHO_TABULEIRO) {
        valido = 0;
    }

    if (valido) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linha + i][coluna - i] == NAVIO) {
                valido = 0;
                break;
            }
        }
    }

    if (valido) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[linha + i][coluna - i] = NAVIO;
        }
    } else {
        printf("\nErro: posição inválida ou sobreposição no navio diagonal secundaria.\n");
        return 1;
    }

    // ==========================
    // EXIBIÇÃO DO TABULEIRO
    // ==========================
    printf("\n=== TABULEIRO FINAL ===\n\n");

    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}