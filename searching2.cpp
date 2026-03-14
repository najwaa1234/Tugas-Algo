#include <iostream>
using namespace std;

int main () {
	int cari = 8;
	int array[8] = {1, 2, 3, 4, 5, 6, 7, 8};
	array[8] = cari; // memasukkan nilai yang dicari di array
	
	int x = 0;
	while(array[x] != array[8]) {
		x++;
	}
	
	if (x == 8) {
		cout << "tidak ketemu";
	}
	else {
		cout << "ketemu di indeks ke-" << x;
	}
}
