#include <iostream>
#include <algorithm>
using namespace std;
void inMang(int arr[], int n) {
    cout << "[ ";
    for (int i = 0; i < n; i++) {
        cout << arr[i];
        if (i < n - 1) cout << ", ";
    }
    cout << " ]\n";
}
void vunDong(int arr[], int n, int i) {
    int Cha = i;
    int conTrai = 2 * i + 1;
    int conPhai = 2 * i + 2;
    if (conTrai < n && arr[conTrai] > arr[Cha]) {
        Cha = conTrai;
    }
    if (conPhai < n && arr[conPhai] > arr[Cha]) {
        Cha = conPhai;
    }
    if (Cha != i) {
        swap(arr[i], arr[Cha]);
        vunDong(arr, n, Cha);
    }
}

int main()
{
    return 0;
}
