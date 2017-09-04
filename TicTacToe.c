
// Made by p32929
// www.facebook.com/p32929

#include<stdio.h>

int i, j, p, x, a[9], vc;
char p1 = 'X', p2 = 'O';

void show_board() {
    printf("Current board\n");
    printf("-------------\n");
    for (i = 0; i < 9; i++) {
        printf("| %c ", a[i]);
        if ((i + 1) % 3 == 0)
            printf("|\n-------------\n");
    }
}

int validation_checker() {
    if ((x <= 0 || x > 9) || (a[x - 1] != ' '))
        return 1;
    else
        return 2;
}

int winner_checker() {
    if ((a[0] != ' ' && a[0] == a[1] && a[1] == a[2]) || (a[3] != ' ' && a[3] == a[4] && a[4] == a[5]) ||
        (a[6] != ' ' && a[6] == a[7] && a[7] == a[8]) || (a[0] != ' ' && a[0] == a[3] && a[3] == a[6]) ||
        (a[1] != ' ' && a[1] == a[4] && a[4] == a[7]) || (a[2] != ' ' && a[2] == a[5] && a[5] == a[8]) ||
        (a[0] != ' ' && a[0] == a[4] && a[4] == a[8]) || (a[2] != ' ' && a[2] == a[4] && a[4] == a[6]))
        return 1;
    else
        return 0;
}


int main() {
    for (i = 0; i < 9; i++) {
        a[i] = ' ';
    }

    show_board();

    for (j = 0; j < 9; j++) {
        p = j % 2 == 0 ? 1 : 2;
        printf("\nPlayer %d\'s turn: ", p);
        scanf("%d", &x);
        vc = validation_checker();
        if (vc == 1) {
            printf("\e[1;1H\e[2J");
            printf("...::: INVALID :::...\n\n");
            show_board();
            j--;
        } else {
            a[x - 1] = p == 1 ? p1 : p2;
            printf("\n");
            printf("\e[1;1H\e[2J");
            show_board();
            int wc = winner_checker();
            if (wc == 1) {
                printf("Player %d won\n", p);
                break;
            }
        }
    }
}

