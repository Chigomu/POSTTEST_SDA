#include <iostream>
#include <string>
using namespace std;

struct Node {
    char data;
    Node* next;
};

// Fungsi Push: Menambahkan data ke dalam Stack
void push(Node*& top, char data) {
    Node* newNode = new Node{data, top};
    top = newNode;
}

// Fungsi Pop: Mengeluarkan data terkahir yang ditambahkan oleh Push
char pop(Node*& top) {
    if (top == nullptr) return '\0';
    Node* temp = top;
    char poppedValue = temp->data;
    top = top->next;
    delete temp;
    return poppedValue;
}

string reverseString(string s) {
    Node* stackTop = nullptr;
    string reversed = "";

    // Push semua karakter dari string ke dalam stack.
    for (char karakter : s) {
        push(stackTop, karakter);
    }

    // Pop semua karakter dari stack untuk membalik urutannya.
    while (stackTop != nullptr) {
        reversed += pop(stackTop);
    }

    return reversed;
}
 
int main() {
    string text = "Struktur Data";
    cout << "Teks asli: " << text << endl;
    cout << "Teks terbalik: " << reverseString(text) << endl;
    return 0;
}