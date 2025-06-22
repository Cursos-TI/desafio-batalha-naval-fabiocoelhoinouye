#include<stdio.h>
#include<stdlib.h>

/* Jogo batalha naval nivel novato */

int main(){

    // definindo variaveis:

    const int tamanho_tabuleiro = 10;
    const int tamanho_navio = 3;
    const int valor_agua = 0;
    const int valor_navio = 3;

    // criação do tabuleiro no formato 10x10

    int tabuleiro[10][10];
    for (int i = 0; i < tamanho_tabuleiro; i++)
    {
        for (int j = 0; j < tamanho_tabuleiro; j++)
        {
            tabuleiro[i][j] = valor_agua;
        }
        
    }
    
    // cordenadas dos navios linha e coluna

    int linhaH = 1, colunaH = 2; // navio horizontal
    int linhaV = 6, colunaV = 5; // Navio vertical

    // verifica se navio horizontal cabe no tabueliro e nao sobrepoe outro

    int podeHorizontal = 1;
    if (colunaH + tamanho_navio <= tamanho_tabuleiro)
    {
        for (int i = 0; i < tamanho_navio; i++)
        {
            if (tabuleiro[linhaH][colunaH + i] != valor_agua) {
                podeHorizontal = 0;
                break;
            }
        }
        
    } else {
        podeHorizontal = 0;
    }

    // Posicionando navio horizontal
    if (podeHorizontal)
    {
        for (int i = 0; i < tamanho_navio; i++)
        {
            tabuleiro[linhaH][colunaH +i] = valor_navio;
        }
         
    } else{
        printf("Erro ao posicionar o navio horizontal\n");
        return 1;
    }

    // verificação se navio vertical cabe no tabuleiro e nao sobrepoe outro

    int podeVertical = 1;
    if (linhaV + tamanho_navio <= tamanho_tabuleiro)
    {
        for (int i = 0; i < tamanho_navio; i++)
        {
           if (tabuleiro[linhaV +i][colunaV] != valor_agua)
           {
            podeVertical = 0;
            break;
           }
           
        }
        
    } else {
        podeVertical = 0;
    }

    // posiçao navio vertical

    if (podeVertical)
    {
        for (int i = 0; i < tamanho_navio; i++)
        {
            tabuleiro[linhaV + i][colunaV] = valor_navio;
        }
        
    } else {
        printf("Erro ao posicionar o navio vertical\n");
        return 1;
    }

    // Exibindo o tabuleiro final
    printf("*** TABULEIRO DE BATALHA NAVAL ***\n");
    for (int i = 0; i < tamanho_tabuleiro; i++)
    {
        for (int j = 0; j < tamanho_tabuleiro; j++)
        {
            printf("%d  ", tabuleiro[i][j]);
        }
        printf("\n");
        
    }
    
    return 0;
}
