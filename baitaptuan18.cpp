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

void inKetQuaDijkstra(DoThi g, int dinhDau, int dinhCuoi)
{
    int khoangCach[SO_TINH];
    int vet[SO_TINH];

    chayDijkstra(g, dinhDau, khoangCach, vet);

    cout << "\n\nDIJKSTRA - DUONG DI NGAN NHAT TU " << tenTinh[dinhDau] << "\n";
    cout << setw(15) << "Dinh den" << setw(15) << "Khoang cach" << endl;

    for(int i = 0; i < g.soDinh; i++)
        cout << setw(15) << tenTinh[i] << setw(15) << khoangCach[i] << endl;

    cout << "\nDuong di ngan nhat tu " << tenTinh[dinhDau] << " den " << tenTinh[dinhCuoi] << ": ";

    if(khoangCach[dinhCuoi] == VO_CUC)
        cout << "Khong co duong di";
    else
    {
        inLoTrinh(dinhCuoi, vet);
        cout << "\nTong trong so: " << khoangCach[dinhCuoi];
    }

    cout << endl;
}

void chayPrim(DoThi g, int dinhDau, DoThi &cayKhung, int &tongTrongSo)
{
    bool daChon[SO_TINH];
    int canhNhoNhat[SO_TINH];
    int cha[SO_TINH];

    khoiTaoDoThi(cayKhung, g.soDinh);
    tongTrongSo = 0;

    for(int i = 0; i < g.soDinh; i++)
    {
        daChon[i] = false;
        canhNhoNhat[i] = VO_CUC;
        cha[i] = -1;
    }

    canhNhoNhat[dinhDau] = 0;

    for(int dem = 0; dem < g.soDinh; dem++)
    {
        int u = -1;
        int giaTriNhoNhat = VO_CUC;

        for(int i = 0; i < g.soDinh; i++)
        {
            if(!daChon[i] && canhNhoNhat[i] < giaTriNhoNhat)
            {
                giaTriNhoNhat = canhNhoNhat[i];
                u = i;
            }
        }

        if(u == -1)
            return;

        daChon[u] = true;

        if(cha[u] != -1)
        {
            themTuyenDuong(cayKhung, u, cha[u], g.maTran[u][cha[u]]);
            tongTrongSo += g.maTran[u][cha[u]];
        }

        for(int v = 0; v < g.soDinh; v++)
        {
            if(g.maTran[u][v] != 0 && !daChon[v] && g.maTran[u][v] < canhNhoNhat[v])
            {
                canhNhoNhat[v] = g.maTran[u][v];
                cha[v] = u;
            }
        }
    }
}

void inKetQuaPrim(DoThi g, int dinhDau)
{
    DoThi cayPrim;
    int tongTrongSo;

    chayPrim(g, dinhDau, cayPrim, tongTrongSo);

    inMaTranKe(cayPrim, "CAY KHUNG NHO NHAT - PRIM");
    cout << "\nTong trong so cay Prim: " << tongTrongSo << endl;
}

vector<Canh> layDanhSachCanh(DoThi g)
{
    vector<Canh> danhSach;

    for(int i = 0; i < g.soDinh; i++)
    {
        for(int j = i + 1; j < g.soDinh; j++)
        {
            if(g.maTran[i][j] != 0)
                danhSach.push_back({i, j, g.maTran[i][j]});
        }
    }

    return danhSach;
}

int timGoc(int cha[], int u)
{
    if(cha[u] == u)
        return u;

    cha[u] = timGoc(cha, cha[u]);
    return cha[u];
}

bool hopNhat(int cha[], int bac[], int u, int v)
{
    int gocU = timGoc(cha, u);
    int gocV = timGoc(cha, v);

    if(gocU == gocV)
        return false;

    if(bac[gocU] < bac[gocV])
        cha[gocU] = gocV;
    else if(bac[gocU] > bac[gocV])
        cha[gocV] = gocU;
    else
    {
        cha[gocV] = gocU;
        bac[gocU]++;
    }

    return true;
}

void chayKruskal(DoThi g, DoThi &cayKhung, int &tongTrongSo)
{
    vector<Canh> danhSach = layDanhSachCanh(g);
    int cha[SO_TINH];
    int bac[SO_TINH];
    int soCanhDaChon = 0;

    khoiTaoDoThi(cayKhung, g.soDinh);
    tongTrongSo = 0;

    sort(danhSach.begin(), danhSach.end(), [](Canh a, Canh b)
    {
        return a.trongSo < b.trongSo;
    });

    for(int i = 0; i < g.soDinh; i++)
    {
        cha[i] = i;
        bac[i] = 0;
    }

    for(int i = 0; i < (int)danhSach.size(); i++)
    {
        Canh canh = danhSach[i];

        if(hopNhat(cha, bac, canh.u, canh.v))
        {
            themTuyenDuong(cayKhung, canh.u, canh.v, canh.trongSo);
            tongTrongSo += canh.trongSo;
            soCanhDaChon++;
        }

        if(soCanhDaChon == g.soDinh - 1)
            break;
    }
}

void inKetQuaKruskal(DoThi g)
{
    DoThi cayKruskal;
    int tongTrongSo;

    chayKruskal(g, cayKruskal, tongTrongSo);

    inMaTranKe(cayKruskal, "CAY KHUNG NHO NHAT - KRUSKAL");
    cout << "\nTong trong so cay Kruskal: " << tongTrongSo << endl;
}

int main()
{
    DoThi banDo;
    taoBanDoGiaoThong(banDo);

    inMaTranKe(banDo, "MA TRAN KE DO THI GIAO THONG");
    inKetQuaDijkstra(banDo, 0, 4);
    inKetQuaPrim(banDo, 0);
    inKetQuaKruskal(banDo);

    return 0;
}
