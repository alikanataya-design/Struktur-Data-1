#include <iostream>
using namespace std;

int main() {
    int n, key, posisi = -1;

    cout << "Masukkan jumlah data: ";
    cin >> n;

    int data[n];

    cout << "Masukkan elemen data: " << endl;
    for (int i = 0; i < n; i++) {
        cout << "Data ke-" << i << ": ";
        cin >> data[i];
    }

    cout << "\nMasukkan nilai yang ingin dicari: ";
    cin >> key;

    // TODO : Proses pencarian sequential/linear
    for (int i = 0; i < n ; i++){
        if(data[i] == key){
            posisi = i; // simpan posisi ketika ketemu 
            break; // karna data sudah ketemu 
        }
    }

    // Output hasil
    if(posisi != -1)
        cout << "\nData ditemukan di indeks ke-" << posisi << endl;
    else  
        cout << "\ndata Tidak ditemukan" << endl;

    return 0;
    
}

// 1. Desecending : 52 36 30 26 21 12 9
// 2. left = 0 , right =N -1 (7 - 1 = 6)
//3. middle = (0 + 6) /2 = 3 --> [26]
//4 perbandingan :
// - [26] == 30 Nooo
// - 30 < 26 Noooo
// - 30 > 26 Yess , cari di bagian > middle

// iterasi 2
// 1. 52 36 30
// 2. left =0 , right = 2 (3-1)
// 3. middle  = (0 + 2)/ 2= 1 --> [36]
// 4. perbandingan :
// -[36] == 30 noo
// -30 < 36 Yess , cari di bagian < middle

// iterasi
// 1. 30
// 2. left = 0, right = 0
// 3. middle =0 (0+0)/2 = 0 --> [30]
// 4. perbandingan :
// - [30] == 30 Yess --> data di temukan