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
// Thêm nút vào BST
Node* insert(Node* root, int x) {
    if (root == NULL)
        return createNode(x);
    if (x < root->data)
        root->left = insert(root->left, x);
    else if (x > root->data)
        root->right = insert(root->right, x);
    return root;
}

int main()
{
    return 0;
}
