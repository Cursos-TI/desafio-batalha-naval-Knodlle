#include <stdio.h>

int tabuleiro[10][10] = {0};
int navio[3] = {3,3,3};


int posicionador_navios(){
        int x, y;
        printf("Escolha a posicao inicial do seu navio\n");
        printf("SOMENTE NUMEROS DE 0 A 9\n");
        
        while(1){
            printf("Linha: "); scanf("%i", &x);
            printf("Coluna: "); scanf("%i",&y);
            if (x > 9 || y > 9 || x < 0 || y < 0){
                printf("Numero invalido!\n");
                continue;
            }
            if (tabuleiro[x][y] == 3){
                printf("Espaco ja ocupado! Selecione outro.\n");
                continue;
            }
            
            break;
            
        }
        
        int opcao;
        int erro = 1;
        while(erro){
            printf("1-Vertical 2-Horizontal 3-Diagonal\nOpcao: ");
            scanf("%d", &opcao);
            
            if(opcao == 1){
            if (x + 2 > 9) {
                printf("O navio vertical ultrapassa o limite do tabuleiro!\n");
                continue;
            }
            if (tabuleiro[x + 1][y] == 3 || tabuleiro[x + 2][y] == 3){
                printf("Espaco ja ocupado! Selecione outro.\n");
                continue;
            }
        } else if (opcao == 2){
            if (y + 2 > 9) {
                printf("O navio horizontal ultrapassa o limite do tabuleiro!\n");
                continue;
            }
            if (tabuleiro[x][y + 1] == 3 || tabuleiro[x][y + 2] == 3){
                printf("Espaco ja ocupado! Selecione outro.\n");
                continue;
            }
        } else if (opcao == 3) {
            if (x > 7 || y > 7) {
                printf("O navio diagonal ultrapassa o limite do tabuleiro!\n");
                continue;
            }
            if (tabuleiro[x + 1][y + 1] == 3 || tabuleiro[x + 2][y + 2] == 3){
                printf("Espaco ja ocupado! Selecione outro.\n");
                continue;
            }
           
        }else{
            printf("Numero invalido\n");
            continue;
        }

        // Posicionamento
        switch(opcao){
            case 1:
                for (int i = 0; i < 3; i++){
                    tabuleiro[x + i][y] = navio[i];
                }
                erro = 0;
                break;
            case 2:
                for (int i = 0; i < 3; i++){
                    tabuleiro[x][y + i] = navio[i];
                }
                erro = 0;
                break;
            case 3:
                for (int i = 0; i < 3; i++){
                        tabuleiro[x + i][y + i] = navio[i];
                    }
                erro = 0;
                break;
        }
    }
    return 0;
}

void mostrar_tabuleiro(){
    for (int i = 0; i <= 9; i++){
        for (int j = 0; j <= 9; j++){
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

    int main(){
    posicionador_navios();
    posicionador_navios();
    posicionador_navios();
    posicionador_navios();
    mostrar_tabuleiro();          

    return 0;
}