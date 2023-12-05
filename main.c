#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para gerar um número aleatório entre 1 e 100
int gerarNumeroAleatorio() {
    srand(time(NULL));
    return rand() % 100 + 1;
}

// Função para avaliar a tentativa do jogador e dar dicas
void avaliarTentativa(int numeroSecreto, int tentativa) {
    if (tentativa < numeroSecreto) {
        printf("Muito baixo! Tente novamente.\n");
    } else if (tentativa > numeroSecreto) {
        printf("Muito alto! Tente novamente.\n");
    } else {
        printf("Parabéns! Você acertou o número %d!\n", numeroSecreto);
    }
}

int main() {
    // Inicialização
    int numeroSecreto = gerarNumeroAleatorio();
    int tentativa, pontuacao = 0;

    // Menu interativo
    int escolha;
    do {
        printf("1. Iniciar Jogo\n");
        printf("2. Sair\n");
        printf("Escolha: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                // Iniciar o jogo
                printf("Adivinhe o número entre 1 e 100.\n");

                do {
                    printf("Digite sua tentativa: ");
                    scanf("%d", &tentativa);
                    avaliarTentativa(numeroSecreto, tentativa);
                    pontuacao++;
                } while (tentativa != numeroSecreto);

                printf("Sua pontuação: %d\n", pontuacao);
                break;
            case 2:
                // Sair do jogo
                printf("Obrigado por jogar!\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (escolha != 2);

    return 0;
}