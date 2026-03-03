#include <iostream>
#include <string>
using namespace std;

//quick sort(descending)
void quick_sort(string array[], int awal, int akhir) {
	int low = awal, high = akhir;
	string pivot = array[(awal + akhir) / 2];
	
	do {
		while (array[low] > pivot) //tanda > untuk descending
			low++;
		while (array[high] < pivot) //tanda < untuk descending 
			high--;
			
		if (low <= high) {
			swap(array[low], array[high]);
			low++;
			high--;
		}
	} while (low < high);
	
	if (awal < high)
		quick_sort(array, awal, high);
	if (low < akhir)
		quick_sort(array, low, akhir);
	}
	
int main () {
	int n;
	
	cout << "Masukkan jumlah mahasiswa: ";
	cin >> n;
	cin.ignore();
	
	string nama[n];
	
	cout << "Masukkan daftar nama mahasiswa: " << endl;
	for(int i = 0; i < n; i++) {
		cout << "Nama ke-" << i + 1 << ": ";
		getline(cin, nama[i]);
	}
	
	//bubble sort (ascending)
	for(int i = 0; i < n - 1; i++) {
		for(int j = 0; j < n -1 - i; j++) {
			if(nama[j] > nama[j + 1]) {
			string temp = nama[j +1];
			nama[j + 1] = nama[j];
			nama[j] = temp;
		}
	}
}

	 cout << "\nData setelah diurutkan ascending (bubble sort):\n";
    for (int i = 0; i < n; i++) {
        cout << nama[i] << endl;
    }

    // Quick Sort (Descending)
    quick_sort(nama, 0, n - 1);

    cout << "\nData setelah diurutkan descending (quick sort):\n";
    for (int i = 0; i < n; i++) {
        cout << nama[i] << endl;
    }

    return 0;
}



