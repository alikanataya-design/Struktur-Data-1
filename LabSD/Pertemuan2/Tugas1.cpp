#include <iostream>
using namespace std;

// Struktur Node
struct Node {
    int nilai;
    Node* next;
};

// Menampilkan isi linked list
void tampilkan(Node* head) {
    cout << "Linked List: ";

    if (head == nullptr) {
        cout << "Kosong";
    } else {
        Node* bantu = head;
        while (bantu != nullptr) {
            cout << bantu->nilai;
            if (bantu->next != nullptr)
                cout << " -> ";
            bantu = bantu->next;
        }
    }

    cout << endl;
}

// Menambah node di awal
void tambahAwal(Node*& head, int nilai) {
    Node* baru = new Node;
    baru->nilai = nilai;
    baru->next = head;
    head = baru;

    cout << "Node berhasil ditambahkan di awal.\n";
    tampilkan(head);
}

// Menambah node di akhir
void tambahAkhir(Node*& head, int nilai) {
    Node* baru = new Node;
    baru->nilai = nilai;
    baru->next = nullptr;

    if (head == nullptr) {
        head = baru;
    } else {
        Node* bantu = head;

        while (bantu->next != nullptr) {
            bantu = bantu->next;
        }

        bantu->next = baru;
    }

    cout << "Node berhasil ditambahkan di akhir.\n";
    tampilkan(head);
}

// Menambah node setelah nilai tertentu
void tambahSetelah(Node*& head, int target, int nilai) {
    Node* bantu = head;

    while (bantu != nullptr && bantu->nilai != target) {
        bantu = bantu->next;
    }

    if (bantu == nullptr) {
        cout << "Nilai " << target << " tidak ditemukan.\n";
        tampilkan(head);
        return;
    }

    Node* baru = new Node;
    baru->nilai = nilai;
    baru->next = bantu->next;
    bantu->next = baru;

    cout << "Node berhasil ditambahkan setelah nilai "
         << target << ".\n";

    tampilkan(head);
}

// Menghapus node berdasarkan nilai
void hapusNode(Node*& head, int nilai) {
    if (head == nullptr) {
        cout << "Linked List kosong.\n";
        tampilkan(head);
        return;
    }

    // Jika node yang dihapus adalah head
    if (head->nilai == nilai) {
        Node* hapus = head;
        head = head->next;
        delete hapus;

        cout << "Node dengan nilai " << nilai
             << " berhasil dihapus.\n";

        tampilkan(head);
        return;
    }

    Node* bantu = head;

    while (bantu->next != nullptr &&
           bantu->next->nilai != nilai) {
        bantu = bantu->next;
    }

    if (bantu->next == nullptr) {
        cout << "Nilai " << nilai << " tidak ditemukan.\n";
        tampilkan(head);
        return;
    }

    Node* hapus = bantu->next;
    bantu->next = hapus->next;
    delete hapus;

    cout << "Node dengan nilai " << nilai
         << " berhasil dihapus.\n";

    tampilkan(head);
}

// Program utama
int main() {
    Node* head = nullptr;
    int pilihan, nilai, target;

    do {
        cout << "\n SINGLE LINKED LIST \n";
        cout << "1. Tambah Node di Awal\n";
        cout << "2. Tambah Node di Akhir\n";
        cout << "3. Tambah Node Setelah Nilai Tertentu\n";
        cout << "4. Hapus Node Berdasarkan Nilai\n";
        cout << "5. Tampilkan Linked List\n";
        cout << "0. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {

            case 1:
                cout << "Masukkan nilai mahasiswa: ";
                cin >> nilai;
                tambahAwal(head, nilai);
                break;

            case 2:
                cout << "Masukkan nilai mahasiswa: ";
                cin >> nilai;
                tambahAkhir(head, nilai);
                break;

            case 3:
                cout << "Masukkan nilai yang dicari: ";
                cin >> target;

                cout << "Masukkan nilai baru: ";
                cin >> nilai;

                tambahSetelah(head, target, nilai);
                break;

            case 4:
                cout << "Masukkan nilai yang ingin dihapus: ";
                cin >> nilai;

                hapusNode(head, nilai);
                break;

            case 5:
                tampilkan(head);
                break;

            case 0:
                cout << "Program selesai.\n";
                break;

            default:
                cout << "Pilihan tidak valid!\n";
        }

    } while (pilihan != 0);

    // Menghapus seluruh node sebelum program selesai
    while (head != nullptr) {
        Node* hapus = head;
        head = head->next;
        delete hapus;
    }

    return 0;
}