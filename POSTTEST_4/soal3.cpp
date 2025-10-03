#include <iostream>
#include <string>
using namespace std;

struct Node {
    string document;
    Node* next;
};

// Enqueue: Menambahkan data ke dalam Queue
void enqueue(Node*& front, Node*& rear, string document) {
    Node* newNode = new Node{document, nullptr};

    // Jika antrian kosong, node baru menjadi front dan rear.
    if (front == nullptr) {
        front = newNode;
        rear = newNode;
    } else {
        // Jika tidak, sambungkan ke belakang dan update rear.
        rear->next = newNode;
        rear = newNode;
    }
}

// Dequeue: Menegeluarkan dan Menghapus data paling duluan yang dimasukkan ke dalam queue
string dequeue(Node*& front, Node*& rear) {
    if (front == nullptr) return "Error: Antrian kosong";

    // Simpan node depan dan datanya.
    Node* temp = front;
    string documentData = temp->document;

    // Geser front ke node berikutnya.
    front = front->next;

    // Jika antrian jadi kosong, rear juga harus null.
    if (front == nullptr) {
        rear = nullptr;
    }

    // Hapus node lama dan kembalikan datanya.
    delete temp;
    return documentData;
}

void processAllDocuments(Node*& front, Node*& rear) {
    cout << "Memulai pemrosesan antrian printer:" << endl;
    // Loop selama antrian tidak kosong.
    while (front != nullptr) {
        // Ambil (dequeue) dan cetak dokumen dari depan.
        cout << "Memproses: " << dequeue(front, rear) << endl;
    }
}

int main() {
    Node* front = nullptr;
    Node* rear = nullptr;

    enqueue(front, rear, "Document1.pdf");
    enqueue(front, rear, "Report.docx");
    enqueue(front, rear, "Presentation.pptx");

    processAllDocuments(front, rear);

    return 0;
}