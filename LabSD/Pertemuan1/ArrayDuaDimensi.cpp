#include <iostream>                                      // contoh dari 2 dimensi  1 dimensi index 1 baris
                                                                                // 2 dimensi index 1 table
                                                                                // 3 dimensi = int angka [2][3][4]
using namespace std;

int main(){
    int nilai[3][4] = {                                   // 3 mahasiswa 4 itu nilai yg mereka yang ulang ujian nya
        {80, 75, 90, 85},
        {70, 60, 88, 77}, 
        {95, 85, 92, 89}
    };

    for (int i = 0; i < 3; i++) {                        // i untuk baris 
        cout << "Mahasiswa" << i + 1 << " : ";

        for(int j = 0; j < 4; j++) {                     // j untuk kolom 
            cout << nilai[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
} 
 1 index
 2 index
3 dimensi