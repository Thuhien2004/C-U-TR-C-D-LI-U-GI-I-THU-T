#include <iostream>
using namespace std;

// Định nghĩa cấu trúc của một nút trong cây nhị phân
struct Node {
    char value;   // Giá trị là ký tự (toán tử hoặc toán hạng)
    Node* left;   // Con trỏ đến nút con trái
    Node* right;  // Con trỏ đến nút con phải

    // Hàm khởi tạo nút
    Node(char val) : value(val), left(nullptr), right(nullptr) {}
};

// Hàm duyệt hậu tự (post-order) để in biểu thức hậu tố
void printPostfix(Node* root) {
    if (root == nullptr) return;

    // Duyệt trái
    printPostfix(root->left);

    // Duyệt phải
    printPostfix(root->right);

    // Duyệt gốc
    cout << root->value << " ";
}

// Hàm tạo cây nhị phân biểu diễn biểu thức a*(b+c)/(d*e)
Node* createExpressionTree() {
    // Tạo các nút lá
    Node* a = new Node('a');
    Node* b = new Node('b');
    Node* c = new Node('c');
    Node* d = new Node('d');
    Node* e = new Node('e');

    // Tạo các toán tử
    Node* plus = new Node('+');  // b + c
    plus->left = b;
    plus->right = c;

    Node* mul1 = new Node('*');  // a * (b + c)
    mul1->left = a;
    mul1->right = plus;

    Node* mul2 = new Node('*');  // d * e
    mul2->left = d;
    mul2->right = e;

    Node* div = new Node('/');   // (a * (b + c)) / (d * e)
    div->left = mul1;
    div->right = mul2;

    // Trả về gốc của cây (phép chia)
    return div;
}

int main() {
    // Tạo cây nhị phân biểu diễn biểu thức
    Node* root = createExpressionTree();

    // In biểu thức dưới dạng hậu tố
    cout << "Bieu thuc hau to: ";
    printPostfix(root);
    cout << endl;

    return 0;
}
