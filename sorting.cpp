#include <iostream>
using namespace std;

void tampilData(int array[], int size)
{
	for(int i = 0; i < size; i++)
	{
	cout << array[i] << " ";
	}
}

void bubbleSort(int array[], int size)
{
	for(int i = 0; i < size - 1; i++)
	{
		for(int j = 0; j < size - i - 1; j++)
		{
			if(array[j] > array[j+1]) // < ascending, > descending
			{
				//~ int temp = array[j+1];
				//~ array[j+1] = array[j];
				//~ array[j] = temp;
				swap(array[j], array[j+1]) //sebuah fungsi
			} 
		}
	}
	
}

int main() {
	int n = 5;
	int array[n] = {5, 3, 1, 4, 2};
	
	cout << "Data sebelum disort:" << endl;
	tampilData(array, n);
	cout << endl;
	
	bubbleSort(array,n);
	cout << "Data setelah di sort: (Bubble sort): " << endl;
	tampilData(array, n);	
	
}
