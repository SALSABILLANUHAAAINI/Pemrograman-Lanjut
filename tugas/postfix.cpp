#include <iostream>
#include <cstdlib>
#include <string>
#include <cctype>
#include <algorithm>

using namespace std;

// Struktur Node untuk Linked List
typedef struct node {
    int data;
    struct node *next;
} Node;

// Struktur Stack
typedef struct Stack {
    int count;
    struct node *top;
} Stack;

Stack stack;

// Deklarasi fungsi
void createStack(Stack& stack); 
bool isEmpty(Stack& stack); // Mengecek apakah stack kosong
void pushStack(Stack& stack, int data); // Menambah elemen ke stack
int popStack(Stack& stack); // Menghapus elemen teratas dari stack dan mengembalikan nilainya
bool isOperator(char c); // Mengecek apakah karakter adalah operator aritmetika

// Deklarasi Fungsi Evaluasi Postfix
int evaluatePostfix(const string& postfix); // Mengevaluasi ekspresi postfix dan mengembalikan hasilnya
string infixToPostfix(const string& expression); // Konversi infiks ke postfix
string infixToPrefix(const string& expression); // Konversi infiks ke prefix

// Tampilan menu
int main() {
    string expression;
    createStack(stack);
    char pilihan;

    cout << "Masukkan ekspresi infiks (hanya angka 0-9 dan operator): ";
    cin >> expression;

    do {

        cout << "========= Menu ==========\n";
        cout << "Pilih opsi menu:\n";
        cout << "1. Konversi infiks ke postfix\n";
        cout << "2. Konversi infiks ke prefix\n";
        cout << "3. Hasil perhitungan\n";
        cout << "Masukkan pilihan (tekan E untuk keluar): ";
        cin >> pilihan;

        if (pilihan == '1') {
            string postfix = infixToPostfix(expression);
            cout << "Notasi postfix: " << postfix << endl;
        } else if (pilihan == '2') {
            string prefix = infixToPrefix(expression);
            cout << "Notasi prefix: " << prefix << endl;
        } else if (pilihan == '3') {
            string postfix = infixToPostfix(expression);
            int result = evaluatePostfix(postfix);
            cout << "Hasil perhitungan: " << result << endl;
        } else if (pilihan == 'E' || pilihan == 'e') {
            cout << "Keluar dari program.\n";
        } else {
            cout << "Pilihan tidak valid!\n";
        }
        cout << "\nTekan Enter untuk melanjutkan...\n";
        cin.ignore();
        cin.get();
    } while (pilihan != 'E' && pilihan != 'e');

    return 0;
}

// Membuat stack baru
void createStack(Stack& stack) {
    stack.count = 0;
    stack.top = NULL;
}

// Fungsi untuk mengecek apakah stack kosong
bool isEmpty(Stack& stack) {
    return stack.top == NULL;
}

// Menambah data di top
void pushStack(Stack& stack, int data) {
    Node *newPtr = new Node;
    if (newPtr == NULL) {
        cout << "Alokasi memori gagal!";
        return;
    }
    newPtr->data = data;
    newPtr->next = stack.top;
    stack.top = newPtr;
    stack.count++;
}

// Menghapus data pada top dan mengembalikan nilainya
int popStack(Stack& stack) {
    if (isEmpty(stack)) {
        cout << "Stack kosong, tidak ada data untuk di-pop.\n";
        return -1;
    }
    Node *dltPtr = stack.top;
    int dataOut = stack.top->data;
    stack.top = stack.top->next;
    delete dltPtr;
    stack.count--;
    return dataOut;
}

// Melihat data di top tanpa menghapus
int peek(Stack& stack) {
    if (isEmpty(stack)) {
        cout << "Stack kosong saat ini!\n";
        return -1;
    }
    return stack.top->data;
}

// Fungsi untuk mendapatkan prioritas operator
int getPrecedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

// Fungsi untuk mengecek apakah karakter adalah operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Fungsi konversi infiks ke postfix
string infixToPostfix(const string& expression) {
    string postfix;
    Stack tempStack;
    createStack(tempStack);

    for (size_t i = 0; i < expression.size(); ++i) {
        char c = expression[i];
        if (isalnum(c)) {
            postfix += c; 
        } else if (c == '(') {
            pushStack(tempStack, c);
        } else if (c == ')') {
            while (!isEmpty(tempStack) && peek(tempStack) != '(') {
                postfix += (char)popStack(tempStack);
            }
            popStack(tempStack);
        } else if (isOperator(c)) {
            while (!isEmpty(tempStack) && getPrecedence(peek(tempStack)) >= getPrecedence(c)) {
                postfix += (char)popStack(tempStack);
            }
            pushStack(tempStack, c);
        }
    }
    while (!isEmpty(tempStack)) {
        postfix += (char)popStack(tempStack);
    }

    return postfix;
}

// Fungsi konversi infiks ke prefix
string infixToPrefix(const string& expression) {
    string reversedExpression = expression;
    reverse(reversedExpression.begin(), reversedExpression.end());

    for (size_t i = 0; i < reversedExpression.size(); ++i) {
        if (reversedExpression[i] == '(') {
            reversedExpression[i] = ')';
        } else if (reversedExpression[i] == ')') {
            reversedExpression[i] = '(';
        }
    }

    string reversedPostfix = infixToPostfix(reversedExpression);
    reverse(reversedPostfix.begin(), reversedPostfix.end());

    return reversedPostfix;
}

// Fungsi untuk evaluasi ekspresi postfix
int evaluatePostfix(const string& postfix) {
    Stack evaluationStack;
    createStack(evaluationStack);

    for (size_t i = 0; i < postfix.size(); ++i) {
        char c = postfix[i];

        if (isdigit(c)) {
            pushStack(evaluationStack, c - '0');
        } else if (isOperator(c)) {
            int operand2 = popStack(evaluationStack);
            int operand1 = popStack(evaluationStack);

            switch (c) {
                case '+': pushStack(evaluationStack, operand1 + operand2); break;
                case '-': pushStack(evaluationStack, operand1 - operand2); break;
                case '*': pushStack(evaluationStack, operand1 * operand2); break;
                case '/': pushStack(evaluationStack, operand1 / operand2); break;
            }
        }
    }

    return popStack(evaluationStack);
}

