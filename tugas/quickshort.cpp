#include <iostream>
#include <string>

using namespace std;

// Fungsi untuk menampilkan isi array
void tampilkan(int arr[], int size)
{
    for (int i = 0; i < 10; i++)

        cout << arr[i] << " ";

    cout << endl;
}

// Fungsi untuk mengurutkan array (menggunakan algoritma asli Anda)
void mySort(int arr[], int iStart, int iPivot, int iEnd)
{
    int i = iStart - 1, j = iStart, temp;

    while (j < iPivot)
    {
        if (arr[j] < arr[iPivot])
        {
            i++;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            j++;
        }
        else
            j++;
    }
    i++;
    if (arr[i] > arr[iPivot])
    {
        temp = arr[i];
        arr[i] = arr[iPivot];
        arr[iPivot] = temp;
        iPivot = i;
    }
    tampilkan(arr, iEnd + 1);
    // kiri
    if (iPivot > iStart)
        mySort(arr, iStart, iPivot - 1, iPivot - 1);
    // kanan
    if (iPivot > iEnd)
        mySort(arr, iPivot + 1, iEnd, iEnd);
}

int main()
{
    int arr[] = {5, 4, 3, 2, 1, 10, 9, 8, 7, 6};
    int n = sizeof(arr) / sizeof(int);

    // Memanggil fungsi mySort
    mySort(arr, 0, n - 1, n - 1);

    return 0;
}
