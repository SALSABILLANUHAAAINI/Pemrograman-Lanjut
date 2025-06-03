#include <iostream>
using namespace std;

int main(){
    int data[] = {5,4,3,2,1,3,2,1,2,1};
    int n = sizeof(data) / sizeof(int);

    
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - 1 - i; j++) {
            if(data[j] > data[j + 1]) {
                
                int temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }

    
    for(int k =0 ; k<sizeof(data)/sizeof(int); k++ )
        cout<<data[k]<<", ";
        cout<<endl;

    return 0;
}

