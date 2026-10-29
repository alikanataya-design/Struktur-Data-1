#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Masukkan jumlah elemen data: ";
    cin >> n;

    int data[n];
    cout << "Masukkan elemen-elemen data: \n";
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }

    // TODO : Algoritma Bubble Sort dari terkecil hingga terbesar
       for(int i=0; i<n - 1; i++){
        int key = data [i];
        int j= i - 1;

        while(j >= 0 && data [j] > key ){
            data [j + 1] = data[j];
            j--;
        }
        data[j + 1]= key;
       }

    cout << "Data setelah diurutkan dari terkecil hingga terbesar:\n";
    for (int i = 0; i < n; i++) {
        cout << data[i] << " ";
    }
    cout << endl;

    return 0;
}