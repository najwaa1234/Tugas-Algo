#include <iostream>
using namespace std;

int main () {
	const int kSize = 8;
	int array[kSize] = {1, 2, 3, 4, 5, 6, 7, 8};
	
	int cari = 5;
	
	//LINEAR SEARCH TANPA SENTINEL
	int index = 0;
	bool ketemu = false;
	
	while (index < kSize && ketemu != true) {
		if (array[index] == cari) {
			ketemu = true;
			break;
		}
		index++;
	}
	if (ketemu) cout << cari << " ditemukan";
	else cout << "tidak ditemukan!";
}
