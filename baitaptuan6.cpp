#include <iostream>
#include <string>
using namespace std;
struct File {
    string name;
    int size;
    long time;
};
struct Node {
    File data;
    Node* next;
};
struct LinkedList {
    Node* head;
};
void init(LinkedList &list) {
    list.head = NULL;
}
void insertFile(LinkedList &list, File f) {
    Node* newNode = new Node{f, NULL};
    if (list.head == NULL || f.time < list.head->data.time) {
        newNode->next = list.head;
        list.head = newNode;
        return;
    }
    Node* cur = list.head;
    while (cur->next != NULL && cur->next->data.time < f.time) {
        cur = cur->next;
    }
    newNode->next = cur->next;
    cur->next = newNode;
}
int totalSize(LinkedList list) {
    int sum = 0;
    Node* cur = list.head;
    while (cur != NULL) {
        sum += cur->data.size;
        cur = cur->next;
    }
    return sum;
}
// tìm file nhỏ nhất
Node* findMin(LinkedList list) {
    Node* minNode = list.head;
    Node* cur = list.head;
    while (cur != NULL) {
        if (cur->data.size < minNode->data.size) {
            minNode = cur;
        }
        cur = cur->next;
    }
    return minNode;
}
