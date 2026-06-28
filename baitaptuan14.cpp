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

// B2: Thêm nút vào AVL
Node* insert(Node *root, int key) {
    if (root == NULL)
        return createNode(key);
    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);
    else
        return root;
    root->height = 1 + maxx(height(root->left),
                            height(root->right));
    int balance = getBalance(root);

    // LL
    if (balance > 1 && key < root->left->key)
        return rightRotate(root);

    // RR
    if (balance < -1 && key > root->right->key)
        return leftRotate(root);

    // LR
    if (balance > 1 && key > root->left->key) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // RL
    if (balance < -1 && key < root->right->key) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}

// Duyệt NLR
void preorder(Node *root) {
    if (root != NULL) {
        cout << root->key << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

int main()
{
    return 0;
}
