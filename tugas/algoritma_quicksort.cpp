#include <iostream>
#include <string>

using namespace std;
// pivot diambil dinilai akhir
// j = index awal
// i = index sebelum j / - j
// temp= menukar  nilai elemen
// pertanyaan ="apakah data ke j lebih besar dari pivot? jika ya maka j di geser/ apakah data ke j lebih kecil daripada data pivot? jika ya maka i naik 1 dan j di swap ke i"
// swipe dilakukan jika nilai j lebih kecil dari pivot
// jika j sudah = [ivot maka i +1 ]
// jika posisi i lebih besar dari pivot ditukar

// membagi array menjadi 2 bagian (kanan&kir)
// kanan akan diproses dengan langkah yang sama
// 0 = pivot=1

void tukar(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int quick(int data[], int start, int end)
{
    int n = sizeof(data) / sizeof(int);
    int pivot = n - 1;
    int i = (start - 1);
    for (int j = start; j < end; j++)
    {
        if (data[j] < pivot)
        {
            i++;
            tukar(&data[i], &data[j]);
        }
    }
}

void quickSort(int data[], int start, int end)
{
    if (start < end)
    {
        int pi = quick(data, start, end); // Dapatkan indeks pivot

        // Rekursi untuk bagian kiri dan kanan array
        quickSort(data, start, pi - 1);
        quickSort(data, pi + 1, end);
    }
}

main()
{
    int data[] = {5, 4, 3, 2, 1, 10, 9, 8, 7, 6};
}
