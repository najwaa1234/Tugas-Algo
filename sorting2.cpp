#include <iostream>
using namespace std;

void quick_sort(int array[], int awal, int akhir) {

    int low = awal, high = akhir;

    int pivot = array[(awal + akhir) / 2];


    do {

        while (array[low] < pivot)

            low++;

        while (array[high] > pivot)

            high--;


        if (low <= high) {

            swap(array[low], array[high]);

            low++;

            high--;

        }

    } while (low <= high);


    if (awal < high)

        quick_sort(array, awal, high);

    if (low < akhir)

        quick_sort(array, low, akhir);

}

int main() {

    int values[] = {9, 3, 16, 2, 18, 8, 30};

    int n = sizeof(values) / sizeof(values[0]);


    cout << "Data sebelum diurutkan:" << endl;

    for (int i = 0; i < n; i++)

    {

        cout << values[i] << " ";

    }


    quick_sort(values, 0, n - 1);


    cout << "\nData yang sudah diurutkan:" << endl;

    for (int i = 0; i < n; i++)

    {

        cout << values[i] << " ";

    }


    return 0;

}
