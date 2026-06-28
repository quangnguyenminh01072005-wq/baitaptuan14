#include <iostream>
using namespace std;

struct Node {
    int key;
    Node *left;
    Node *right;
    int height;
};

// Lấy chiều cao nút
int height(Node *p) {
    if (p == NULL)
        return 0;
    return p->height;
}

// Hàm max
int maxx(int a, int b) {
    return (a > b) ? a : b;
}

// Tạo nút mới
Node* createNode(int x) {
    Node *p = new Node;
    p->key = x;
    p->left = NULL;
    p->right = NULL;
    p->height = 1;
    return p;
}

// Quay phải
Node* rightRotate(Node *y) {
    Node *x = y->left;
    Node *T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = maxx(height(y->left), height(y->right)) + 1;
    x->height = maxx(height(x->left), height(x->right)) + 1;
    return x;
}

// Quay trái
Node* leftRotate(Node *x) {
    Node *y = x->right;
    Node *T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = maxx(height(x->left), height(x->right)) + 1;
    y->height = maxx(height(y->left), height(y->right)) + 1;
    return y;
}

// Hệ số cân bằng
int getBalance(Node *p) {
    if (p == NULL)
        return 0;
    return height(p->left) - height(p->right);
}

int main()
{
    return 0;
}
