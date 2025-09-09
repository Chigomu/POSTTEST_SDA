//Soal 2: Buat program untuk menyimpan matriks 3x3. GANJIL: Hitung jumlah diagonal utama + diagonal sekunder!

#include <iostream>
using namespace std;

int main() {
    const int N = 3;
    int matriks[N][N];

    cout << "Masukkan elemen matriks 3x3:" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << "Elemen [" << i << "][" << j << "]: ";
            cin >> matriks[i][j];
        }
    }

    int jumlahDiagonal = 0;
    for (int i = 0; i < N; i++) {
        jumlahDiagonal += matriks[i][i];              // diagonal utama
        jumlahDiagonal += matriks[i][N - 1 - i];      // diagonal sekunder
    }

    //Kalau jumlah elemen tengah dihitung dua kali, kurangi sekali
    if (N % 2 == 1) {
        jumlahDiagonal -= matriks[N/2][N/2];
    }

    //output matriks
    cout << "\nMatriks 3x3:" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << matriks[i][j] << "\t";
        }
        cout << endl;
    }

    cout << "\nJumlah diagonal utama + diagonal sekunder = " 
         << jumlahDiagonal << endl;

    return 0;
}