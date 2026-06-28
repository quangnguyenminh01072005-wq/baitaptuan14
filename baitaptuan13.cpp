#include <iostream>
using namespace std;
// Cấu trúc nút
struct Node {
    int data;
    Node *left;
    Node *right;
};
// Tạo nút mới
Node* createNode(int x) {
    Node* p = new Node;
    p->data = x;
    p->left = NULL;
    p->right = NULL;
    return p;
}

int main()
{
    return 0;
}
