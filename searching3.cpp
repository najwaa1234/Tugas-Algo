#include <iostream>
using namespace std;

int main () {
	int array[9] = {1, 2, 3, 4, 5, 6, 7, 8};
	int cari = 5;
	int awal, tengah, akhir;
	bool ketemu = false;
	
	awal = 0;
	akhir = 7;
	
	while((!ketemu) && (awal <= akhir)) {
	tengah = (awal+akhir) /2;
	if(cari == array[tengah]) {
		ketemu = true;
	}
	else if(cari < array[tengah]) {
		akhir = tengah - 1;
	} else if (cari > array[tengah]) {
		awal = tengah + 1;
			}
		}
		if(ketemu) {
			cout << "ditemukan";
		} else {
			cout << "tidak ditemukan";
		}

}
