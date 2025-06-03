#include <iostream>
#include <list>

using namespace std;

int main () {
    int arr[10] = {9, 5, 6, 7, 3, 4, 2, 1, 5, 6};
    list<int> l;  // Daftar untuk menyimpan indeks elemen yang ditemukan

    int key = 6;

    // Pencarian linear
    for (int i = 0; i < (sizeof(arr) / sizeof(int)); i++) {
        if (key == arr[i]) {
            l.push_back(i);  // Menyimpan indeks ke dalam list
        }
    }

    // Menampilkan semua indeks yang ditemukan
    for (int item : l) {
        cout << item <<endl;
    }
    cout << endl;

    return 0;
}
