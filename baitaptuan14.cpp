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

int main()
{
    return 0;
}
