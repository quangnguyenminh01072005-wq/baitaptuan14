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

//================= THÊM CUỐI =================
void themCuoi(Node* &head, SinhVien x){
    Node* p = taoNode(x);
    if(head == NULL){
        head = p;
        return;
    }
    Node* q = head;
    while(q->next)
        q = q->next;
    q->next = p;
}

//================= THÊM THEO THỨ TỰ MÃ =================
void themTheoThuTu(Node* &head, SinhVien x){
    Node* p = taoNode(x);
    if(head == NULL || strcmp(x.ma, head->data.ma) < 0){
        p->next = head;
        head = p;
        return;
    }
    Node* q = head;
    while(q->next && strcmp(q->next->data.ma, x.ma) < 0)
        q = q->next;
    p->next = q->next;
    q->next = p;
}

int main()
{
    return 0;
}
