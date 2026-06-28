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

int main()
{
    return 0;
}
