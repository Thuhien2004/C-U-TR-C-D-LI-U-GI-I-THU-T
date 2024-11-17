#include <iostream>

using namespace std;

void Hanoi(int n, char from, char to, char aux) {
    if (n == 1) {
        cout << "Di chuyen dia " << n << " tu coc " << from << " sang coc " << to << endl;
    } else {
        Hanoi(n - 1, from, aux, to);
        cout << "Di chuyen dia " << n << " tu coc " << from << " sang coc" << to << endl;
        Hanoi(n - 1, aux, to, from);
    }
}

int main() {
    int n;
    cout << "Nhap so dia: ";
    cin >> n;

    Hanoi(n, 'A', 'C', 'B');

    return 0;
}