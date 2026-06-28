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

int main()
{
    return 0;
}
