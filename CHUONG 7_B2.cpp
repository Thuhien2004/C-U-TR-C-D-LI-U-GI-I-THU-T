#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// C?u trúc luu thông tin c?nh
struct Canh {
    char dinh1, dinh2; // Hai d?nh c?a c?nh
    int trongSo; // Tr?ng s? c?a c?nh
    Canh(char _dinh1, char _dinh2, int _trongSo) : dinh1(_dinh1), dinh2(_dinh2), trongSo(_trongSo) {}
};

// So sánh hai c?nh theo tr?ng s?
bool soSanh(Canh a, Canh b) {
    return a.trongSo < b.trongSo;
}

// DSU - T?p h?p không giao nhau (Disjoint Set Union)
struct DSU {
    vector<char> cha;

    DSU() {}

    // Kh?i t?o cha cho m?i d?nh
    void khoiTao(char n) {
        cha.resize(n + 1);
        for (char i = 'A'; i <= n; ++i)
            cha[i] = i;
    }

    char tim(char x) {
        if (cha[x] != x)
            cha[x] = tim(cha[x]);
        return cha[x];
    }

    bool hopNhat(char x, char y) {
        char rootX = tim(x);
        char rootY = tim(y);
        if (rootX != rootY) {
            cha[rootY] = rootX; // H?p nh?t
            return true;
        }
        return false;
    }
};

int main() {
    // Danh sách các c?nh
    vector<Canh> danhSachCanh = {
        Canh('A', 'B', 1),
        Canh('B', 'C', 2),
        Canh('A', 'C', 3)
    };

    // S?p x?p các c?nh theo tr?ng s? tang d?n
    sort(danhSachCanh.begin(), danhSachCanh.end(), soSanh);

    DSU dsu; 
    dsu.khoiTao('C'); // Kh?i t?o DSU v?i các d?nh t? A d?n C

    vector<Canh> cayKhung; // Danh sách c?nh trong cây khung c?c ti?u
    int tongTrongSo = 0;

    // Duy?t qua các c?nh theo th? t? tr?ng s? tang d?n
    for (Canh e : danhSachCanh) {
        if (dsu.hopNhat(e.dinh1, e.dinh2)) {
            cayKhung.push_back(e);
            tongTrongSo += e.trongSo;
        }
    }

    // In ra cây khung c?c ti?u và t?ng tr?ng s?
    cout << "cac canh trong cay khung cuc tieu:" << endl;
    for (Canh e : cayKhung) {
        cout << e.dinh1 << " - " << e.dinh2 << " : " << e.trongSo << endl;
    }
    cout << "tong trong so cua cay khung cuc tieu: " << tongTrongSo << endl;

    return 0;
}
