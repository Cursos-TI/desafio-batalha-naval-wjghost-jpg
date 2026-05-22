#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_HABILIDADE 5

#define AGUA 0
#define NAVIO 3
#define HABILIDADE 5

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    int cone[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int cruz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int octaedro[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];

    int centro = TAMANHO_HABILIDADE / 2;

    // Inicializa o tabuleiro com água
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // Posiciona navios no tabuleiro
    tabuleiro[1][1] = NAVIO;
    tabuleiro[1][2] = NAVIO;
    tabuleiro[1][3] = NAVIO;

    tabuleiro[4][7] = NAVIO;
    tabuleiro[5][7] = NAVIO;
    tabuleiro[6][7] = NAVIO;

    tabuleiro[7][1] = NAVIO;
    tabuleiro[8][2] = NAVIO;
    tabuleiro[9][3] = NAVIO;

    // Cria matriz do cone
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (j >= centro - i && j <= centro + i) {
                cone[i][j] = 1;
            } else {
                cone[i][j] = 0;
            }
        }
    }

    // Cria matriz da cruz
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (i == centro || j == centro) {
                cruz[i][j] = 1;
            } else {
                cruz[i][j] = 0;
            }
        }
    }

    // Cria matriz do octaedro em formato de losango
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            int distancia = (i > centro ? i - centro : centro - i) +
                            (j > centro ? j - centro : centro - j);

            if (distancia <= centro) {
                octaedro[i][j] = 1;
            } else {
                octaedro[i][j] = 0;
            }
        }
    }

    // Aplica habilidade CONE
    int origemConeLinha = 0;
    int origemConeColuna = 5;

    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            int linhaTabuleiro = origemConeLinha + i;
            int colunaTabuleiro = origemConeColuna - centro + j;

            if (linhaTabuleiro >= 0 && linhaTabuleiro < TAMANHO_TABULEIRO &&
                colunaTabuleiro >= 0 && colunaTabuleiro < TAMANHO_TABULEIRO &&
                cone[i][j] == 1 &&
                tabuleiro[linhaTabuleiro][colunaTabuleiro] != NAVIO) {

                tabuleiro[linhaTabuleiro][colunaTabuleiro] = HABILIDADE;
            }
        }
    }

    // Aplica habilidade CRUZ
    int origemCruzLinha = 5;
    int origemCruzColuna = 2;

    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            int linhaTabuleiro = origemCruzLinha - centro + i;
            int colunaTabuleiro = origemCruzColuna - centro + j;

            if (linhaTabuleiro >= 0 && linhaTabuleiro < TAMANHO_TABULEIRO &&
                colunaTabuleiro >= 0 && colunaTabuleiro < TAMANHO_TABULEIRO &&
                cruz[i][j] == 1 &&
                tabuleiro[linhaTabuleiro][colunaTabuleiro] != NAVIO) {

                tabuleiro[linhaTabuleiro][colunaTabuleiro] = HABILIDADE;
            }
        }
    }

    // Aplica habilidade OCTAEDRO
    int origemOctaedroLinha = 7;
    int origemOctaedroColuna = 7;

    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            int linhaTabuleiro = origemOctaedroLinha - centro + i;
            int colunaTabuleiro = origemOctaedroColuna - centro + j;

            if (linhaTabuleiro >= 0 && linhaTabuleiro < TAMANHO_TABULEIRO &&
                colunaTabuleiro >= 0 && colunaTabuleiro < TAMANHO_TABULEIRO &&
                octaedro[i][j] == 1 &&
                tabuleiro[linhaTabuleiro][colunaTabuleiro] != NAVIO) {

                tabuleiro[linhaTabuleiro][colunaTabuleiro] = HABILIDADE;
            }
        }
    }

    // Exibe o tabuleiro final
    printf("=== BATALHA NAVAL - NIVEL MESTRE ===\n\n");
    printf("0 = Agua | 3 = Navio | 5 = Area de habilidade\n\n");

    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}