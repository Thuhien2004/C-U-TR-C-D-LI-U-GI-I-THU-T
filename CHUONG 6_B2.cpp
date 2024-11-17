#include <iostream>
using namespace std;

// Định nghĩa cấu trúc nút của cây nhị phân
struct Node {
    char data;       // Lưu toán tử hoặc toán hạng
    Node* left;      // Con trỏ đến cây con trái
    Node* right;     // Con trỏ đến cây con phải

    Node(char value) { // Constructor
        data = value;
        left = right = nullptr;
    }
};

// Hàm duyệt theo thứ tự trước (Pre-order)
void preOrder(Node* root) {
    if (root == nullptr) return; 
    cout << root->data << " ";   // Thăm nút gốc
    preOrder(root->left);        // Duyệt cây con trái
    preOrder(root->right);       // Duyệt cây con phải
}

// Hàm duyệt theo thứ tự giữa (In-order)
void inOrder(Node* root) {
    if (root == nullptr) return; 
    inOrder(root->left);         // Duyệt cây con trái
    cout << root->data << " ";   // Thăm nút gốc
    inOrder(root->right);        // Duyệt cây con phải
}

// Hàm duyệt theo thứ tự sau (Post-order)
void postOrder(Node* root) {
    if (root == nullptr) return; 
    postOrder(root->left);       // Duyệt cây con trái
    postOrder(root->right);      // Duyệt cây con phải
    cout << root->data << " ";   // Thăm nút gốc
}

// Hàm chính
int main() {
    // Tạo cây nhị phân biểu diễn biểu thức a * (b + c) / (d * e)
    Node* root = new Node('/');               // Gốc là '/'
    root->left = new Node('*');               // Nhánh trái là '*'
    root->right = new Node('*');              // Nhánh phải là '*'

    root->left->left = new Node('a');         // Nhánh trái của '*' là 'a'
    root->left->right = new Node('+');        // Nhánh phải của '*' là '+'
    root->left->right->left = new Node('b');  // Nhánh trái của '+' là 'b'
    root->left->right->right = new Node('c'); // Nhánh phải của '+' là 'c'

    root->right->left = new Node('d');        // Nhánh trái của '*' là 'd'
    root->right->right = new Node('e');       // Nhánh phải của '*' là 'e'

    // Duyệt cây theo thứ tự trước
    cout << "DUYET THEO THU TU TRUOC: ";
    preOrder(root);
    cout << endl;

    // Duyệt cây theo thứ tự giữa
    cout << "DUYET THEO THU TU GIUA: ";
    inOrder(root);
    cout << endl;

    // Duyệt cây theo thứ tự sau
    cout << "DUYET THEO THU TU SAU: ";
    postOrder(root);
    cout << endl;

    return 0;
}
