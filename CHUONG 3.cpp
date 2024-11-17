#include <iostream>
using namespace std;

int F(int n) {
    // Điều kiện cơ sở
    if (n < 3) {
        return 1;
    }
    // Công thức đệ quy
    return F(n - 1) + F(n - 3);
}

int main() {
    int n;

    // Nhập số nguyên dương n
    cout << "Nhap so nguyen duong n (0 < n <= 10): ";
    cin >> n;

    // Kiểm tra giới hạn của n
    if (n <= 0 || n > 10) {
        cout << "Gia tri n khong hop le. Vui long nhap lai trong khoang (0 < n <= 10)." << endl;
        return 1; // Kết thúc chương trình nếu n không hợp lệ
    }

    // Tính và in kết quả
    cout << "F(" << n << ") = " << F(n) << endl;

    return 0;
}
