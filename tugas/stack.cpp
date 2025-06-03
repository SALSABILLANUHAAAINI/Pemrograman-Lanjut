#include <iostream>
#include <string>
#include <cctype>
#include <stdexcept>
#include <algorithm>
using namespace std;

// Struktur Node untuk Linked List
struct Node {
    int data;
    Node* next;
};

// Kelas Stack menggunakan Linked List
class Stack {
private:
    Node* top;

public:
    Stack() : top(NULL) {}

    // Fungsi untuk menambahkan elemen ke stack
    void push(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = top;
        top = newNode;
    }

    // Fungsi untuk menghapus elemen dari stack
    int pop() {
        if (isEmpty()) {
            throw runtime_error("Stack kosong!");
        }
        int value = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return value;
    }

    // Fungsi untuk melihat elemen teratas tanpa menghapusnya
    int peek() const {
        if (isEmpty()) {
            throw runtime_error("Stack kosong!");
        }
        return top->data;
    }

    // Fungsi untuk mengecek apakah stack kosong
    bool isEmpty() const {
        return top == NULL;
    }
};

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
    Stack stack;
    string postfix;

    for (char c : expression) {
        if (isalnum(c)) {
            postfix += c;
        } else if (c == '(') {
            stack.push(c);
        } else if (c == ')') {
            while (!stack.isEmpty() && stack.peek() != '(') {
                postfix += (char)stack.pop();
            }
            stack.pop();
        } else if (isOperator(c)) {
            while (!stack.isEmpty() && getPrecedence(stack.peek()) >= getPrecedence(c)) {
                postfix += (char)stack.pop();
            }
            stack.push(c);
        }
    }

    while (!stack.isEmpty()) {
        postfix += (char)stack.pop();
    }

    return postfix;
}

// Fungsi konversi infiks ke prefix
string infixToPrefix(const string& expression) {
    string reversedExpression = expression;
    reverse(reversedExpression.begin(), reversedExpression.end());

    for (char& c : reversedExpression) {
        if (c == '(') c = ')';
        else if (c == ')') c = '(';
    }

    string reversedPostfix = infixToPostfix(reversedExpression);
    reverse(reversedPostfix.begin(), reversedPostfix.end());

    return reversedPostfix;
}

// Fungsi menghitung hasil ekspresi postfix
int evaluatePostfix(const string& postfix) {
    Stack evaluationStack;

    for (char c : postfix) {
        if (isdigit(c)) {
            evaluationStack.push(c - '0'); // Mengonversi karakter ke integer
        } else if (isOperator(c)) {
            int operand2 = evaluationStack.pop();
            int operand1 = evaluationStack.pop();
            
            switch (c) {
                case '+': evaluationStack.push(operand1 + operand2); break;
                case '-': evaluationStack.push(operand1 - operand2); break;
                case '*': evaluationStack.push(operand1 * operand2); break;
                case '/': evaluationStack.push(operand1 / operand2); break;
            }
        }
    }
    
    return evaluationStack.pop();
}

// Fungsi utama
int main() {
    string expression;
    int choice;

    cout << "Masukkan ekspresi infiks (hanya angka 0-9 dan operator): ";
    cin >> expression;

    do {
        cout << "\nMenu:\n";
        cout << "1. Konversi infiks ke postfix\n";
        cout << "2. Konversi infiks ke prefix\n";
        cout << "3. Hitung hasil ekspresi\n";
        cout << "4. Keluar\n";
        cout << "Pilih opsi: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string postfix = infixToPostfix(expression);
                cout << "Notasi postfix: " << postfix << endl;
                break;
            }
            case 2: {
                string prefix = infixToPrefix(expression);
                cout << "Notasi prefix: " << prefix << endl;
                break;
            }
            case 3: {
                string postfix = infixToPostfix(expression);
                int result = evaluatePostfix(postfix);
                cout << "Hasil perhitungan: " << result << endl;
                break;
            }
            case 4:
                cout << "Keluar dari program." << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
                break;
        }
    } while (choice != 4);

    return 0;
}

