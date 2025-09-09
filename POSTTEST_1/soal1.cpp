//Soal 1: Buat program untuk menyimpan 7 data integer dalam array. GANJIL: Isi dengan kelipatan 3!

#include <iostream>
using namespace std;

void balikArray(int *arr, int n) {
    int *awal = arr;
    int *akhir = arr + n - 1;
    while (awal < akhir) {
        int temp = *awal;
        *awal = *akhir;
        *akhir = temp;
        awal++;
        akhir--;
    }
}

int main() {
    const int N = 7;
    int arr[N];

    for (int i = 0; i < N; i++) {
        arr[i] = (i + 1) * 3;
    }

    cout << "Array sebelum dibalik: ";
    for (int i = 0; i < N; i++) cout << arr[i] << " ";
    cout << endl;

    balikArray(arr, N);

    cout << "Array sesudah dibalik: ";
    for (int i = 0; i < N; i++) cout << arr[i] << " ";
    cout << endl;

    return 0;
}