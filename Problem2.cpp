#include <iostream>
using namespace std;

const int MAX = 100;

int hitungPanjang(char teks[]) {
    int panjang = 0;
    while (teks[panjang] != '\0') {
        panjang++;
    }
    return panjang;
}

// Mengubah huruf kapital menjadi nilai posisinya (A=1, B=2, ..., Z=26)
int nilaiHuruf(char c) {
    return (c - 'A') + 1;
}

// Mengubah nilai posisi (1..26) kembali menjadi huruf kapital
char hurufDariNilai(int nilai) {
    return 'A' + (nilai - 1);
}

int main() {
    char pesan[MAX];

    cout << "Masukkan pesan (huruf kapital, tanpa spasi): ";
    cin >> pesan;

    int panjang = hitungPanjang(pesan);

    int nilaiAsli[MAX];
    for (int i = 0; i < panjang; i++) {
        nilaiAsli[i] = nilaiHuruf(pesan[i]);
    }

    char hasil[MAX];
    hasil[0] = pesan[0]; // huruf pertama tidak mengalami perubahan

    for (int i = 1; i < panjang; i++) {
        int jumlah = nilaiAsli[i] + nilaiAsli[i - 1];
        int nilaiBaru = ((jumlah - 1) % 26) + 1;
        hasil[i] = hurufDariNilai(nilaiBaru);
    }
    hasil[panjang] = '\0';

    cout << "\nPesan asli    : " << pesan << endl;
    cout << "Pesan tersandi: " << hasil << endl;

    return 0;
}