#include <stdio.h>
void Board(char b[3][3]){
    int k = 1;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            b[i][j] = '0' + (k++);
        }
    }
    printf("\n");
}

void printBoard(char b[3][3]){
    for(int i=0; i<3; i++){
        for(int j =0; j<3; j++){
            printf("%c", b[i][j]);
            if(j < 2){
                printf("|");
            }
        }
        printf("\n");
        if(i < 2){
            printf("---|---|---\n");
        }
    }
}

int winCondition(char b[3][3]){
     for (int i = 0; i < 3; i++)
        if (b[i][0] == b[i][1] && b[i][1] == b[i][2]) return 1;

    for (int j = 0; j < 3; j++)
        if (b[0][j] == b[1][j] && b[1][j] == b[2][j]) return 1;

    if (b[0][0] == b[1][1] && b[1][1] == b[2][2]) return 1;
    if (b[0][2] == b[1][1] && b[1][1] == b[2][0]) return 1;

    return 0;
}

int draw(char b[3][3]){
     for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (b[i][j] >= '1' && b[i][j] <= '9'){
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    char b[3][3];
    Board(b);   

    char player = 'X';

    while (1) {
        printBoard(b);

        int r, c;
        printf("Player %c: ", player);
        if (scanf("%d %d", &r, &c) != 2) {
            printf("Error!\n");
            return 0;
        }

        r--;
        c--;

        if (r < 0 || r > 2 || c < 0 || c > 2) {
            printf("Position is outside the board.\n");
            continue;
        }

        if (!(b[r][c] >= '1' && b[r][c] <= '9')) {
            printf("Position is already taken.\n");
            continue;
        }

        b[r][c] = player;

        if (winCondition(b)) {
            printBoard(b);
            printf("Player %c wins!\n", player);
            break;
        }

        if (draw(b)) {
            printBoard(b);
            printf("Draw game!\n");
            break;
        }

        player = (player == 'X') ? 'O' : 'X';
    }

    return 0;
}
