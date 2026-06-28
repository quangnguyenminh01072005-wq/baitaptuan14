#include <iostream>
using namespace std;
struct Node {
    char data;
    Node* left;
    Node* right;
};
Node* taoNode(char x) {
    Node* p = new Node;
    p->data = x;
    p->left = NULL;
    p->right = NULL;
    return p;
}
Node* cayDayDu() {
    Node* A = taoNode('A');
    Node* B = taoNode('B');
    Node* C = taoNode('C');
    Node* D = taoNode('D');
    Node* E = taoNode('E');
    Node* F = taoNode('F');
    Node* G = taoNode('G');
    A->left = B;
    A->right = C;
    B->left = D;
    B->right = E;
    C->left = F;
    C->right = G;
    return A;
} 
Node* cayLechTrai() {
    Node* A = taoNode('A');
    Node* B = taoNode('B');
    Node* C = taoNode('C');
    Node* D = taoNode('D');
    A->left = B;
    B->left = C;
    C->left = D;
    return A;
}
Node* cayLechPhai() {
    Node* A = taoNode('A');
    Node* B = taoNode('B');
    Node* C = taoNode('C');
    Node* D = taoNode('D');
    A->right = B;
    B->right = C;
    C->right = D;
    return A;
}
Node* cayZigZag() {
    Node* A = taoNode('A');
    Node* B = taoNode('B');
    Node* C = taoNode('C');
    Node* D = taoNode('D');
    A->left = B;
    B->right = C;
    C->left = D;
    return A;
}
Node* cayBieuThuc() {
    Node* chia = taoNode('/');
    Node* cong = taoNode('+');
    Node* d = taoNode('d');

    Node* nhan = taoNode('*');
    Node* c = taoNode('c');

    Node* a = taoNode('a');
    Node* b = taoNode('b');

    chia->left = cong;
    chia->right = d;

    cong->left = nhan;
    cong->right = c;

    nhan->left = a;
    nhan->right = b;

    return chia;
}
void duyetTruoc(Node* root) {
    if(root != NULL) {
        cout << root->data << " ";
        duyetTruoc(root->left);
        duyetTruoc(root->right);
    }
}
void duyetGiua(Node* root) {
    if(root != NULL) {
        duyetGiua(root->left);
        cout << root->data << " ";
        duyetGiua(root->right);
    }
}
void duyetSau(Node* root) {
    if(root != NULL) {
        duyetSau(root->left);
        duyetSau(root->right);
        cout << root->data << " ";
    }
}
void truoc(Node* root) {
    if(root != NULL) {
        cout << root->data;
        truoc(root->left);
        truoc(root->right);
    }
}

int main()
{
    return 0;
}
