#include <iostream>
using namespace std;

#define N 8 // Số đỉnh trong đồ thị

void printAdjacencyMatrix(int adjMatrix[N][N]) {
    cout << "MA TRAN KE DO THI:" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    // Khởi tạo ma trận kề với tất cả giá trị ban đầu là 0
    int adjMatrix[N][N] = {0};

    // Thiết lập các cung theo đồ thị
    adjMatrix[0][1] = 1; // 1 -> 2
    adjMatrix[0][2] = 1; // 1 -> 3
    adjMatrix[0][3] = 1; // 1 -> 4
    adjMatrix[1][4] = 1; // 2 -> 5
    adjMatrix[2][4] = 1; // 3 -> 5
    adjMatrix[3][4] = 1; // 4 -> 5
    adjMatrix[4][5] = 1; // 5 -> 6
    adjMatrix[4][6] = 1; // 5 -> 7
    adjMatrix[4][7] = 1; // 5 -> 8
    adjMatrix[5][7] = 1; // 6 -> 8
    adjMatrix[6][7] = 1; // 7 -> 8

    // In ma trận kề
    printAdjacencyMatrix(adjMatrix);

    return 0;
}
