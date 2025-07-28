#include <stdio.h>

#define TAMANHO_TABULEIRO 10 
int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};
int navio[3] = {3,3,3};


int cone[5][5] = {
    {0,0,0,0,0},
    {0,0,0,0,0},
    {0,0,1,0,0},
    {0,1,1,1,0},
    {1,1,1,1,1}
};

int cruz[5][5] = {
    {0,0,1,0,0},
    {0,0,1,0,0},
    {1,1,1,1,1},
    {0,0,1,0,0},
    {0,0,1,0,0}
};

int octaedro[5][5] = {
    {0,0,1,0,0},
    {0,1,1,1,0},
    {1,1,1,1,1},
    {0,1,1,1,0},
    {0,0,1,0,0}
};

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
        printf("1-Vertical 2-Horizontal 3-Diagonal primaria 4-Diagonal secundaria\nOpcao: ");
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
                printf("O navio diagonal primaria ultrapassa o limite do tabuleiro!\n");
                continue;
            }
            if (tabuleiro[x + 1][y + 1] == 3 || tabuleiro[x + 2][y + 2] == 3){
                printf("Espaco ja ocupado! Selecione outro.\n");
                continue;
            }
           
        }else if (opcao == 4){
            if (x > 7 || y < 2) {
                printf("O navio diagonal secundaria ultrapassa o limite do tabuleiro!\n");
                continue;
            }
            if (tabuleiro[x + 1][y - 1] == 3 || tabuleiro[x + 2][y - 2] == 3){
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
            case 4: 
                for (int i = 0; i < 3; i++){
                tabuleiro[x + i][y - i] = navio[i];
                }
                erro = 0;
                break;
        }
    }
    return 0;
}

//aplicar habilidades mo tabuleiro
void aplicar_habilidade(int habilidade[5][5], int centro_x, int centro_y) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (habilidade[i][j] == 1) {
                int pos_x = centro_x + (i - 2);
                int pos_y = centro_y + (j - 2); 
                
                //limites do tabuleiro
                if (pos_x >= 0 && pos_x < TAMANHO_TABULEIRO && pos_y >= 0 && pos_y < TAMANHO_TABULEIRO) {
                    tabuleiro[pos_x][pos_y] = 5; 
                }
            }
        }
    }
}

void mostrar_tabuleiro(){
    for (int i = 0; i < TAMANHO_TABULEIRO; i++){
        for (int j = 0; j < TAMANHO_TABULEIRO; j++){
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
    
    
    aplicar_habilidade(cone, 5, 5);       
    aplicar_habilidade(cruz, 2, 7);       
    aplicar_habilidade(octaedro, 8, 3);   
    
    mostrar_tabuleiro();          

    return 0;
}