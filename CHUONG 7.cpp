#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Cấu trúc lưu thông tin cạnh
struct Edge {
    int u, v, weight;
    Edge(int _u, int _v, int _weight) : u(_u), v(_v), weight(_weight) {}
};

// So sánh hai cạnh theo trọng số
bool compare(Edge a, Edge b) {
    return a.weight < b.weight;
}

// DSU - Disjoint Set Union (Union-Find)
struct DSU {
    vector<int> parent, rank;

    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    bool unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] < rank[rootY])
                swap(rootX, rootY);
            parent[rootY] = rootX;
            if (rank[rootX] == rank[rootY])
                rank[rootX]++;
            return true;
        }
        return false;
    }
};

int main() {
    // Số đỉnh và danh sách các cạnh
    int V = 5;
    vector<Edge> edges = {
        Edge(1, 2, 12), Edge(1, 5, 9), Edge(1, 4, 7),
        Edge(2, 4, 17), Edge(2, 3, 20), Edge(2, 5, 5),
        Edge(3, 4, 25), Edge(4, 5, 40)
    };

    // Sắp xếp các cạnh theo trọng số tăng dần
    sort(edges.begin(), edges.end(), compare);

    DSU dsu(V + 1); // Khởi tạo DSU với V đỉnh
    vector<Edge> mst; // Danh sách cạnh trong cây khung cực tiểu
    int totalWeight = 0;

    // Duyệt qua các cạnh theo thứ tự trọng số tăng dần
    for (Edge e : edges) {
        if (dsu.unite(e.u, e.v)) {
            mst.push_back(e);
            totalWeight += e.weight;
            if (mst.size() == V - 1)
                break;
        }
    }

    // In ra cây khung cực tiểu và tổng trọng số
    cout << "Cac canh trong cay khung cuc tieu:" << endl;
    for (Edge e : mst) {
        cout << e.u << " - " << e.v << " : " << e.weight << endl;
    }
    cout << "Tong trong so cay khung cuc tieu: " << totalWeight << endl;

    return 0;
}
