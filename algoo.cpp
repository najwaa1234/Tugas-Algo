#include <iostream>
using namespace std;

#define debug(x) cout << #x << " => " << (x) << endl;

int main() {
	int array[3] = {10, 20, 30};
	debug(array[2]);
	debug(array + 2);
	
	array[1] = 50;
	debug(array[1]);
	
	for (int i = 0; i < 3; ++i) {
		cout << *(array + i) << " ";
	}
	cout << endl << endl;
	
	char nama[] = "REZA";
	char* nama_ptr = nama;
	nama_ptr = nama_ptr + 1;
	debug(nama_ptr);
		
	
}
