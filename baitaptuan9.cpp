#include <iostream>
#include <cstring>
using namespace std;
struct Ngay{
    int d,m,y;
};
struct SinhVien{
    char ma[10], ten[50];
    Ngay ns;
};
struct Node{
    SinhVien data;
    Node *next;
};

//================= TẠO NODE =================
Node* taoNode(SinhVien x){
    Node* p = new Node;
    p->data = x;
    p->next = NULL;
    return p;
}

//================= NHẬP =================
void nhapSV(SinhVien &x){
    cin.ignore();
    cout<<"Ma: ";
    cin.getline(x.ma,10);
    cout<<"Ten: ";
    cin.getline(x.ten,50);
    cout<<"Ngay sinh: ";
    cin>>x.ns.d>>x.ns.m>>x.ns.y;
}

int main()
{
    return 0;
}
