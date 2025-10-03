#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

void exchangeHeadAndTail(Node *&head_ref) {
    if (head_ref == nullptr || head_ref->next == head_ref) {
        return;
    }
    
    // Jika hanya 2 node, cukup geser head pointernya.
    if (head_ref->next->next == head_ref) {
        head_ref = head_ref->next;
        return;
    }
    
    // Simpan pointer ke head, tail, dan tetangga dalamnya.
    Node* old_head = head_ref;
    Node* old_tail = head_ref->prev;
    Node* head_next = old_head->next;
    Node* tail_prev = old_tail->prev;

    // Sambungkan para tetangga (node 2 dan 4) ke partner barunya.
    tail_prev->next = old_head; 
    head_next->prev = old_tail;

    // Sambungkan head & tail lama ke tetangga barunya.
    old_head->prev = tail_prev;
    old_tail->next = head_next;

    // Tutup kembali lingkaran dengan menghubungkan head & tail baru satu sama lain.
    old_head->next = old_tail;
    old_tail->prev = old_head;

    // Jadikan old_tail sebagai head yang baru.
    head_ref = old_tail;
}

void printList(Node *head_ref) {
    if (head_ref == nullptr) { cout << "List kosong" << endl; return; }
    Node *current = head_ref;
    do {
        cout << current->data << " ";
        current = current->next;
    } while (current != head_ref);
    cout << endl;
}

void insertEnd(Node *&head_ref, int data) {
    Node *newNode = new Node{data, nullptr, nullptr};
    if (head_ref == nullptr) {
        newNode->next = newNode;
        newNode->prev = newNode;
        head_ref = newNode;
        return;
    }
    Node *tail = head_ref->prev;
    newNode->next = head_ref;
    newNode->prev = tail;
    head_ref->prev = newNode;
    tail->next = newNode;
}

int main() {
    Node *head = nullptr;
    insertEnd(head, 1);
    insertEnd(head, 2);
    insertEnd(head, 3);
    insertEnd(head, 4);
    insertEnd(head, 5);

    cout << "List sebelum exchange: ";
    printList(head);

    exchangeHeadAndTail(head);

    cout << "List setelah exchange head dan tail: ";
    printList(head);

    return 0;
}