#include <iostream>
#include <stack>
using namespace std;

void chuyenSangNhiPhan(int so) {
    stack<int> s;

    // Đẩy phần dư vào stack cho đến khi số bằng 0
    while (so > 0) {
        s.push(so % 2); // Lưu phần dư vào stack
        so /= 2;        // Cập nhật số bằng thương của phép chia
    }

    // Pop từng phần tử trong stack để tạo ra chuỗi nhị phân
    cout << "So nhi phan la: ";
    while (!s.empty()) {
        cout << s.top(); // Lấy phần tử trên cùng của stack
        s.pop();         // Xóa phần tử trên cùng sau khi lấy ra
    }
    cout << endl;
}

int main() {
    int so = 39;
    cout << "So thap phan: " << so << endl;
    chuyenSangNhiPhan(so);

    return 0;
}
