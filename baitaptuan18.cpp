#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>
#include <utility>
using namespace std;

const int SO_TINH = 11;
const int VO_CUC = 1000000000;

const string tenTinh[SO_TINH] =
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

struct DoThi
{
    int soDinh;
    int maTran[SO_TINH][SO_TINH];
};

struct Canh
{
    int u;
    int v;
    int trongSo;
};

void khoiTaoDoThi(DoThi &g, int n)
{
    g.soDinh = n;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            g.maTran[i][j] = 0;
}

void themTuyenDuong(DoThi &g, int u, int v, int maDuong)
{
    g.maTran[u][v] = maDuong;
    g.maTran[v][u] = maDuong;
}

int main()
{
    return 0;
}
