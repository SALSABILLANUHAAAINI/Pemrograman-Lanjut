#include <iostream>
#include <string.h>

using namespace std;
/*
int main(){
    int data[] = {5, 9, 3, 2, 7, 8, 3};
    int n = sizeof(data) / sizeof(int);

    for(int i = 0; i < n - 1; i++){
        int indexTerkecil = i;
        for(int j = i + 1; j < n; j++){
            if(data[indexTerkecil] > data[j])
                indexTerkecil = j;
        }
        
        // Tukar elemen terkecil dengan elemen di posisi i
        int temp = data[indexTerkecil];
        data[indexTerkecil] = data[i];
        data[i] = temp;
    }

    // Menampilkan data yang sudah diurutkan
    for(int i = 0; i < n; i++){
        cout << data[i] << " ";
    }
    cout << endl;

    return 0;
}*/

/*
int main(){
    int data[] = {5,4,3,2,1,3,2,1,2,1};
    
    for(int i =0 ; i<sizeof(data)/sizeof(int); i++ ){
        int indeksTerkecil = i;
        for(int j = i; j<sizeof(data)/sizeof(int); j++){
            if(data[indeksTerkecil]>data[j]) 
                indeksTerkecil = j;
        }

        int temp = data[indeksTerkecil];
        for(int j = indeksTerkecil; j>i; j--)
            data[j] = data[j-1];    
        data[i] = temp;

        for(int k =0 ; k<sizeof(data)/sizeof(int); k++ )
            cout<<data[k]<<", ";
        cout<<endl;
    }

}
*/

int main(){
	int data[] = {5,4,3,2,1,3,2,1,2,1};
	int n = sizeof(data) / sizeof(int);
	
	for(int i=0; i<n; i++){
		for(int j=0;j<n-1; j++){
		if(data[j]>data[j+1]){
			int temp = data [j];
			data[j]= data[j+1];
			data[j+1]= temp;
		}
		
        for(int k =0 ; k<sizeof(data)/sizeof(int); k++ )
            cout<<data[k]<<", ";
        cout<<endl;
		}
	}
	
	
}


#include <iostream>
using namespace std;

int main() {
    int data[] = {5, 9, 3, 2, 7, 8, 3};
    int n = sizeof(data) / sizeof(int);

    // Algoritma Bubble Sort untuk mengurutkan dari besar ke kecil
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (data[j] < data[j + 1]) { // Perbandingan untuk descending
                // Tukar elemen
                int temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }

    // Menampilkan data yang sudah diurutkan
    cout << "Data setelah diurutkan (besar ke kecil): ";
    for (int i = 0; i < n; i++) {
        cout << data[i] << " ";
    }
    cout << endl;

    return 0;
}



