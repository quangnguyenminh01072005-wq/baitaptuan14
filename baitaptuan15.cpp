#include <iostream>
#include <string>
#include <iomanip>
#include <queue>

using namespace std;
const int MAX_NODES = 11;
const int INF = 1000000;

// Cấu hình cặp dữ liệu: trọng số, đỉnh đến
typedef pair<int, int> NodePair;
string danhSachTinh[MAX_NODES] =
{
    "Ha Noi",
    "Thai Nguyen",
    "Bac Ninh",
    "Bac Giang",
    "Uong Bi",
    "Hai Phong",
    "Hai Duong",
    "Hung Yen",
    "Phu Ly",
    "Hoa Binh",
    "Son Tay"
};
struct Graph
{
    int totalNodes;
    int matrix[MAX_NODES][MAX_NODES];
};

int main()
{
    return 0;
}
