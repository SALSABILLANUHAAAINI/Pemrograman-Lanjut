#include <iostream>
#include <string>
using namespace std;

// Struktur Buku
struct Buku {
    int id;
    string judul;
    string penulis;
    string penerbit;
    int jumlah_stock;
};

// Maksimal jumlah buku yang dapat disimpan
const int MAKS_BUKU = 100;
int jumlahBukuSaatIni = 0;  // Menghitung jumlah buku yang ada

// Fungsi untuk menambahkan buku ke dalam perpustakaan
void tambahBuku(Buku perpustakaan[], int id, string judul, string penulis, string penerbit, int jumlah_stock) {
    if (jumlahBukuSaatIni < MAKS_BUKU) {
        perpustakaan[jumlahBukuSaatIni] = {id, judul, penulis, penerbit, jumlah_stock};
        jumlahBukuSaatIni++;
        cout << "Buku berhasil ditambahkan.\n";
    } else {
        cout << "Perpustakaan penuh. Tidak bisa menambahkan buku baru.\n";
    }
}

// Fungsi untuk menampilkan daftar buku
void tampilkanBuku(const Buku perpustakaan[]) {
    if (jumlahBukuSaatIni == 0) {
        cout << "Perpustakaan kosong.\n";
        return;
    }

    for (int i = 0; i < jumlahBukuSaatIni; i++) {
        cout << "ID Buku: " << perpustakaan[i].id << endl;
        cout << "Judul Buku: " << perpustakaan[i].judul << endl;
        cout << "Penulis: " << perpustakaan[i].penulis << endl;
        cout << "Penerbit: " << perpustakaan[i].penerbit << endl;
        cout << "Jumlah Stok: " << perpustakaan[i].jumlah_stock << endl;
        cout << "---------------------------" << endl;
    }
}

// Fungsi untuk mencari buku berdasarkan ID
int cariBuku(const Buku perpustakaan[], int id) {
    for (int i = 0; i < jumlahBukuSaatIni; i++) {
        if (perpustakaan[i].id == id) {
            return i;  // Mengembalikan indeks buku jika ditemukan
        }
    }
    return -1;  // Jika tidak ditemukan
}

// Fungsi untuk mengubah isi buku berdasarkan ID
void ubahBuku(Buku perpustakaan[], int id) {
    int indeks = cariBuku(perpustakaan, id);
    if (indeks != -1) {
        cout << "Buku ditemukan. Masukkan informasi baru:" << endl;
        cout << "Masukkan Judul Baru: ";
        cin.ignore();
        getline(cin, perpustakaan[indeks].judul);
        cout << "Masukkan Penulis Baru: ";
        getline(cin, perpustakaan[indeks].penulis);
        cout << "Masukkan Penerbit Baru: ";
        getline(cin, perpustakaan[indeks].penerbit);
        cout << "Masukkan Jumlah Stok Baru: ";
        cin >> perpustakaan[indeks].jumlah_stock;
        cout << "Buku berhasil diubah.\n";
    } else {
        cout << "Buku dengan ID " << id << " tidak ditemukan.\n";
    }
}

// Fungsi untuk menghapus buku berdasarkan ID
void hapusBuku(Buku perpustakaan[], int id) {
    int indeks = cariBuku(perpustakaan, id);
    if (indeks != -1) {
        // Menggeser elemen setelah buku yang dihapus ke depan
        for (int i = indeks; i < jumlahBukuSaatIni - 1; i++) {
            perpustakaan[i] = perpustakaan[i + 1];
        }
        jumlahBukuSaatIni--;  // Kurangi jumlah buku saat ini
        cout << "Buku dengan ID " << id << " berhasil dihapus.\n";
    } else {
        cout << "Buku dengan ID " << id << " tidak ditemukan.\n";
    }
}

int main() {
    Buku perpustakaan[MAKS_BUKU];  // Array untuk menyimpan daftar buku

    int pilihan, id, jumlah_stock;
    string judul, penulis, penerbit;

    do {
        cout << "\n=== Sistem Perpustakaan ===\n";
        cout << "1. Tambah Buku\n";
        cout << "2. Tampilkan Buku\n";
        cout << "3. Cari Buku Berdasarkan ID\n";
        cout << "4. Ubah Buku Berdasarkan ID\n";
        cout << "5. Hapus Buku Berdasarkan ID\n";
        cout << "6. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan ID Buku: ";
                cin >> id;
                cin.ignore();  // Mengabaikan karakter newline
                cout << "Masukkan Judul Buku: ";
                getline(cin, judul);
                cout << "Masukkan Penulis Buku: ";
                getline(cin, penulis);
                cout << "Masukkan Penerbit Buku: ";
                getline(cin, penerbit);
                cout << "Masukkan Jumlah Stok: ";
                cin >> jumlah_stock;
                tambahBuku(perpustakaan, id, judul, penulis, penerbit, jumlah_stock);
                break;
            case 2:
                cout << "\nDaftar Buku:\n";
                tampilkanBuku(perpustakaan);
                break;
            case 3:
                cout << "Masukkan ID Buku yang dicari: ";
                cin >> id;
                int indeks;
                indeks = cariBuku(perpustakaan, id);
                if (indeks != -1) {
                    cout << "Buku Ditemukan:" << endl;
                    cout << "ID Buku: " << perpustakaan[indeks].id << endl;
                    cout << "Judul Buku: " << perpustakaan[indeks].judul << endl;
                    cout << "Penulis: " << perpustakaan[indeks].penulis << endl;
                    cout << "Penerbit: " << perpustakaan[indeks].penerbit << endl;
                    cout << "Jumlah Stok: " << perpustakaan[indeks].jumlah_stock << endl;
                } else {
                    cout << "Buku dengan ID " << id << " tidak ditemukan." << endl;
                }
                break;
            case 4:
                cout << "Masukkan ID Buku yang ingin diubah: ";
                cin >> id;
                ubahBuku(perpustakaan, id);
                break;
            case 5:
                cout << "Masukkan ID Buku yang ingin dihapus: ";
                cin >> id;
                hapusBuku(perpustakaan, id);
                break;
            case 6:
                cout << "Keluar dari program.\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
                break;
        }
    } while (pilihan != 6);

    return 0;
}


