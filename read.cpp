#include <iostream>
using namespace std;

int main(){
	const char* filename = "data.bin";
	FILE* file_ptr = fopen(filename, "rb");
	
	if (file_ptr == NULL){
		cout << "Gagal membaca file!";
		exit(1); //program eror
	}
	
	//fgets
	//~ char hasil_baca[20];
	int hasil_baca;
	cout <<"Hasil baca sebelum file : " << hasil_baca << endl;
	
	//sizeof
	//fgets(hasil_baca, 16, file_ptr);
	//~ fgets(hasil_baca, sizeof(hasil_baca)/ sizeof(char), file_ptr);
	//~ cout <<"Hasil baca setelah file : " << hasil_baca << endl;
	
	//fscanf
	//~ fscanf(file_ptr, "%s", hasil_baca);
	//~ while(fscanf(file_ptr, "%*s%s", hasil_baca) != EOF) {
	//~ cout << "hasil baca setelah file:" << hasil_baca << endl;
	
	//fread
	fread(&hasil_baca, sizeof(int), 1, file_ptr);
	cout << "hasil baca setelah file: " << hasil_baca << endl;
	fclose(file_ptr);
	
}
