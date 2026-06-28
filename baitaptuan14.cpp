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

int main()
{
    return 0;
}
