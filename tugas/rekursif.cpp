#include <iostream>
#include <string>

using namespace std;



// rekursif adalah fungsi yanf memanggil dirinya sendiri
/*void angka(int n){
	if (n <= 10){
		cout<< "loping ke :" <<n<< endl;
		angka(n+1);
		cout <<"lanjut ke" << n<< endl;
		
	}
}

int main() {
	angka(1);
	return 0;
}*/

//  continue : langsung melewati fungsi di bawahnya
// start again digunakan mirip seperti fungsi jadi dia ada memulai
int main(){
	
	int i=0;
		
	cout<< "before loop"<< endl;
	
	start_again://memulai
	i++;
	cout<< "inside loop"<< i<<endl;
	if(i<10) goto start_again;//mengakhir

	cout<< "after loop"<< endl;
	return 0;
}

// ldari string

