#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

void sortedInsert(Node *&head_ref, int data) {
    Node* newNode = new Node{data, nullptr, nullptr};

    // Kasus 1: Jika list masih kosong
    if (head_ref == nullptr) {
        newNode->next = newNode;
        newNode->prev = newNode;
        head_ref = newNode;
        return;
    }

    // Kasus 2: Data baru lebih kecil dari head (sisipkan di awal)
    // Jika data baru lebih kecil dari head, sisipkan di awal.
    if (data < head_ref->data) {
        Node* last = head_ref->prev;
        newNode->next = head_ref;
        head_ref->prev = newNode;
        newNode->prev = last;
        last->next = newNode;
        head_ref = newNode; // Update head_ref menjadi node baru.
        return;
    }
 
    //Kasus 3: Cari posisi di tengah atau akhir.
    Node* current = head_ref;
    while (current->next != head_ref && current->next->data < data) {
        current = current->next;
    }
    // Sisipkan node baru setelah 'current'.
    newNode->next = current->next;
    current->next->prev = newNode;
    current->next = newNode;
    newNode->prev = current;
}

void printList(Node *head_ref)
{
    if (head_ref == nullptr) { cout << "List kosong" << endl; return; }
    Node *current = head_ref;
    do {
        cout << current->data << " ";
        current = current->next;
    } while (current != head_ref);
    cout << endl;
}

int main()
{
    Node *head = nullptr;
    sortedInsert(head, 30);
    sortedInsert(head, 10);
    sortedInsert(head, 40);
    sortedInsert(head, 20);

    cout << "Circular Doubly Linked List (sorted): ";
    printList(head);

    return 0;
}