#include <iostream>
#include <string>
using namespace std;

struct Node {
    char data;
    Node* next;
};

// Fungsi Push dari Soal 1
void push(Node*& top, char data) {
    Node* newNode = new Node{data, top};
    top = newNode;
}

// Fungsi Pop dari Soal 1
char pop(Node*& top) {
    if (top == nullptr) return '\0';
    Node* temp = top;
    char poppedValue = temp->data;
    top = top->next;
    delete temp;
    return poppedValue;
}

bool areBracketsBalanced(string expr) {
    Node* stackTop = nullptr;

    for (char karakter : expr) {
        // Jika kurung buka, push ke stack.
        if (karakter == '(' || karakter == '{' || karakter == '[') {
            push(stackTop, karakter);
        }
        // Jika kurung tutup, lakukan pengecekan.
        else if (karakter == ')' || karakter == '}' || karakter == ']') {
            // Jika stack kosong saat ada kurung tutup, tidak seimbang.
            if (stackTop == nullptr) return false;

            // Pop dan cek apakah kurung cocok.
            char topChar = pop(stackTop);
            if ((karakter == ')' && topChar != '(') ||
                (karakter == '}' && topChar != '{') ||
                (karakter == ']' && topChar != '[')) {
                return false;
            }
        }
    }
    // Di akhir, stack harus kosong agar seimbang.
    return stackTop == nullptr;
}
 
int main() {
    string expr1 = "{[()]}";
    cout << expr1 << " -> " << (areBracketsBalanced(expr1) ? "Seimbang" : "Tidak Seimbang") << endl;

    string expr2 = "{[(])}";
    cout << expr2 << " -> " << (areBracketsBalanced(expr2) ? "Seimbang" : "Tidak Seimbang") << endl;

    return 0;
}