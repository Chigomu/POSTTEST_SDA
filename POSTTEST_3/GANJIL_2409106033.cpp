#include <iostream>
#include <string>
using namespace std;

struct Item {
    string namaItem;
    int jumlah;
    string tipe;
    Item* next;
    Item* prev;
};

Item* head = nullptr;
Item* tail = nullptr;

string namaUser, nimUser;
const int JUMLAH_AWAL = 33;   // dua digit terakhir NIM 033
const int POSISI_SISIP = 4;   // digit terakhir 3 -> 3 + 1 = 4

// Buat node baru
Item* createItem(string namaItem, string tipe) {
    Item* newNode = new Item();
    newNode->namaItem = namaItem;
    newNode->jumlah = JUMLAH_AWAL;
    newNode->tipe = tipe;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    return newNode;
}

// Tambah item di akhir
void tambahItem(string namaItem, string tipe) {
    Item* newNode = createItem(namaItem, tipe);
    if (head == nullptr) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    cout << "Item \"" << namaItem << "\" berhasil ditambahkan.\n";
}

// Penyisipan item sesuai NIM
void sisipItem(string namaItem, string tipe) {
    Item* newNode = createItem(namaItem, tipe);
    if (head == nullptr) {
        head = tail = newNode;
        return;
    }

    if (POSISI_SISIP == 1) {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        return;
    }

    Item* temp = head;
    int count = 1;
    while (temp != nullptr && count < POSISI_SISIP - 1) {
        temp = temp->next;
        count++;
    }

    if (temp == nullptr || temp->next == nullptr) {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    } else {
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
        temp->next = newNode;
    }

    cout << "Item \"" << namaItem << "\" berhasil disisipkan pada posisi " << POSISI_SISIP << ".\n";
}

// Hapus item terakhir
void hapusItemTerakhir() {
    if (tail == nullptr) {
        cout << "Inventory kosong.\n";
        return;
    }
    cout << "Item \"" << tail->namaItem << "\" dihapus.\n";
    Item* temp = tail;
    if (head == tail) {
        head = tail = nullptr;
    } else {
        tail = tail->prev;
        tail->next = nullptr;
    }
    delete temp;
}

// Gunakan item (jumlah--, hapus jika habis)
void gunakanItem(string namaItem) {
    Item* temp = head;
    while (temp != nullptr && temp->namaItem != namaItem) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Item \"" << namaItem << "\" tidak ditemukan.\n";
        return;
    }

    temp->jumlah--;
    cout << "Item \"" << namaItem << "\" digunakan. Sisa: " << temp->jumlah << "\n";

    if (temp->jumlah <= 0) {
        cout << "Item \"" << namaItem << "\" habis dan dihapus.\n";
        if (temp == head && temp == tail) {
            head = tail = nullptr;
        } else if (temp == head) {
            head = head->next;
            head->prev = nullptr;
        } else if (temp == tail) {
            tail = tail->prev;
            tail->next = nullptr;
        } else {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
        }
        delete temp;
    }
}

// Traversal dari depan
void tampilkanInventory() {
    if (head == nullptr) {
        cout << "Inventory kosong.\n";
        return;
    }
    cout << "\n=== INVENTORY (Depan -> Belakang) ===\n";
    Item* temp = head;
    int i = 1;
    while (temp != nullptr) {
        cout << i++ << ". " << temp->namaItem 
             << " | Jumlah: " << temp->jumlah 
             << " | Tipe: " << temp->tipe << "\n";
        temp = temp->next;
    }
}

// Traversal dari belakang
void tampilkanInventoryBelakang() {
    if (tail == nullptr) {
        cout << "Inventory kosong.\n";
        return;
    }
    cout << "\n=== INVENTORY (Belakang -> Depan) ===\n";
    Item* temp = tail;
    int i = 1;
    while (temp != nullptr) {
        cout << i++ << ". " << temp->namaItem 
             << " | Jumlah: " << temp->jumlah 
             << " | Tipe: " << temp->tipe << "\n";
        temp = temp->prev;
    }
}

// Detail data berdasarkan ID (nomor urut)
void tampilkanDetail(int id) {
    if (head == nullptr) {
        cout << "Inventory kosong.\n";
        return;
    }
    Item* temp = head;
    int i = 1;
    while (temp != nullptr && i < id) {
        temp = temp->next;
        i++;
    }
    if (temp == nullptr) {
        cout << "ID tidak ditemukan.\n";
    } else {
        cout << "\n=== DETAIL ITEM ID " << id << " ===\n";
        cout << "Nama Item : " << temp->namaItem << "\n";
        cout << "Jumlah    : " << temp->jumlah << "\n";
        cout << "Tipe      : " << temp->tipe << "\n";
        cout << "===============================\n";
    }
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
        cout << "   [5] ➤ Tampilkan Inventory (Depan -> Belakang)\n";
        cout << "   [6] ➤ Tampilkan Inventory (Belakang -> Depan)\n";
        cout << "   [7] ➤ Tampilkan Detail Item (berdasarkan ID)\n";
        cout << "   [0] ➤ Keluar\n";
        cout << "======================================================================\n";
        cout << "   Pilihan Anda: ";
        cin >> pilihan;
        cin.ignore();

        string namaItem, tipe;
        int id;
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
            case 6:
                tampilkanInventoryBelakang();
                break;
            case 7:
                cout << "Masukkan ID Item: ";
                cin >> id;
                cin.ignore();
                tampilkanDetail(id);
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
