#include <iostream>
using namespace std;

// Định nghĩa cấu trúc Node
struct Node {
    int info;
    Node* next;

    Node(int value) { // Constructor
        info = value;
        next = nullptr;
    }
};

// Hàm thêm nút vào cuối danh sách
void addToTail(Node*& head, int value) {
    Node* newNode = new Node(value);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Hàm tách danh sách thành EvenList và OddList
void splitList(Node* L, Node*& EvenList, Node*& OddList) {
    while (L != nullptr) {
        if (L->info % 2 == 0) { // Giá trị chẵn
            addToTail(EvenList, L->info);
        } else { // Giá trị lẻ
            addToTail(OddList, L->info);
        }
        L = L->next; // Di chuyển sang nút tiếp theo
    }
}

// Hàm in danh sách
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->info << " ";
        head = head->next;
    }
    cout << endl;
}

// Hàm chính
int main() {
    Node* L = nullptr;       // Danh sách gốc
    Node* EvenList = nullptr; // Danh sách chẵn
    Node* OddList = nullptr;  // Danh sách lẻ

    // Thêm các phần tử vào danh sách gốc
    addToTail(L, 1);
    addToTail(L, 2);
    addToTail(L, 3);
    addToTail(L, 4);
    addToTail(L, 5);

    cout << "Danh sach goc: ";
    printList(L);

    // Tách danh sách
    splitList(L, EvenList, OddList);

    cout << "Danh sach so chan: ";
    printList(EvenList);

    cout << "Danh sach so le: ";
    printList(OddList);

    return 0;
}
