#include <iostream>
using namespace std;

// Định nghĩa cấu trúc của một nút trong danh sách liên kết
struct Node {
    int info;     // Trường chứa thông tin (giá trị)
    Node* next;   // Con trỏ trỏ đến nút tiếp theo

    // Hàm khởi tạo nút mới
    Node(int value) : info(value), next(nullptr) {}
};

// Thêm một nút mới vào cuối danh sách
void themCuoi(Node*& P, int value) {
    Node* newNode = new Node(value); // Tạo nút mới

    if (P == nullptr) { // Nếu danh sách rỗng
        P = newNode;    // Gán nút mới làm nút đầu tiên
    } else {
        Node* temp = P;
        while (temp->next != nullptr) { // Tìm nút cuối cùng
            temp = temp->next;
        }
        temp->next = newNode; // Thêm nút mới vào cuối danh sách
    }
}

// Xoá một nút có trường info bằng x
void xoaNode(Node*& P, int x) {
    if (P == nullptr) { // Nếu danh sách rỗng
        cout << "Danh sach rong." << endl;
        return;
    }

    // Xử lý trường hợp nút đầu có info bằng x
    if (P->info == x) {
        Node* temp = P;
        P = P->next; // Cập nhật nút đầu danh sách
        delete temp; // Xoá nút đầu
        return;
    }

    // Tìm nút cần xoá
    Node* temp = P;
    while (temp->next != nullptr && temp->next->info != x) {
        temp = temp->next;
    }

    // Nếu tìm thấy nút có info bằng x
    if (temp->next != nullptr) {
        Node* nodeToDelete = temp->next;
        temp->next = nodeToDelete->next; // Bỏ qua nút cần xoá
        delete nodeToDelete; // Xoá nút
    } else {
        cout << "Khong tim thay gia tri " << x << " trong danh sach." << endl;
    }
}

// Hàm in danh sách
void inDanhSach(Node* P) {
    Node* temp = P;
    while (temp != nullptr) {
        cout << temp->info << " -> ";
        temp = temp->next;
    }
    cout << "null" << endl;
}

int main() {
    Node* P = nullptr; // Khởi tạo danh sách rỗng

    // Thêm các nút vào danh sách
    themCuoi(P, 10);
    themCuoi(P, 20);
    themCuoi(P, 30);
    themCuoi(P, 40);

    cout << "Danh sach sau khi them cac phan tu: ";
    inDanhSach(P);

    // Xoá nút có giá trị info = 20
    xoaNode(P, 20);
    cout << "Danh sach sau khi xoa phan tu co gia tri 20: ";
    inDanhSach(P);

    return 0;
}
