#include <iostream>
#include <string>

using namespace std;

// Definisi struktur untuk Buku
struct Buku {
    string id_buku;
    string judul;
    string penulis;
    string penerbit;
    int jumlah_stok;
    Buku* next; // Pointer ke buku berikutnya (untuk linked list)
};

// Pointer ke kepala linked list
Buku* head = NULL;

// Fungsi menambah buku
void tambahBuku() {
    Buku* bukuBaru = new Buku;

    cout << "Masukkan ID buku: ";
    cin.ignore(); getline(cin, bukuBaru->id_buku);
    cout << "Masukkan Judul Buku: ";
    getline(cin, bukuBaru->judul);
    cout << "Masukkan Nama Penulis: ";
    getline(cin, bukuBaru->penulis);
    cout << "Masukkan Nama Penerbit: ";
    getline(cin, bukuBaru->penerbit);
    cout << "Masukkan Jumlah Stok: ";
    cin >> bukuBaru->jumlah_stok;
    bukuBaru->next = NULL;

    if (head == NULL) {
        head = bukuBaru;
    } else {
        Buku* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = bukuBaru;
    }

    cout << "Buku sudah berhasil ditambahkan!" << endl;
}

// Fungsi rekursif untuk menampilkan detail buku per baris
void tampilkanBukuRekursif(Buku* buku) {
    if (buku == NULL) {
        return;
    }

    // Menampilkan detail buku per baris
    cout << "Judul     : " << buku->judul << endl;
    cout << "Penulis   : " << buku->penulis << endl;
    cout << "Penerbit  : " << buku->penerbit << endl;
    cout << "ID Buku   : " << buku->id_buku << endl;
    cout << "-----------------------------" << endl;

    tampilkanBukuRekursif(buku->next); // Panggilan rekursif untuk buku berikutnya
}

// Fungsi utama untuk menampilkan daftar buku
void tampilkanBuku() {
    if (head == NULL) {
        cout << "Tidak ada data buku." << endl;
        return;
    }
    cout << "Daftar Buku di Perpustakaan:" << endl;
    tampilkanBukuRekursif(head);
}

// Fungsi mengedit buku
void ubahBuku() {
    string id_buku;
    cout << "Masukkan ID buku yang ingin diedit: ";
    cin.ignore();
    getline(cin, id_buku);

    Buku* temp = head;
    while (temp != NULL) {
        if (temp->id_buku == id_buku) {
            int pilihanUbah;
            cout << "\nPilih apa yang ingin diedit:" << endl;
            cout << "1. Ubah Judul" << endl;
            cout << "2. Ubah Penulis" << endl;
            cout << "3. Ubah Penerbit" << endl;
            cout << "4. Ubah Jumlah Stok" << endl;
            cout << "5. Ubah Semua Data" << endl;
            cout << "Pilih opsi: ";
            cin >> pilihanUbah;
            cin.ignore();

            switch (pilihanUbah) {
                case 1:
                    cout << "Masukkan judul baru: "; getline(cin, temp->judul);
                    break;
                case 2:
                    cout << "Masukkan penulis baru: "; getline(cin, temp->penulis);
                    break;
                case 3:
                    cout << "Masukkan penerbit baru: "; getline(cin, temp->penerbit);
                    break;
                case 4:
                    cout << "Masukkan jumlah stok baru: ";
                    cin >> temp->jumlah_stok;
                    cin.ignore();
                    break;
                case 5:
                    cout << "Masukkan judul baru: "; getline(cin, temp->judul);
                    cout << "Masukkan penulis baru: "; getline(cin, temp->penulis);
                    cout << "Masukkan penerbit baru: "; getline(cin, temp->penerbit);
                    cout << "Masukkan jumlah stok baru: ";
                    cin >> temp->jumlah_stok;
                    cin.ignore();
                    break;
                default:
                    cout << "Silahkan masukan opsi yang ada." << endl;
            }

            cout << "Buku berhasil diperbarui!" << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Tidak ada buku dengan kode tersebut." << endl;
}

// Fungsi menghapus buku
void hapusBuku() {
    string id_buku;
    cout << "Masukkan ID buku yang ingin dihapus: ";
    cin.ignore();
    getline(cin, id_buku);

    Buku* temp = head;
    Buku* prev = NULL;

    while (temp != NULL) {
        if (temp->id_buku == id_buku) {
            if (prev == NULL) {
                head = temp->next;
            } else {
                prev->next = temp->next;
            }
            delete temp;
            cout << "Buku berhasil dihapus!" << endl;
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    cout << "Tidak ada buku dengan kode tersebut." << endl;
}

// Menu utama
int main() {
    int pilihan;
    do {
        cout << "\n=== Sistem Perpustakaan ===" << endl;
        cout << "1. Tambah Buku" << endl;
        cout << "2. Tampilkan Buku" << endl;
        cout << "3. Edit Buku" << endl;
        cout << "4. Hapus Buku" << endl;
        cout << "5. Keluar" << endl;
        cout << "Masukan pilihan yang diinginkan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tambahBuku();
                cout << "===================\n" << endl;
                break;
            case 2:
                tampilkanBuku();
                cout << "===================\n" << endl;
                break;
            case 3:
                ubahBuku();
                cout << "===================\n" << endl;
                break;
            case 4:
                hapusBuku();
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
    } while (pilihan != 5);

    return 0;
}

