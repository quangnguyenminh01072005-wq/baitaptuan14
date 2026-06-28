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

int main()
{
    return 0;
}
