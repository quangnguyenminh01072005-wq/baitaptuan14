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
// cau hinh do thi
void taoDoThi(Graph &soDo, int soLuongDinh)
{
    soDo.totalNodes = soLuongDinh;

    for(int i = 0; i < soLuongDinh; i++)
        for(int j = 0; j < soLuongDinh; j++)
            soDo.matrix[i][j] = 0;
}
// Ham noi tuyen duong
void noiTuyenDuong(Graph &soDo, int tinhA, int tinhB, int khoangCach)
{
    soDo.matrix[tinhA][tinhB] = khoangCach;
    soDo.matrix[tinhB][tinhA] = khoangCach;
}
// Ham hien thi
void hienThiBang(int bangSo[MAX_NODES][MAX_NODES], int kichThuoc)
{
    cout << setw(15) << "";

    for(int i = 0; i < kichThuoc; i++)
        cout << setw(12) << danhSachTinh[i];

    cout << endl;

    for(int i = 0; i < kichThuoc; i++)
    {
        cout << setw(15) << danhSachTinh[i];

        for(int j = 0; j < kichThuoc; j++)
            cout << setw(12) << bangSo[i][j];

        cout << endl;
    }
}
// Thuật toán Warshall kiểm tra khả năng thông suốt giữa các tỉnh
void chayWarshall(Graph soDo, int ketQuaLienThong[MAX_NODES][MAX_NODES])
{
    int total = soDo.totalNodes;

    for(int i = 0; i < total; i++)
    {
        for(int j = 0; j < total; j++)
        {
            if(i == j)
                ketQuaLienThong[i][j] = 1;
            else if(soDo.matrix[i][j] != 0)
                ketQuaLienThong[i][j] = 1;
            else
                ketQuaLienThong[i][j] = 0;
        }
    }

    for(int k = 0; k < total; k++)
    {
        for(int i = 0; i < total; i++)
        {
            for(int j = 0; j < total; j++)
            {
                if(ketQuaLienThong[i][j] == 0)
                    ketQuaLienThong[i][j] = ketQuaLienThong[i][k] && ketQuaLienThong[k][j];
            }
        }
    }
}

int main()
{
    return 0;
}
