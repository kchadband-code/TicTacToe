#include <stdio.h>

char board[3][3];

void initBoard() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = ' ';
}

void printBoard() {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
        if (i < 2) printf("---+---+---\n");
    }
    printf("\n");
}

int checkWin() {
    // rows
    for (int i = 0; i < 3; i++)
        if (board[i][0] != ' ' &&
            board[i][0] == board[i][1] &&
            board[i][1] == board[i][2])
            return 1;

    // columns
    for (int j = 0; j < 3; j++)
        if (board[0][j] != ' ' &&
            board[0][j] == board[1][j] &&
            board[1][j] == board[2][j])
            return 1;

    // diagonals
    if (board[0][0] != ' ' &&
        board[0][0] == board[1][1] &&
        board[1][1] == board[2][2])
        return 1;

    if (board[0][2] != ' ' &&
        board[0][2] == board[1][1] &&
        board[1][1] == board[2][0])
        return 1;

    return 0;
}

int isDraw() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] == ' ')
                return 0;
    return 1;
}

int main() {
    int row, col;
    char currentPlayer = 'X';
    int gameOver = 0;

    initBoard();

    printf("Tic Tac Toe (Player X vs Player O)\n");
    printf("Enter row and column (0, 1, or 2)\n");

    while (!gameOver) {
        printBoard();
        printf("Player %c, enter row and column: ", currentPlayer);
        scanf("%d %d", &row, &col);

        if (row < 0 || row > 2 || col < 0 || col > 2) {
            printf("Invalid position. Try again.\n");
            continue;
        }

        if (board[row][col] != ' ') {
            printf("Cell already taken. Try again.\n");
            continue;
        }

        board[row][col] = currentPlayer;

        if (checkWin()) {
            printBoard();
            printf("Player %c wins!\n", currentPlayer);
            gameOver = 1;
        } else if (isDraw()) {
            printBoard();
            printf("It's a draw!\n");
            gameOver = 1;
        } else {
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
    }

    return 0;
}
