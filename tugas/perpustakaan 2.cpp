#include <iostream>
#include <string>

using namespace std;

#define MAX_BOOKS 100 // Maksimal jumlah buku yang dapat disimpan

// Definisi struct untuk Buku
struct Book {
    string id_buku;    // kode_buku berupa string// buat pakai string
    string judul;
    string penulis;
    string penerbit;
    int jumlah_stock;
};

// Array untuk menyimpan daftar buku
Book* library[MAX_BOOKS]; // Pointer array untuk struct Book
int bookCount = 0;        // Jumlah buku dalam perpustakaan

// Fungsi menambah buku
void addBook() {
    if (bookCount >= MAX_BOOKS) {
        cout << "Perpustakaan sudah penuh!" << endl;
        return;
    }

    // Mengalokasikan memori untuk buku baru
    Book* newBook = new Book;

    // Mengisi informasi buku
    cout << "Masukkan ID buku: ";
    cin.ignore(); getline(cin, newBook->id_buku);
    cout << "Masukkan Judul Buku: "; getline(cin, newBook->judul);
    cout << "Masukkan Nama Penulis: "; getline(cin, newBook->penulis);
    cout << "Masukkan Nama Penerbit: "; getline(cin, newBook->penerbit);
    cout << "Masukkan Jumlah Stock: ";
    cin >> newBook->jumlah_stock;

    // Menambahkan buku ke array
    library[bookCount] = newBook;
    bookCount++;

    cout << "Buku sudah berhasil ditambahkan!" << endl;
}

// Fungsi menampilkan daftar buku
void displayBooks() {
    if (bookCount == 0) { //jika jumlah buku 0 maka tidak ada data buku
        cout << "Tidak ada data buku." << endl;
        return;
    }

    cout << "Daftar Buku di Perpustakaan:" << endl;
    for (int i = 0; i < bookCount; i++) {
        cout << "ID Buku: " << library[i]->id_buku
             << ", Judul: " << library[i]->judul
             << ", Penulis: " << library[i]->penulis
             << ", Penerbit: " << library[i]->penerbit << endl;
    }
}

// Fungsi mengedit buku
void updateBook() {
    string id_buku;
    cout << "Masukkan kode buku yang ingin diedit: ";
    cin.ignore();
    getline(cin, id_buku);

    for (int i = 0; i < bookCount; i++) {
        if (library[i]->id_buku == id_buku) {
            cout << "Masukan ID buku: " << id_buku << endl;
            int editChoice;
            cout << "\nPilih apa yang ingin diedit:" << endl;
            cout << "1. Judul" << endl;
            cout << "2. Penulis" << endl;
            cout << "3. Penerbit" << endl;
            cout << "4. Jumlah Stock" << endl;
            cout << "5. Semua Data" << endl;
            cout << "Pilih opsi: ";
            cin >> editChoice;
            cin.ignore();

            switch (editChoice) {
                case 1:
                    cout << "Masukkan judul baru: "; getline(cin, library[i]->judul);
                    break;
                case 2:
                    cout << "Masukkan penulis baru: "; getline(cin, library[i]->penulis);
                    break;
                case 3:
                    cout << "Masukkan penerbit baru: "; getline(cin, library[i]->penerbit);
                    break;
                case 4:
                    cout << "Masukkan jumlah stock baru: ";
                    cin >> library[i]->jumlah_stock;
                    cin.ignore();
                    break;
                case 5:
                    cout << "Masukkan judul baru: "; getline(cin, library[i]->judul);
                    cout << "Masukkan penulis baru: "; getline(cin, library[i]->penulis);
                    cout << "Masukkan penerbit baru: "; getline(cin, library[i]->penerbit);
                    cout << "Masukkan jumlah stock baru: ";
                    cin >> library[i]->jumlah_stock;
                    cin.ignore();
                    break;
                default:
                    cout << "Silahkan masukan opsi yang ada." << endl;
            }

            cout << "Buku berhasil diperbarui!" << endl;
            return;
        }
    }
    cout << "Tidak ada buku dengan kode tersebut." << endl;
}

// Fungsi menghapus buku
void deleteBook() {
    string id_buku;
    cout << "Masukkan kode buku yang ingin dihapus: ";
    cin.ignore();
    getline(cin, id_buku);

    for (int i = 0; i < bookCount; i++) {
        if (library[i]->id_buku == id_buku) {
            delete library[i]; // Hapus memori yang dialokasikan untuk buku

            // Menggeser buku setelah yang dihapus
            for (int j = i; j < bookCount - 1; j++) {
                library[j] = library[j + 1];
            }
            bookCount--;
            cout << "Buku berhasil dihapus!" << endl;
            return;
        }
    }
    cout << "Tidak ada buku dengan kode tersebut." << endl;
}

// Menu utama
int main() {
    int choice;
    do {
        cout << "\n=== Sistem Perpustakaan ===" << endl;
        cout << "1. Tambah Buku" << endl;
        cout << "2. Tampilkan Buku" << endl;
        cout << "3. Edit Buku" << endl;
        cout << "4. Hapus Buku" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilih opsi: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addBook();
                cout << "===================\n" << endl;
                break;
            case 2:
                displayBooks();
                cout << "===================\n" << endl;
                break;
            case 3:
                updateBook();
                cout << "===================\n" << endl;
                break;
            case 4:
                deleteBook();
                cout << "===================\n" << endl;
                break;
            case 5:
                cout << "Keluar dari program." << endl;
                cout << "===================\n" << endl;
                break;
            default:
                cout << "Opsi tidak valid." << endl;
                cout << "===================\n" << endl;
        }
    } while (choice != 5);

    // Menghapus semua buku sebelum keluar
    for (int i = 0; i < bookCount; i++) {
        delete library[i];
    }

    return 0;
}
