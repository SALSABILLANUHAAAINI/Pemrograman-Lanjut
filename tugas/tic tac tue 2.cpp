#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//untuk menggambar papan tic tac tue
void drawBoard(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %c |", board[i][j]); // untuk menggambar garis pada papan
        }
        printf("\n");
        if (i < 2) {
            printf("---+---+---\n");
        }
    }
}

// untuk cek pemenang dengan melihat kolom dan barisnya
int checkWin(char board[3][3], char player) {
    // cek baris
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return 1;
        }
    }
    // cek kolom
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return 1;
        }
    }
    // cek diagonal miring
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return 1;
    }
    return 0;
}

// untuk menghasilkan gerakan komputer
int generateMove(char board[3][3]) {
    int move;
    do { // do while berfungsi untuk mengulang pengecekan bil ada kolom atau baris udah diisi
        move = rand() % 9 + 1; // rand berguna untuk menentukan posisi acak yang kosong pada papan yang terdiri dari angka 1-9 yang teredPt dipapan
    } while (board[(move - 1) / 3][(move - 1) % 3] == 'X' || board[(move - 1) / 3][(move - 1) % 3] == 'O'); // menjalankan fungsi [(move - 1) / 3] (untuk cek baris) [(move - 1) % 3] == 'X' (untuk cek apa diisi oleh pemain Xatau O 
    return move;
}


// permainan tic tac tue
int main() {
    char board[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };
    char currentPlayer = 'X'; // untuk memanggil inputan yang kita masukan
    int moveCount = 0; // untuk memanggil komputer yang menjadi lawan

    srand(time(NULL)); // Seed the random number generator

    while (1) { // while do untuk mengulang setiap proses menerima inputan dan komputer mengisi secara berulang hingga menemukan hasil menang atau kalah
        drawBoard(board); // menampilkan papan
        if (currentPlayer == 'X') { // fungsi untuk pemain jalan
            printf("Mulailah permaian dengan memasukan dimana tenpat anda ingin memulai (1-9): ");
            int move; scanf("%d", &move); // menyimpan input
            int row = (move - 1) / 3;
            int col = (move - 1) % 3;
            if (board[row][col] != 'X' && board[row][col] != 'O') {
                board[row][col] = currentPlayer;
                moveCount++;
                if (checkWin(board, currentPlayer)) {
                    drawBoard(board);
                    printf("You win!!!;)\n");
                    break;
                }
                if (moveCount == 9) {
                    drawBoard(board);
                    printf("It's a draw!\n");
                    break;
                }
                currentPlayer = 'O';
            } else {
                printf("Invalid move, try again.\n");
            }
        } else {
            int move = generateMove(board); // fungsi komputer jalan
            int row = (move - 1) / 3;
            int col = (move - 1) % 3;
            board[row][col] = currentPlayer;
            moveCount++; // melacak total pergerakan
            printf("Computer's move: %d\n", move);
            if (checkWin(board, currentPlayer)) {
                drawBoard(board);
                printf("Computer wins!\n");
                break;
            }
            if (moveCount == 9) { //bila gambar papan penuh
                drawBoard(board);
                printf("It's a draw!\n");
                break;
            }
            currentPlayer = 'X';
        }
    }
    return 0;
}
