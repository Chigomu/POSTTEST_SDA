#include <iostream>
#include <string>
using namespace std;

struct Item {
    string namaItem;
    int jumlah;
    string tipe;
    Item* next;
};

Item* head = nullptr;
string namaUser, nimUser;
const int JUMLAH_AWAL = 33;   // dua digit terakhir NIM 033
const int POSISI_SISIP = 4;   // digit terakhir 3 -> 3 + 1 = 4

Item* createItem(string namaItem, string tipe) {
    Item* newNode = new Item();
    newNode->namaItem = namaItem;
    newNode->jumlah = JUMLAH_AWAL;
    newNode->tipe = tipe;
    newNode->next = nullptr;
    return newNode;
}

void tambahItem(string namaItem, string tipe) {
    Item* newNode = createItem(namaItem, tipe);
    if (head == nullptr) {
        head = newNode;
    } else {
        Item* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    cout << "Item \"" << namaItem << "\" berhasil ditambahkan dengan jumlah " << JUMLAH_AWAL << ".\n";
}

void sisipItem(string namaItem, string tipe) {
    Item* newNode = createItem(namaItem, tipe);
    if (head == nullptr || POSISI_SISIP == 1) {
        newNode->next = head;
        head = newNode;
        return;
    }

    Item* temp = head;
    int count = 1;
    while (temp != nullptr && count < POSISI_SISIP - 1) {
        temp = temp->next;
        count++;
    }

    if (temp == nullptr) {
        cout << "Posisi sisip melebihi panjang inventory. Item ditambahkan di akhir.\n";
        tambahItem(namaItem, tipe);
    } else {
        newNode->next = temp->next;
        temp->next = newNode;
        cout << "Item \"" << namaItem << "\" berhasil disisipkan pada posisi " << POSISI_SISIP << ".\n";
    }
}

void hapusItemTerakhir() {
    if (head == nullptr) {
        cout << "Inventory kosong.\n";
        return;
    }
    if (head->next == nullptr) {
        cout << "Item \"" << head->namaItem << "\" dihapus.\n";
        delete head;
        head = nullptr;
        return;
    }

    Item* temp = head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }
    cout << "Item \"" << temp->next->namaItem << "\" dihapus.\n";
    delete temp->next;
    temp->next = nullptr;
}

void gunakanItem(string namaItem) {
    if (head == nullptr) {
        cout << "Inventory kosong.\n";
        return;
    }

    Item* temp = head;
    Item* prev = nullptr;
    while (temp != nullptr && temp->namaItem != namaItem) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Item \"" << namaItem << "\" tidak ditemukan.\n";
        return;
    }

    temp->jumlah--;
    cout << "Item \"" << namaItem << "\" digunakan. Sisa: " << temp->jumlah << "\n";

    if (temp->jumlah <= 0) {
        cout << "Item \"" << namaItem << "\" habis dan dihapus dari inventory.\n";
        if (prev == nullptr) {
            head = temp->next;
        } else {
            prev->next = temp->next;
        }
        delete temp;
    }
}

void tampilkanInventory() {
    if (head == nullptr) {
        cout << "Inventory kosong.\n";
        return;
    }
    cout << "\n=== INVENTORY SAAT INI ===\n";
    Item* temp = head;
    int i = 1;
    while (temp != nullptr) {
        cout << i++ << ". " << temp->namaItem 
             << " | Jumlah: " << temp->jumlah 
             << " | Tipe: " << temp->tipe << "\n";
        temp = temp->next;
    }
    cout << "==========================\n";
}

int main() {
    cout << "Masukkan Nama: ";
    getline(cin, namaUser);
    cout << "Masukkan NIM: ";
    getline(cin, nimUser);

    int pilihan;
    do {
        cout << "\n======================================================================\n";
        cout << "                   🎮 GAME INVENTORY MANAGEMENT 🎮                    \n";
        cout << "----------------------------------------------------------------------\n";
        cout << "   Player : " << namaUser << " \n";
        cout << "   NIM    : " << nimUser   << " \n";
        cout << "======================================================================\n";
        cout << "   [1] ➤ Tambah Item Baru\n";
        cout << "   [2] ➤ Sisipkan Item\n";
        cout << "   [3] ➤ Hapus Item Terakhir\n";
        cout << "   [4] ➤ Gunakan Item\n";
        cout << "   [5] ➤ Tampilkan Inventory\n";
        cout << "   [0] ➤ Keluar\n";
        cout << "======================================================================\n";
        cout << "   Pilihan Anda: ";
        cin >> pilihan;
        cin.ignore();

        string namaItem, tipe;
        switch (pilihan) {
            case 1:
                cout << "Masukkan Nama Item: ";
                getline(cin, namaItem);
                cout << "Masukkan Tipe Item: ";
                getline(cin, tipe);
                tambahItem(namaItem, tipe);
                break;
            case 2:
                cout << "Masukkan Nama Item: ";
                getline(cin, namaItem);
                cout << "Masukkan Tipe Item: ";
                getline(cin, tipe);
                sisipItem(namaItem, tipe);
                break;
            case 3:
                hapusItemTerakhir();
                break;
            case 4:
                cout << "Masukkan Nama Item yang ingin digunakan: ";
                getline(cin, namaItem);
                gunakanItem(namaItem);
                break;
            case 5:
                tampilkanInventory();
                break;
            case 0:
                cout << "Sampai jumpa!\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 0);

    return 0;
}
