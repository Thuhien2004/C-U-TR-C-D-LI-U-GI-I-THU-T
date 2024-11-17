#include <iostream>
using namespace std;

// Hàm sắp xếp nổi bọt (Bubble Sort)
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Hoán đổi hai phần tử
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Hàm tìm kiếm tuần tự
int linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target)
            return i; // Trả về vị trí nếu tìm thấy
    }
    return -1; // Không tìm thấy
}

int main() {
    int arr[] = {7, 2, 5, 1, 9, 5}; // Mảng ban đầu
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 5;

    // Sắp xếp mảng
    bubbleSort(arr, n);

    // In mảng sau khi sắp xếp
    cout << "mang sau khi sap xep: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Tìm kiếm phần tử 5
    int result = linearSearch(arr, n, target);
    if (result != -1)
        cout << "phan tu " << target << " duoc tim thay tai vi tri: " << result << endl;
    else
        cout << "Phan tu khong ton tai trong mang" << endl;

    return 0;
}
