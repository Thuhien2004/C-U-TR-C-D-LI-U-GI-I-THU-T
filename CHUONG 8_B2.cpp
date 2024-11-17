#include <iostream>
using namespace std;

void sapXepChen(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        
        // Di chuyển các phần tử lớn hơn key sang phải
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void inMang(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {0, 5, 2, 6, 9, 3, 4, 8, 7, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Mang ban dau: ";
    inMang(arr, n);

    sapXepChen(arr, n);

    cout << "Mang sau khi sap xep: ";
    inMang(arr, n);

    return 0;
}
