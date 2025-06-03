#include<iostream>
#include<stdio.h>

using namespace std;

/*
  int block(int _a, int _b) : { // parameter byval: (int _a, int _b)
  	int hasil = 0;
  	hasil= _a + _b;
  	
  	return hasil;
  }
  
  int main(){
  	int a= 1, b= 3;
  	
  	int hasil;
	block(a,b, &hasil);
  	cout<<hasil<<endl;
  	return 0;
  } */
  
void block(int _a, int _b, int *hasil)  { 
  	*hasil = _a + _b;
  }
  
  int main(){
  	int a= 1, b= 3;
  	int hasil;
	block(a,b, &hasil);
  	cout<<hasil<<endl;
  	return 0;
  }
  
  
