//Soal 4: Buat fungsi untuk menukar dua variabel integer. GANJIL: Gunakan double pointer (int **) dalam fungsi untuk melakukan pertukaran nilai.

#include <iostream>
using namespace std;

void tukar(int **a, int **b) {
    int temp = **a;
    **a = **b;
    **b = temp;
}

int main() {
    int x, y;
    cout << "Masukkan nilai x: ";
    cin >> x;
    cout << "Masukkan nilai y: ";
    cin >> y;

    cout << "\nSebelum ditukar: x = " << x << ", y = " << y << endl;

    int *px = &x;
    int *py = &y;
    tukar(&px, &py);

    cout << "Sesudah ditukar: x = " << x << ", y = " << y << endl;

    return 0;
}