#include <iostream>
using namespace std;

#define debug(x) cout << #x << " => " << (x) << endl;

int main() {
	//deklarasi pointer
	int* num_ptr = NULL;
	cout << num_ptr;
	
	int num_var = 15;
	num_ptr = &num_var; //inisialisai// ngasih nilai ke num_ptr
	debug(num_ptr);
	num_var = 20;
	debug(*num_ptr); //dereference cara menggambil nilai dari pointer 
	
	*num_ptr = 25;
	debug(*num_ptr);
	debug(num_var);
	
	
}
