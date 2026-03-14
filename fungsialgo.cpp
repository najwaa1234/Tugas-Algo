#include <iostream>
using namespace std;

#define debug(x) cout << #x << " => " << (x) << endl;

void ubahNilai(int* num) {
	*num = 22;
}

int main () {
	int num = 18;
	cout << "nilai sebelum diubah";
	debug(num);
	ubahNilai(&num);
	cout << "nilai setelah diubah";
	debug(num);
}
