#include <iostream>

using namespace std;

int main() {
    int a, b, tong, hieu, tich, thuong;

    cout << "Nhap so nguyen a: ";
    cin >> a;

    cout << "Nhap so nguyen b: ";
    cin >> b;

    tong = a + b;
    hieu = a - b;
    tich = a * b;

    if (b != 0) {
        thuong = float (a )/ b;
        cout << "Thuong cua hai so la: " << thuong << endl;
    } else {
        cout << "Khong the chia cho 0" << endl;
    }

    cout << "Tong cua hai so la: " << tong << endl;
    cout << "Hieu cua hai so la: " << hieu << endl;
    cout << "Tich cua hai so la: " << tich << endl;

    return 0;
}