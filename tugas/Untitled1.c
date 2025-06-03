#include <stdio.h>

char board[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
char human = 'O';
char ai = 'X';

// Menampilkan papan
void printBoard() {
    printf(" %c | %c | %c \n", board[0], board[1], board[2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[3], board[4], board[5]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[6], board[7], board[8]);
}

// Mengecek apakah ada yang menang
int checkWinner() {
    // Cek baris
    for (int i = 0; i < 9; i += 3) {
        if (board[i] == board[i+1] && board[i+1] == board[i+2] && board[i] != ' ') {
            return (board[i] == ai) ? 10 : -10;
        }
    }
    // Cek kolom
    for (int i = 0; i < 3; i++) {
        if (board[i] == board[i+3] && board[i+3] == board[i+6] && board[i] != ' ') {
            return (board[i] == ai) ? 10 : -10;
        }
    }
    // Cek diagonal
    if ((board[0] == board[4] && board[4] == board[8] && board[0] != ' ') ||
        (board[2] == board[4] && board[4] == board[6] && board[2] != ' ')) {
        return (board[4] == ai) ? 10 : -10;
    }
    return 0; // Tidak ada yang menang
}

// Mengecek apakah permainan seri
int isDraw() {
    for (int i = 0; i < 9; i++) {
        if (board[i] == ' ') {
            return 0; // Masih ada ruang kosong
        }
    }
    return 1; // Seri
}

// Algoritma minimax
int minimax(int depth, int isMaximizing) {
    int score = checkWinner();
    if (score == 10 || score == -10) {
        return score;
    }
    if (isDraw()) {
        return 0;
    }

    if (isMaximizing) {
        int bestScore = -1000;
        for (int i = 0; i < 9; i++) {
            if (board[i] == ' ') {
                board[i] = ai; // Simulasikan langkah AI
                int score = minimax(depth + 1, 0);
                board[i] = ' '; // Kembalikan papan
                bestScore = (score > bestScore) ? score : bestScore;
            }
        }
        return bestScore;
    } else {
        int bestScore = 1000;
        for (int i = 0; i < 9; i++) {
            if (board[i] == ' ') {
                board[i] = human; // Simulasikan langkah manusia
                int score = minimax(depth + 1, 1);
                board[i] = ' '; // Kembalikan papan
                bestScore = (score < bestScore) ? score : bestScore;
            }
        }
        return bestScore;
    }
}

// Mencari langkah terbaik untuk AI
int findBestMove() {
    int bestMove = -1;
    int bestScore = -1000;
    for (int i = 0; i < 9; i++) {
        if (board[i] == ' ') {
            board[i] = ai; // Simulasikan langkah AI
            int moveScore = minimax(0, 0); // Jalankan minimax
            board[i] = ' '; // Kembalikan papan
            if (moveScore > bestScore) {
                bestMove = i;
                bestScore = moveScore;
            }
        }
    }
    return bestMove;
}

// Jalankan permainan
void playGame() {
    int position;
    while (1) {
        printBoard();
        if (checkWinner() == 10) {
            printf("AI (X) menang!\n");
            break;
        } else if (checkWinner() == -10) {
            printf("Manusia (O) menang!\n");
            break;
        } else if (isDraw()) {
            printf("Permainan seri!\n");
            break;
        }

        if (currentPlayer == human) {
            printf("Pilih posisi (1-9): ");
            scanf("%d", &position);
            position--;
            if (board[position] == ' ') {
                board[position] = human;
                currentPlayer = ai;
            } else {
                printf("Posisi tidak valid!\n");
            }
        } else {
            printf("Giliran AI (X)...\n");
            int bestMove = findBestMove();
            board[bestMove] = ai;
            currentPlayer = human;
        }
    }
}

int main() {
    printf("Permainan Tic-Tac-Toe melawan AI menggunakan algoritma Minimax\n");
    playGame();
    return 0;


