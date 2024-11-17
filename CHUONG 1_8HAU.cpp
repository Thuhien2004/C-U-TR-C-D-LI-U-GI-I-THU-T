#include <iostream>
#include <vector>
using namespace std;

#define N 8 // Kích thước bàn cờ 8x8

// Kiểm tra xem có an toàn để đặt quân hậu tại (row, col) không
bool isSafe(vector<vector<int>> &board, int row, int col) {
    // Kiểm tra cột
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1) 
            return false;
    }

    // Kiểm tra đường chéo trái trên
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) 
            return false;
    }

    // Kiểm tra đường chéo phải trên
    for (int i = row, j = col; i >= 0 && j < N; i--, j++) {
        if (board[i][j] == 1) 
            return false;
    }

    return true; // Không bị tấn công
}

// Hàm đệ quy để giải bài toán 8 quân hậu
bool solveNQueens(vector<vector<int>> &board, int row) {
    if (row >= N) {
        return true; // Đã đặt xong tất cả các quân hậu
    }

    for (int col = 0; col < N; col++) {
        if (isSafe(board, row, col)) {
            // Đặt quân hậu tại (row, col)
            board[row][col] = 1;

            // Gọi đệ quy để đặt quân hậu ở hàng tiếp theo
            if (solveNQueens(board, row + 1)) {
                return true;
            }

            // Nếu không tìm được giải pháp, quay lui
            board[row][col] = 0;
        }
    }

    return false; // Không tìm được vị trí hợp lệ
}

// In kết quả
void printBoard(vector<vector<int>> &board) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << (board[i][j] ? "Q " : ". ");
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> board(N, vector<int>(N, 0)); // Khởi tạo bàn cờ 8x8 với giá trị 0

    if (solveNQueens(board, 0)) {
        cout << "Giai phap cho bai toan 8 quan hau:" << endl;
        printBoard(board);
    } else {
        cout << "Khong co giai phap." << endl;
    }

    return 0;
}
