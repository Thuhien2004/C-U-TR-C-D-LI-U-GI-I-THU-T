#include <iostream>
using namespace std;

int linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target)
            return i; // Trả về vị trí của phần tử nếu tìm thấy
    }
    return -1; // Không tìm thấy
}

int main() {
    int arr[] = {0, 5, 4, 8, 7, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 8;

    int result = linearSearch(arr, n, target);
    if (result != -1)
        cout << "Phan tu " << target << " duoc tim thay tai vi tri: " << result << endl;
    else
        cout << "Phan tu khong ton tai trong mang" << endl;

    return 0;
}
