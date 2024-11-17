#include <iostream>
using namespace std;

void sapXepNoiBot(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        // Nếu không có hoán đổi nào, dừng vòng lặp
        if (!swapped)
            break;
    }
}

void inMang(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {1, 3, 9, 0, 2, 4, 6, 8, 7, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Mang ban dau: ";
    inMang(arr, n);

    sapXepNoiBot(arr, n);

    cout << "Mang sau khi sap xep: ";
    inMang(arr, n);

    return 0;
}
