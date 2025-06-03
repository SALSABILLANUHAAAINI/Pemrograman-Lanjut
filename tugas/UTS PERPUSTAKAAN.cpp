#include <iostream>
#include <string>

using namespace std;

#define MAKS_BUKU 100 // Maksimal jumlah buku yang dapat disimpan

// Definisi struct untuk Buku
struct Buku {
    string id_buku;	
    string judul;
    string penulis;
    string penerbit;
    int jumlah_stok;
};

// Array untuk menyimpan daftar buku(array of struct)
Buku perpustakaan[MAKS_BUKU]; 
int jumlahBuku = 0;           // deklarasi jumlah buku dalam perpustakaan


// Fungsi menambah buku
void tambahBuku() {
    if (jumlahBuku >= MAKS_BUKU) {
        cout << "maaf saat ini, Perpustakaan sudah penuh!" << endl;
        return;
    }

    // Mengisi informasi buku
    cout << "Masukkan ID buku: ";
    cin.ignore(); getline(cin, perpustakaan[jumlahBuku].id_buku);
    cout << "Masukkan Judul Buku: ";
	getline(cin, perpustakaan[jumlahBuku].judul);
    cout << "Masukkan Nama Penulis: "; 
	getline(cin, perpustakaan[jumlahBuku].penulis);
    cout << "Masukkan Nama Penerbit: "; 
	getline(cin, perpustakaan[jumlahBuku].penerbit);
    cout << "Masukkan Jumlah Stok: ";
    cin >> perpustakaan[jumlahBuku].jumlah_stok;

    jumlahBuku++;
    cout << "Buku sudah berhasil ditambahkan!" << endl;
}

// Fungsi rekursif untuk menampilkan detail buku per baris
void tampilkanBukuRekursif(int indeks) {
    if (indeks >= jumlahBuku) { // kondisi dasar untuk menghentikan rekursi
        return;
    }

    // Menampilkan detail buku per baris
    cout << "Judul     : " << perpustakaan[indeks].judul << endl;
    cout << "Penulis   : " << perpustakaan[indeks].penulis << endl;
    cout << "Penerbit  : " << perpustakaan[indeks].penerbit << endl;
    cout << "ID Buku   : " << perpustakaan[indeks].id_buku << endl;
    cout << "-----------------------------" << endl;

    // Panggilan rekursif untuk buku berikutnya
    tampilkanBukuRekursif(indeks + 1);
}

// Fungsi utama untuk menampilkan daftar buku 
void tampilkanBuku() {
    if (jumlahBuku == 0) {
        cout << "Tidak ada data buku." << endl;
        return;
    }
    cout << "Daftar Buku di Perpustakaan:" << endl;
    tampilkanBukuRekursif(0); // supaya mulai dari buku pertama
}


// Fungsi mengedit buku
void ubahBuku() {
    string id_buku;
    cout << "Masukkan ID buku yang ingin diedit: ";
    cin.ignore();
    getline(cin, id_buku);

    for (int i = 0; i < jumlahBuku; i++) {
        if (perpustakaan[i].id_buku == id_buku) {
            cout << "Masukan ID buku: " << id_buku << endl;
            int pilihanUbah;
            cout << "\nPilih apa yang ingin diedit:" << endl;
            cout << "1. Ubah  Judul" << endl;
            cout << "2. Ubah Penulis" << endl;
            cout << "3. Ubah Penerbit" << endl;
            cout << "4. Ubah Jumlah Stok" << endl;
            cout << "5. Ubah Semua Data" << endl;
            cout << "Pilih opsi: ";
            cin >> pilihanUbah;
            cin.ignore();

            switch (pilihanUbah) {
                case 1:
                    cout << "Masukkan judul baru: "; getline(cin, perpustakaan[i].judul);
                    break;
                case 2:
                    cout << "Masukkan penulis baru: "; getline(cin, perpustakaan[i].penulis);
                    break;
                case 3:
                    cout << "Masukkan penerbit baru: "; getline(cin, perpustakaan[i].penerbit);
                    break;
                case 4:
                    cout << "Masukkan jumlah stok baru: ";
                    cin >> perpustakaan[i].jumlah_stok;
                    cin.ignore();
                    break;
                case 5:
                    cout << "Masukkan judul baru: "; getline(cin, perpustakaan[i].judul);
                    cout << "Masukkan penulis baru: "; getline(cin, perpustakaan[i].penulis);
                    cout << "Masukkan penerbit baru: "; getline(cin, perpustakaan[i].penerbit);
                    cout << "Masukkan jumlah stok baru: ";
                    cin >> perpustakaan[i].jumlah_stok;
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
void hapusBuku() {
    string id_buku;
    cout << "Masukkan ID buku yang ingin dihapus: ";
    cin.ignore();
    getline(cin, id_buku);

    for (int i = 0; i < jumlahBuku; i++) {
        if (perpustakaan[i].id_buku == id_buku) {
            // Menggeser buku setelah yang dihapus
            for (int j = i; j < jumlahBuku - 1; j++) {
                perpustakaan[j] = perpustakaan[j + 1];
            }
            jumlahBuku--;
            cout << "Buku berhasil dihapus!" << endl;
            return;
        }
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
        cout << "masukan pilihan yang diinginkan ";
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

