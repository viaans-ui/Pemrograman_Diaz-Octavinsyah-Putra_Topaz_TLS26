#include <iostream>
using namespace std;

const int MAXN = 1000;
int hidup[MAXN];     // 1 = masih hidup, 0 = sudah dieliminasi
int totalAstronot;   //Total Astronot (N)

int Survivor(int Jum) {
    int next = (Jum + 1) % totalAstronot;
    while (hidup[next] == 0) {
        next = (next + 1) % totalAstronot;
    }
    return next;
}

int main() {
    int n, k;

    cout << "Masukkan jumlah astronot (N): ";
    cin >> n;
    cout << "Masukkan nilai K awal      : ";
    cin >> k;

    totalAstronot = n;
    for (int i = 0; i < n; i++) {
        hidup[i] = 1; // semua astronot hidup
    }

    int Sisa = n;
    int Index = 0; // index 0 -> astronot nomor 1

    cout << "\nUrutan astronot yang dieliminasi: ";

    while (Sisa > 1) {
        int elim = k - 1;
        for (int s = 0; s < elim; s++) {
            Index = Survivor(Index);
        }

        int terelim = Index + 1; 
        hidup[Index] = 0; Sisa--;
        if (Sisa > 0) {
           cout << terelim;
            cout << ", ";
        }

        // Update nilai K 
        if (terelim % 2 == 0) {
            k = k + 2;
        } else {
            k = k - 1;
        }
        if (k < 2) {
            k = 2;
        }

        if (Sisa > 0) {
            Index = Survivor(Index);
        }
    }

    // Cari astronot yang tersisa (bertahan)
    int survivor = -1;
    for (int i = 0; i < n; i++) {
        if (hidup[i] == 1) {
            survivor = i;
            break;
        }
    }

    cout << "\nAstronot yang bertahan (terakhir): " << (survivor + 1) << endl;

    return 0;
}