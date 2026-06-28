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

void taoBanDoGiaoThong(DoThi &g)
{
    khoiTaoDoThi(g, SO_TINH);

    int cacTuyenDuong[][3] =
    {
        {0, 6, 1},   // D1: Ha Noi - Hai Duong
        {6, 7, 2},   // D2: Hai Duong - Hung Yen
        {7, 8, 3},   // D3: Hung Yen - Phu Ly
        {0, 8, 4},   // D4: Ha Noi - Phu Ly
        {0, 9, 5},   // D5: Ha Noi - Hoa Binh
        {0, 10, 6},  // D6: Ha Noi - Son Tay
        {0, 1, 7},   // D7: Ha Noi - Thai Nguyen
        {0, 2, 8},   // D8: Ha Noi - Bac Ninh
        {2, 3, 9},   // D9: Bac Ninh - Bac Giang
        {3, 4, 10},  // D10: Bac Giang - Uong Bi
        {2, 4, 11},  // D11: Bac Ninh - Uong Bi
        {4, 5, 12},  // D12: Uong Bi - Hai Phong
        {6, 5, 13}   // D13: Hai Duong - Hai Phong
    };

    int soTuyen = sizeof(cacTuyenDuong) / sizeof(cacTuyenDuong[0]);

    for(int i = 0; i < soTuyen; i++)
        themTuyenDuong(g, cacTuyenDuong[i][0], cacTuyenDuong[i][1], cacTuyenDuong[i][2]);
}

void inMaTranKe(DoThi g, string tieuDe)
{
    cout << "\n" << tieuDe << "\n";
    cout << setw(15) << "";

    for(int i = 0; i < g.soDinh; i++)
        cout << setw(12) << tenTinh[i];

    cout << endl;

    for(int i = 0; i < g.soDinh; i++)
    {
        cout << setw(15) << tenTinh[i];

        for(int j = 0; j < g.soDinh; j++)
        {
            if(g.maTran[i][j] == 0)
                cout << setw(12) << 0;
            else
                cout << setw(12) << ("D" + to_string(g.maTran[i][j]));
        }

        cout << endl;
    }
}

void chayDijkstra(DoThi g, int dinhDau, int khoangCach[], int vet[])
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> hangDoi;

    for(int i = 0; i < g.soDinh; i++)
    {
        khoangCach[i] = VO_CUC;
        vet[i] = -1;
    }

    khoangCach[dinhDau] = 0;
    hangDoi.push({0, dinhDau});

    while(!hangDoi.empty())
    {
        int chiPhiHienTai = hangDoi.top().first;
        int u = hangDoi.top().second;
        hangDoi.pop();

        if(chiPhiHienTai > khoangCach[u])
            continue;

        for(int v = 0; v < g.soDinh; v++)
        {
            if(g.maTran[u][v] != 0)
            {
                int chiPhiMoi = khoangCach[u] + g.maTran[u][v];

                if(chiPhiMoi < khoangCach[v])
                {
                    khoangCach[v] = chiPhiMoi;
                    vet[v] = u;
                    hangDoi.push({chiPhiMoi, v});
                }
            }
        }
    }
}

void inLoTrinh(int dinh, int vet[])
{
    if(dinh == -1)
        return;

    inLoTrinh(vet[dinh], vet);

    if(vet[dinh] != -1)
        cout << " -> ";

    cout << tenTinh[dinh];
}

int main()
{
    return 0;
}
